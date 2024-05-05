#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <RtcDS1307.h>
#include <Adafruit_SSD1306.h>
#include <Ticker.h>

// Pengecekan setting ukuran OLED pada library
#if (SSD1306_LCDHEIGHT != 64) // 128x64 pixel
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

// Pin untuk MFRC522
#define RST_PIN 22
#define SS_PIN  21

// Pin I2C
#define I2C_SDA 33
#define I2C_SCL 32

// LED pin
#define RED_LED_PIN     25
#define GREEN_LED_PIN   26
#define BLUE_LED_PIN    2

// Button pin
#define BTNPIN          12

// Address I2C OLED
#define OLED_ADDR 0x3C

// Deklarasi object untuk MFRC522
MFRC522 mfrc522(SS_PIN, RST_PIN);

// Deklarasi object untuk RTC
RtcDS1307<TwoWire> rtc(Wire);

// Deklarasi object untuk OLED display
Adafruit_SSD1306 oled;

// Timer untuk ADC
Ticker timer;

// ISR untuk button
void IRAM_ATTR button_isr()
{ 
  if (digitalRead(BTNPIN) == LOW) // Jika button ditekan
  {
    // Nyalakan LED
    digitalWrite(BLUE_LED_PIN, HIGH);
  }
  else
  {
    // Matikan LED
    digitalWrite(BLUE_LED_PIN, LOW);
  }
}

// ISR untuk timer
void timer_isr()
{
  // Membaca nilai sensor cahaya dan mengirim ke serial monitor
  Serial.println(analogRead(27));
}

void setup()
{
  // Konfigurasi komunikasi serial
  Serial.begin(9600);
  
  // Inisialisasi SPI
  SPI.begin();
  
  // Inisialisasi MFRC522
  mfrc522.PCD_Init();

  // Inisialisasi pin I2C
  Wire.begin(I2C_SDA, I2C_SCL, 400000);
  
  // Inisialisasi RTC
  rtc.Begin();  
  // Men-set waktu RTC ke waktu saat kode di-compile
  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
  rtc.SetDateTime(compiled);
  rtc.SetIsRunning(true);

  // Inisialisasi OLED
  oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  // Membersihkan memory OLED
  oled.clearDisplay();
  
  // Konfigurasi GPIO pin sebagai output untuk LED
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);

  // Set nilai LED ke kondisi off
  digitalWrite(RED_LED_PIN, HIGH);
  digitalWrite(GREEN_LED_PIN, HIGH);
  digitalWrite(BLUE_LED_PIN, LOW);

  // Konfigurasi GPIO pin sebagai input pull-up untuk button
  pinMode(BTNPIN, INPUT_PULLUP);

  // Hubungkan interrupt handler (ISR) dengan button
  attachInterrupt(digitalPinToInterrupt(BTNPIN), button_isr, CHANGE);

  // Set ticker untuk generate interrupt setiap 3000 ms
  timer.attach_ms(3000, timer_isr);
}

void loop()
{
  // Read RTC date and time
  RtcDateTime now = rtc.GetDateTime();
    
  // Menampilkan waktu RTC pada OLED
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(WHITE);
  oled.setCursor(4, 12);
  oled.printf("%04d/%02d/%02d",
      now.Year(), now.Month(), now.Day());
  oled.setCursor(16, 38);
  oled.printf("%02d:%02d:%02d",
      now.Hour(), now.Minute(), now.Second());
  oled.display();
  
  // Reset loop jika tidak ada kartu RFID baru yang terdeteksi
  // Hal ini dilakukan agar proses di dalam loop ini tidak berjalan terus menerus
  if (!mfrc522.PICC_IsNewCardPresent())
    return;

  // Melakukan pembacaan kartu RFID
  if (!mfrc522.PICC_ReadCardSerial())
    return;

  // Membaca UID dari kartu RFID
  unsigned long uid = 0;
  uid |= mfrc522.uid.uidByte[0] << 24;
  uid |= mfrc522.uid.uidByte[1] << 16;
  uid |= mfrc522.uid.uidByte[2] << 8;
  uid |= mfrc522.uid.uidByte[3];
  // Stop pembacaan kartu RFID
  mfrc522.PICC_HaltA();

  // Pengecekan UID
  if (uid == 0xD265ADBB)
  {
    // Jika UID benar, maka kedipkan green LED
    for (int i = 0; i < 3; i++)
    {
      digitalWrite(GREEN_LED_PIN, LOW);
      delay(100);
      digitalWrite(GREEN_LED_PIN, HIGH);
      delay(100);
    }
  }
  else
  {
    // Jika UID salah, maka kedipkan red LED
    for (int i = 0; i < 3; i++)
    {
      digitalWrite(RED_LED_PIN, LOW);
      delay(100);
      digitalWrite(RED_LED_PIN, HIGH);
      delay(100);
    }
  }
}
