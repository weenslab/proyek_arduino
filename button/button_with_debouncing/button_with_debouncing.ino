#include <Wire.h>
#include <Adafruit_SSD1306.h>

// Pin I2C
#define I2C_SDA 33
#define I2C_SCL 32

// Pin button
#define BTNPIN 22

// Address I2C OLED
#define OLED_ADDR 0x3C

// Deklarasi object untuk OLED display
Adafruit_SSD1306 oled(128, 64, &Wire, -1);

// Counter
int counter = 0;

// Button debouncing
int button_state = HIGH;
int last_button_state = HIGH;
unsigned long last_debounce_time = 0;
unsigned long debounce_delay = 50;

void setup()
{
  // Setup serial communication
  Serial.begin(115200);

  // Inisialisasi pin I2C
  Wire.begin(I2C_SDA, I2C_SCL, 400000);
  
  // Inisialisasi OLED
  oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  oled.clearDisplay();
  oled.setTextColor(WHITE);
  oled.setTextSize(3);
  print_center(String(counter), 0, 20);
  oled.display();

  // Konfigurasi GPIO pin sebagai input pull-up untuk button
  pinMode(BTNPIN, INPUT_PULLUP);
}

void loop()
{
  // Membaca state button kemudian disimpan pada variable
  int reading = digitalRead(BTNPIN);

  // Jika nilai button berubah, karena noise atau penekanan
  if (reading != last_button_state)
  {
    // Simpan nilai milis terbaru (reset timer debouncing)
    last_debounce_time = millis();
  }

  // Jika sudah melebihi waktu untuk menunggu debouncing
  if ((millis() - last_debounce_time) > debounce_delay)
  {
    // Jika state button berubah
    if (reading != button_state)
    {
      button_state = reading;

      if (button_state == LOW)
      {
        // Naikkan nilai counter
        counter++;

        oled.clearDisplay();
        oled.setTextColor(WHITE);
        oled.setTextSize(3);
        print_center(String(counter), 0, 20);
        oled.display();
      }
    }
  }

  // Update variable reading untuk iterasi loop berikutnya
  last_button_state = reading;
}

// Fungsi untuk print text ke OLED dengan alignment center
void print_center(const String str, int x, int y)
{
  int16_t x1, y1;
  uint16_t w, h;
  oled.getTextBounds(str, x, y, &x1, &y1, &w, &h);
  oled.setCursor((x-w/2)+(128/2), y);
  oled.print(str);
}
