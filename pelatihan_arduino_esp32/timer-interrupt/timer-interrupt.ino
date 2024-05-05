#include <Ticker.h>

// LED pin
#define RED_LED_PIN     25
#define GREEN_LED_PIN   26

Ticker timerRedLed;
Ticker timerGreenLed;

void timerRedLed_isr()
{
  // Invert nilai LED
  digitalWrite(RED_LED_PIN, !digitalRead(RED_LED_PIN));
}

void timerGreenLed_isr()
{
  // Invert nilai LED
  digitalWrite(GREEN_LED_PIN, !digitalRead(GREEN_LED_PIN));
}

void setup()
{
  // Konfigurasi GPIO pin sebagai output untuk LED
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  
  // Set nilai LED ke kondisi off
  digitalWrite(RED_LED_PIN, HIGH);
  digitalWrite(GREEN_LED_PIN, HIGH);
  
  // Set ticker untuk generate interrupt setiap 200 ms
  timerRedLed.attach_ms(200, timerRedLed_isr);
  // Set ticker untuk generate interrupt setiap 2000 ms
  timerGreenLed.attach_ms(2000, timerGreenLed_isr);
}

void loop()
{
}
