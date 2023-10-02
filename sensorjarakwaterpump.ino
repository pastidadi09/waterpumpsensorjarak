// Menggunakan pin trig dan echo sensor ultrasonik
const int trigPin = 9;
const int echoPin = 10;

// Pin relay
const int relayPin = 8;

// Variabel untuk menyimpan jarak yang terukur
long distance;

// Variabel untuk menyimpan waktu pengukuran
long duration;

void setup() {
  // Mengatur pin trig sebagai OUTPUT dan echo sebagai INPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Mengatur pin relay sebagai OUTPUT
  pinMode(relayPin, OUTPUT);

  // Memulai Serial Monitor dengan baud rate 9600
  Serial.begin(9600);
}

void loop() {
  // Mengirimkan sinyal ultrasonik
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Menerima waktu yang diperlukan untuk mengirim dan menerima sinyal ultrasonik
  duration = pulseIn(echoPin, HIGH);

  // Menghitung jarak dalam cm
  distance = duration * 0.034 / 2;

  // Menampilkan jarak pada Serial Monitor
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Memeriksa jika jarak kurang dari 5 cm, maka mengaktifkan relay
  if (distance < 5) {
    digitalWrite(relayPin, LOW); // Mengaktifkan relay
  } else {
    digitalWrite(relayPin, HIGH); // Mematikan relay jika jarak lebih dari atau sama dengan 5 cm
  }

  // Menunggu sejenak sebelum mengukur lagi
  delay(1000);
}
