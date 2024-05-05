#include <Wire.h>
#include <RtcDS1307.h>

// Pin I2C
#define I2C_SDA 33
#define I2C_SCL 32

// Deklarasi object untuk RTC
RtcDS1307<TwoWire> rtc(Wire);

void setup()
{
  // Inisialisasi serial
  Serial.begin(9600);
  
  // Inisialisasi pin I2C
  Wire.begin(I2C_SDA, I2C_SCL, 400000);
  
  // Inisialisasi RTC
  rtc.Begin();  
  // Men-set waktu RTC ke waktu saat kode di-compile
  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
  rtc.SetDateTime(compiled);
  rtc.SetIsRunning(true);
}

void loop()
{
  // Membaca waktu RTC (date and time)
  RtcDateTime now = rtc.GetDateTime();
  
  // Print waktu RTC ke serial monitor 
  Serial.printf("%04d/%02d/%02d %02d:%02d:%02d\n",
      now.Year(), now.Month(), now.Day(),
      now.Hour(), now.Minute(), now.Second());
  delay(1000);
}
