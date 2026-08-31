const int IR_PIN = 5;
int irValue = 0;
void setup() {
  Serial.begin(115200);
  pinMode(IR_PIN, INPUT);
}
void loop() {
  // อ่านสถานะจากเซ็นเซอร์
  irValue = digitalRead(IR_PIN);
  // ตรวจสอบว่าตรวจพบวัตถุหรือไม่เซ็นเซอร์ IR ส่วนใหญ่ให้ค่า LOW เมื่อพบวัตถุ
  if (irValue == LOW) {
    Serial.println("พบวัตถุ");
  } else {
    Serial.println("ไม่พบวัตถุ");
  }
  delay(1000);
}
