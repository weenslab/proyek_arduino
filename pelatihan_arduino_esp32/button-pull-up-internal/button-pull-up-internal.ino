// LED pin
#define LEDPIN  2
// Button pin
#define BTNPIN  4

void setup()
{
  // Konfigurasi GPIO pin sebagai output untuk LED on-board
  pinMode(LEDPIN, OUTPUT);
  // Konfigurasi GPIO pin sebagai input pull-up untuk button
  pinMode(BTNPIN, INPUT_PULLUP);
}

void loop()
{
  if (digitalRead(BTNPIN) == LOW) // Jika button ditekan
  {
    // Nyalakan LED on-board
    digitalWrite(LEDPIN, HIGH);
  }
  else
  {
    // Matikan LED on-board
    digitalWrite(LEDPIN, LOW);
  }
}
