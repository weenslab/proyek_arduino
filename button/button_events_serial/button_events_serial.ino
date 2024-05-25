#include "OneButton.h"

// Button on pin 23, active-low
OneButton button(23, true);

void setup()
{
  Serial.begin(9600);
  button.attachClick(buttonClick);
  button.attachDoubleClick(buttonDoubleClick);
  button.attachMultiClick(buttonMultiClick);
  button.attachLongPressStop(buttonLongPress);
}

void loop()
{
  button.tick();
  delay(10);
}

void buttonClick()
{
  Serial.println("Button click.");
}

void buttonDoubleClick()
{
  Serial.println("Button double click.");
}

void buttonMultiClick()
{
  Serial.println("Button multi click.");
}

void buttonLongPress()
{
  Serial.println("Button long press.");
}
