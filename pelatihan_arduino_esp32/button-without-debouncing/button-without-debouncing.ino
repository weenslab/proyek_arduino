// LED pin
#define RED_LED_PIN     25
// Button pin
#define BTNPIN          12

int btn_state;
int led_state = HIGH;

void setup()
{
  // Konfigurasi GPIO pin sebagai output untuk LED
  pinMode(RED_LED_PIN, OUTPUT);
  
  // Set nilai LED ke kondisi off
  digitalWrite(RED_LED_PIN, HIGH);
  
  // Konfigurasi GPIO pin sebagai input pull-up untuk button
  pinMode(BTNPIN, INPUT_PULLUP);
}

void loop()
{
  // Read button
  btn_state = digitalRead(BTNPIN);

  // Toggle LED state
  if (btn_state == LOW)
  {
    led_state = !led_state;
  }
  
  // Write LED state
  digitalWrite(RED_LED_PIN, led_state);
}
