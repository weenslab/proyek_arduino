void setup()
{
  pinMode(32, OUTPUT);
}

void loop() 
{
  analogWrite(32, random(120)+135);
  delay(random(100));
}
