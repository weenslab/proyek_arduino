#include <Wire.h>
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

// Deklarasi object untuk OLED display
Adafruit_SSD1306 oled;

void setup()
{
  // Inisialisasi pin I2C
  Wire.begin(I2C_SDA, I2C_SCL, 400000);
  
  // Inisialisasi OLED
  oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  // Membersihkan memory OLED
  oled.clearDisplay();
}

void loop()
{
  // Membaca nilai LDR
  int light_sensor = analogRead(27); // Nilai sensor LDR

  // Menampilkan nilai sensor cahaya pada OLED
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(WHITE);
  oled.setCursor(45, 25);
  oled.print(light_sensor);
  oled.display();

  delay(500);
}
