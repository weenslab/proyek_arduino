void setup()
{
  // Konfigurasi komunikasi serial
  Serial.begin(9600);
}

void loop()
{
  // Jika ada data pada yang berasal dari input serial monitor PC
  if (Serial.available() > 0)
  {
    // Membaca data tersebut kemudian disimpan sebagai string
    String input = Serial.readString();
    // Print data string tersebut kembali ke output serial monitor PC
    Serial.print(input);
  }
}
