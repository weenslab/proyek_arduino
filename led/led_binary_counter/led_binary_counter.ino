// uint8_t pin[8] = {23, 22, 1, 3, 17, 16, 4, 0}; // Right MSB
uint8_t pin[8] = {0, 4, 16, 17, 3, 1, 22, 23}; // Left MSB

void setup()
{
  for (int i = 0; i <= 7; i++)
    pinMode(pin[i], OUTPUT);
}

void loop() 
{
  for (byte i = 0; i <= 255; i++)
  {
    displayBinary(i);
    delay(100);
  }
}

void displayBinary(byte numToShow)
{
  for (int i = 0; i <= 7; i++)
  {
    if (bitRead(numToShow, i) == 1)
      digitalWrite(pin[i], HIGH);
    else
      digitalWrite(pin[i], LOW);
  }
}
