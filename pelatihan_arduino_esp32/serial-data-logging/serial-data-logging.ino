int data_random = 0;

void setup()
{
  // Konfigurasi komunikasi serial
  Serial.begin(9600);
}

void loop()
{
  // Print data ke serial monitor PC setiap 0.5 detik
  data_random = random(256); // Angka random 0-255
  Serial.println(data_random);
  delay(500);
}
