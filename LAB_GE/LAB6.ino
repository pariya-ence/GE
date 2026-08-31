const int TRIG_PIN = 18;
const int ECHO_PIN = 19;
long duration;// เก็บระยะเวลาที่คลื่นเสียงเดินทาง
float distance;// เก็บค่าระยะทาง (เซนติเมตร)
void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}
void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  // อ่านระยะเวลาที่ Echo รับสัญญาณกลับ
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.0343 / 2;  // ความเร็วเสียง = 0.0343 cm/us หาร 2 ไป-กลับ
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(1000);
}
