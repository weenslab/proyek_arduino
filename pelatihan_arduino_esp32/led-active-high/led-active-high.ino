// LED pin
const int ledPin = 4;

void setup()
{
  // Konfigurasi GPIO pin sebagai output untuk LED
  pinMode(ledPin, OUTPUT);
  // Nyalakan LED active-high
  digitalWrite(ledPin, HIGH);
}

void loop()
{
}
