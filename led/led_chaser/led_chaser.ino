uint8_t pin[8] = {0, 4, 16, 17, 3, 1, 22, 23};

void setup()
{
  for (int i = 0; i <= 7; i++)
    pinMode(pin[i], OUTPUT);
}

void loop() 
{
  for (int i = 7; i >= 0; i--)
  {
    digitalWrite(pin[i], HIGH);
    delay(20);
  }
  delay(250);
  for (int i = 7; i >= 0; i--)
    digitalWrite(pin[i], LOW);
  delay(400);
}
