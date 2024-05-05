#include <SPI.h>
#include <MFRC522.h>

// Pin untuk MFRC522
#define RST_PIN 22
#define SS_PIN  21

// LED pin
#define RED_LED_PIN     25
#define GREEN_LED_PIN   26

// Deklarasi object untuk MFRC522
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup()
{
  // Inisialisasi SPI
  SPI.begin();
  // Inisialisasi MFRC522
  mfrc522.PCD_Init();
  
  // Konfigurasi GPIO pin sebagai output untuk LED
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  // Set nilai LED ke kondisi off
  digitalWrite(RED_LED_PIN, HIGH);
  digitalWrite(GREEN_LED_PIN, HIGH);
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

  // Pengecekan UID
  if (uid == 0xD265ADBB)
  {
    // Jika UID benar, maka kedipkan green LED
    for (int i = 0; i < 3; i++)
    {
      digitalWrite(GREEN_LED_PIN, LOW);
      delay(100);
      digitalWrite(GREEN_LED_PIN, HIGH);
      delay(100);
    }
  }
  else
  {
    // Jika UID salah, maka kedipkan red LED
    for (int i = 0; i < 3; i++)
    {
      digitalWrite(RED_LED_PIN, LOW);
      delay(100);
      digitalWrite(RED_LED_PIN, HIGH);
      delay(100);
    }
  }
}
