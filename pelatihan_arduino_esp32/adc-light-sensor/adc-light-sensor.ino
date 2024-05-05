int light_sensor = 0;

void setup()
{
  // Konfigurasi komunikasi serial
  Serial.begin(9600);
}

void loop()
{
  // Print nilai LDR ke serial monitor setiap 0.5 detik
  light_sensor = analogRead(27); // Nilai sensor LDR
  Serial.println(light_sensor);
  delay(500);
}
