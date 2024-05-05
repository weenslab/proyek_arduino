// LED pin
#define LEDPIN  2
// Button pin
#define BTNPIN  4

void setup()
{
  // Konfigurasi GPIO pin sebagai output untuk LED on-board
  pinMode(LEDPIN, OUTPUT);
  // Konfigurasi GPIO pin sebagai input untuk button
  pinMode(BTNPIN, INPUT);
}

void loop()
{
  if (digitalRead(BTNPIN) == HIGH) // Jika button ditekan (active-high)
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
