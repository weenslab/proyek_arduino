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

  // Menulis text ke memory OLED
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(27, 30);
  oled.print("Hello, world!");

  // Menampilkan isi memory OLED ke display OLED
  oled.display();
}

void loop()
{
}
