#include <Wire.h>
#include <RtcDS1307.h>
#include <Adafruit_SSD1306.h>

// Pengecekan setting ukuran OLED pada library
#if (SSD1306_LCDHEIGHT != 64) // 128x64 pixel
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

// Pin I2C
#define I2C_SDA 33
#define I2C_SCL 32

// Address I2C OLED
#define OLED_ADDR 0x3C

// Deklarasi object untuk RTC
RtcDS1307<TwoWire> rtc(Wire);

// Deklarasi object untuk OLED display
Adafruit_SSD1306 oled;

void setup()
{
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
  delay(1000);
}
