#define RED_LED_PIN     32
#define GREEN_LED_PIN   26
#define BTNPIN          23

void IRAM_ATTR button_isr()
{
  if (digitalRead(BTNPIN) == LOW)
    digitalWrite(RED_LED_PIN, HIGH);
  else
    digitalWrite(RED_LED_PIN, LOW);
}

void setup()
{
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BTNPIN, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(BTNPIN), button_isr, CHANGE);
}

void loop()
{
  digitalWrite(GREEN_LED_PIN, LOW);
  delay(2000);
  digitalWrite(GREEN_LED_PIN, HIGH);
  delay(2000);
}
