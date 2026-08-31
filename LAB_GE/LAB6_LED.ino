const int TRIG_PIN = 18;
const int ECHO_PIN = 19;
const int RED_LED = 25;
const int BLUE_LED = 26;
long duration;
float distance;
void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  digitalWrite(RED_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
}
void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);  // อ่านเวลาที่ Echo กลับมา
  distance = duration * 0.0343 / 2.0;  // คำนวณระยะทาง (เซนติเมตร)
  Serial.print("Distance : ");  // แสดงผลบน Serial Monitor
  Serial.print(distance);
  Serial.println(" cm");
  if (distance < 10.0) {
    digitalWrite(BLUE_LED, LOW);   // ปิด LED สีน้ำเงิน
    digitalWrite(RED_LED, HIGH); // กระพริบ LED สีแดง
    delay(250);
    digitalWrite(RED_LED, LOW);
    delay(250);
  }
  else {
    digitalWrite(RED_LED, LOW);// ปิด LED สีแดง
    digitalWrite(BLUE_LED, HIGH);   // กระพริบ LED สีน้ำเงิน
    delay(250);
    digitalWrite(BLUE_LED, LOW);
    delay(250);
  }
}
