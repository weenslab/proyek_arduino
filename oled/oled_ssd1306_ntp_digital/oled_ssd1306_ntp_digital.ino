#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include "time.h"

// Pin I2C
#define I2C_SDA 33
#define I2C_SCL 32

// Address I2C OLED
#define OLED_ADDR 0x3C

// Deklarasi object untuk OLED display
Adafruit_SSD1306 oled(128, 64, &Wire, -1);

// SSID dan password Wi-Fi AP
const char ssid[] = "<your_wifi_name>";
const char pass[] = "<your_wifi_password>";

// NTP settings
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 7L * 60L * 60L;
const int daylightOffset_sec = 0;

void setup()
{
  // Setup serial communication
  Serial.begin(115200);

  // Inisialisasi pin I2C
  Wire.begin(I2C_SDA, I2C_SCL, 400000);
  
  // Inisialisasi OLED
  oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  oled.clearDisplay();

  // Connect to a WiFi access point
  Serial.printf("Connecting to %s ...\n", ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  if (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    Serial.printf("WiFi connect failed! Rebooting...\n");
    delay(1000);
    ESP.restart();
  }
  Serial.printf("Connected\n");
  Serial.printf("IP address: %s\n", WiFi.localIP().toString().c_str());

  // Init NTP and get the time
  Serial.printf("Configuring NTP...\n");
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();

  // Disconnect WiFi
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
  Serial.printf("Disconnected\n");
}

void loop()
{
  delay(1000);
  printLocalTime();
}

// Fungsi untuk baca NTP dan print ke OLED
void printLocalTime()
{
  struct tm timeinfo;
  char timeHour[3];
  char timeMinute[3];
  char timeSecond[3];
  char timeYear[5];
  char timeMonth[10];
  char timeDate[3];
  char timeDay[10];

  if (!getLocalTime(&timeinfo))
  {
    Serial.println("Failed to obtain time");
    return;
  }

  // Get variable
  strftime(timeHour, 3, "%H", &timeinfo);
  strftime(timeMinute, 3, "%M", &timeinfo);
  strftime(timeSecond, 3, "%S", &timeinfo);
  strftime(timeYear, 5, "%Y", &timeinfo);
  strftime(timeMonth, 10, "%B", &timeinfo);
  strftime(timeDate, 3, "%d", &timeinfo);
  strftime(timeDay, 10, "%A", &timeinfo);

  // Format text
  String txt0 = String(timeDay);
  String txt1 = String(timeHour) + ":" + String(timeMinute) + ":" + String(timeSecond);
  String txt2 = String(timeDate) + " " + String(timeMonth) + " " + String(timeYear);

  oled.clearDisplay();
  oled.setTextColor(WHITE);
  oled.setTextSize(1);
  print_center(txt0, 0, 0);
  oled.setTextSize(2);
  print_center(txt1, 0, 20);
  oled.setTextSize(1);
  print_center(txt2, 0, 50);
  oled.display();
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
