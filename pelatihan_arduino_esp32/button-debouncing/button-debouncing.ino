// LED pin
#define RED_LED_PIN     25
// Button pin
#define BTNPIN          12

int led_state = LOW;
int button_state = HIGH;
int last_button_state = HIGH;

unsigned long last_debounce_time = 0;
unsigned long debounce_delay = 50;

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
  // Membaca state button kemudian disimpan pada variable
  int reading = digitalRead(BTNPIN);

  // Jika nilai button berubah, karena noise atau penekanan
  if (reading != last_button_state)
  {
    // Simpan nilai milis
    last_debounce_time = millis();
  }

  // Jika sudah melebihi waktu untuk menunggu debouncing
  if ((millis() - last_debounce_time) > debounce_delay)
  {
    // Jika state button berubah
    if (reading != button_state)
    {
      button_state = reading;

      // Toggle LED hanya jika state button-nya LOW (active-low circuit)
      if (button_state == LOW)
      {
        led_state = !led_state;
      }
    }
  }

  // Set nilai LED state ke GPIO
  digitalWrite(RED_LED_PIN, led_state);

  // Update variable reading untuk iterasi loop berikutnya
  last_button_state = reading;
}
