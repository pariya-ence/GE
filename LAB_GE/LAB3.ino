/*  การเชื่อมต่อ 
  PIR VCC  -> 3.3V
  PIR GND  -> GND
  PIR OUT  -> GPIO4*/
#define PIR_PIN 4
void setup() {
  // เริ่มต้นการสื่อสารผ่าน Serial Monitor
  Serial.begin(115200);
  // กำหนดขา PIR เป็นอินพุต
  pinMode(PIR_PIN, INPUT);
}
void loop() {
  // อ่านค่าจากเซ็นเซอร์
  int motion = digitalRead(PIR_PIN);
  // ตรวจสอบสถานะการเคลื่อนไหว
  if (motion == HIGH) {
    Serial.println("Motion Detected");
  } else {
    Serial.println("No Motion");
  }
  delay(500);
}

