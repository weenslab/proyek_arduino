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

// Button
int btn_state;

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
  btn_state = digitalRead(BTNPIN);

  if (btn_state == LOW)
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

// Fungsi untuk print text ke OLED dengan alignment center
void print_center(const String str, int x, int y)
{
  int16_t x1, y1;
  uint16_t w, h;
  oled.getTextBounds(str, x, y, &x1, &y1, &w, &h);
  oled.setCursor((x-w/2)+(128/2), y);
  oled.print(str);
}
