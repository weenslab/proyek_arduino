// LED pin
#define RED_LED_PIN     25

void setup()
{
  // Konfigurasi komunikasi serial
  Serial.begin(9600);

  // Konfigurasi GPIO pin sebagai output untuk LED
  pinMode(RED_LED_PIN, OUTPUT);
  
  // Set nilai LED ke kondisi off
  digitalWrite(RED_LED_PIN, HIGH);
}

void loop()
{
  // Jika ada data di receive buffer
  if (Serial.available() > 0)
  {
    // Baca perintah dari receive buffer sampai karakter newline
    String cmd = Serial.readStringUntil('\n');

    // Proses perintah tersebut
    if (cmd == "LED_ON")
    {
      digitalWrite(RED_LED_PIN, LOW);
    }
    else if (cmd == "LED_OFF")
    {
      digitalWrite(RED_LED_PIN, HIGH);      
    }
    else if (cmd == "LED")
    {
      Serial.printf("LED is %s\n", ((digitalRead(RED_LED_PIN) == HIGH) ? "OFF" : "ON"));
    }
  }
}
