// LED pin
#define RED_LED_PIN     25
#define GREEN_LED_PIN   26
// Button pin
#define BTNPIN          12

void setup()
{
  // Konfigurasi GPIO pin sebagai output untuk LED
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  
  // Set nilai LED ke kondisi off
  digitalWrite(RED_LED_PIN, HIGH);
  digitalWrite(GREEN_LED_PIN, HIGH);
  
  // Konfigurasi GPIO pin sebagai input pull-up untuk button
  pinMode(BTNPIN, INPUT_PULLUP);
}

void loop()
{
  // Red LED berkedip setiap 2 detik
  digitalWrite(RED_LED_PIN, LOW);
  delay(2000);
  digitalWrite(RED_LED_PIN, HIGH);
  delay(2000);

  if (digitalRead(BTNPIN) == LOW) // Jika button ditekan
  {
    // Nyalakan LED
    digitalWrite(GREEN_LED_PIN, LOW);
  }
  else
  {
    // Matikan LED
    digitalWrite(GREEN_LED_PIN, HIGH);
  }
}
