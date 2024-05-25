#include "OneButton.h"

typedef enum {
  ACTION_OFF,
  ACTION_ON,
  ACTION_SLOW,
  ACTION_FAST
} MyActions;

OneButton button(23, true);
MyActions nextAction = ACTION_OFF;

void setup()
{
  Serial.begin(9600);

  pinMode(2, OUTPUT);

  button.attachClick(buttonClick);
  button.attachDoubleClick(buttonDoubleClick);
  button.attachLongPressStart(buttonLongPress);
}

void loop()
{
  unsigned long now = millis();

  button.tick();

  if (nextAction == ACTION_OFF)
    digitalWrite(2, LOW);
  else if (nextAction == ACTION_ON)
    digitalWrite(2, HIGH);
  else if (nextAction == ACTION_SLOW)
    digitalWrite(2, (now % 1000 < 500) ? LOW : HIGH);
  else if (nextAction == ACTION_FAST)
    digitalWrite(2, (now % 200 < 100) ? LOW : HIGH);
}

void buttonClick()
{
  Serial.println("Button click.");

  if (nextAction == ACTION_OFF)
    nextAction = ACTION_ON;
  else
    nextAction = ACTION_OFF;
}

void buttonDoubleClick()
{
  Serial.println("Button double click.");

  if (nextAction == ACTION_ON)
    nextAction = ACTION_SLOW;
  else if (nextAction == ACTION_SLOW)
    nextAction = ACTION_FAST;
  else if (nextAction == ACTION_FAST)
    nextAction = ACTION_ON;
}

void buttonLongPress()
{
  Serial.println("Button long press.");
  
  nextAction = ACTION_OFF;
}
