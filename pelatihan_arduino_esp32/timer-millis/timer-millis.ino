// LED pin
#define RED_LED_PIN     25
#define GREEN_LED_PIN   26

unsigned long previousMillisRedLed = 0;
unsigned long previousMillisGreenLed = 0;

void setup()
{
  // Konfigurasi GPIO pin sebagai output untuk LED
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  
  // Set nilai LED ke kondisi off
  digitalWrite(RED_LED_PIN, HIGH);
  digitalWrite(GREEN_LED_PIN, HIGH);
}

void loop()
{
  // Membaca nilai timer milliseconds
  unsigned long currentMillis = millis();

  // Jika waktu timer untuk red LED sudah berlalu selama 200 ms 
  if ((currentMillis-previousMillisRedLed) >= 200)
  {
    // Simpan nilai millis saat ini untuk referensi pada loop berikutnya
    previousMillisRedLed = currentMillis;
    // Invert nilai LED
    digitalWrite(RED_LED_PIN, !digitalRead(RED_LED_PIN));
  }

  // Jika waktu timer untuk green LED sudah berlalu selama 2000 ms 
  if ((currentMillis-previousMillisGreenLed) >= 2000)
  {
    // Simpan nilai millis saat ini untuk referensi pada loop berikutnya
    previousMillisGreenLed = currentMillis;
    // Invert nilai LED
    digitalWrite(GREEN_LED_PIN, !digitalRead(GREEN_LED_PIN));
  }
}
