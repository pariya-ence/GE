// กำหนดพิน GPIO
const int LED1_PIN = 2;
const int LED2_PIN = 4;
const int LED3_PIN = 5;
void setup() {
  // ตั้งค่าให้พิน GPIO ทั้งหมดเป็น OUTPUT
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
}
void loop() {
  // สถานะที่ 1: ติดเฉพาะ LED 1
  digitalWrite(LED1_PIN, HIGH);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);
  delay(1000);
  // สถานะที่ 2: ติดเฉพาะ LED 2
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, HIGH);
  digitalWrite(LED3_PIN, LOW);
  delay(1000);
  // สถานะที่ 3: ติดเฉพาะ LED 3
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, HIGH);
  delay(1000);
}
