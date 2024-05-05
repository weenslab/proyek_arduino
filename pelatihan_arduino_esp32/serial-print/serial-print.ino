void setup()
{
  // Konfigurasi komunikasi serial
  Serial.begin(9600);

  // Print tanpa newline
  Serial.print("Hello, ");
  Serial.print("World!");
  
  // Print dengan newline
  Serial.println();
  Serial.println("Hello, ");
  Serial.println("World!");

  // Print beberapa tipe data
  Serial.println(168); // Print angka integer
  Serial.println(3.14); // Print angka float
  Serial.println('e'); // Print karakter
  Serial.println("Arduino"); // Print string

  // Print angka dalam beberapa radix
  Serial.println(10, BIN); // Print angka dalan biner
  Serial.println(10, OCT); // Print angka dalan octal
  Serial.println(10, DEC); // Print angka dalan desimal
  Serial.println(10, HEX); // Print angka dalan hexadesimal

  // Menghitung luas lingkaran
  int jariJari = 10;
  float luasLingkaran = 3.14 * 10 * 10;
  Serial.print("Luas lingkaran: ");
  Serial.println(luasLingkaran);
}

void loop()
{
}
