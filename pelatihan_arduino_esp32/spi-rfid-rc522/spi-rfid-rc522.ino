#include <SPI.h>
#include <MFRC522.h>

// Pin untuk MFRC522
#define RST_PIN 22
#define SS_PIN  21

// Deklarasi object untuk MFRC522
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup()
{
  // Inisialisasi serial
  Serial.begin(9600);
  // Inisialisasi SPI
  SPI.begin();
  // Inisialisasi MFRC522
  mfrc522.PCD_Init();
}

void loop()
{
  // Reset loop jika tidak ada kartu RFID baru yang terdeteksi
  // Hal ini dilakukan agar proses di dalam loop ini tidak berjalan terus menerus
  if (!mfrc522.PICC_IsNewCardPresent())
    return;

  // Melakukan pembacaan kartu RFID
  if (!mfrc522.PICC_ReadCardSerial())
    return;

  // Membaca UID dari kartu RFID
  unsigned long uid = 0;
  uid |= mfrc522.uid.uidByte[0] << 24;
  uid |= mfrc522.uid.uidByte[1] << 16;
  uid |= mfrc522.uid.uidByte[2] << 8;
  uid |= mfrc522.uid.uidByte[3];
  // Stop pembacaan kartu RFID
  mfrc522.PICC_HaltA();

  // Print UID ke serial monitor
  Serial.print("Card detected, UID: ");
  Serial.println(uid, HEX);
}
