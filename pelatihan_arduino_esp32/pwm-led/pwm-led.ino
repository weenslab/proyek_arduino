// LED pin
#define LEDPIN  25

// Parameter untuk PWM
const int channel = 0;
const int freq = 1000;
const int res = 10;

void setup()
{
  // Inisialisasi PWM
  ledcSetup(channel, freq, res);
  
  // Hubungkan channel PWM ke LED
  ledcAttachPin(LEDPIN, channel);
}

void loop()
{
  // Decrease brightness LED (active-low LED)
  for (int i = 0; i <= 1023; i += 20)
  {
    ledcWrite(channel, i);
    delay(25);
  }
  
  // Increase brightness LED (active-low LED)
  for (int i = 1023; i >= 0; i -= 20)
  {
    ledcWrite(channel, i);
    delay(25);
  }
}
