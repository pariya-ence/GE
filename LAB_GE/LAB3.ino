/*การเชื่อมต่ออุปกรณ์
  PIR Motion Sensor
    VCC  -> 3.3V
    GND  -> GND
    OUT  -> GPIO4
  LED
    Anode (+)   -> GPIO2
    Cathode (-) -> ตัวต้านทาน 220Ω -> GND*/
int PIR_PIN = 4;     // ขาสัญญาณจาก PIR Motion Sensor
int LED_PIN = 2;     // ขาควบคุม LED

void setup() {
  Serial.begin(115200);
  // กำหนดโหมดการทำงานของขา GPIO
  pinMode(PIR_PIN, INPUT);     // PIR เป็นอินพุต
  pinMode(LED_PIN, OUTPUT);    // LED เป็นเอาต์พุต
  // ปิด LED เมื่อเริ่มต้นโปรแกรม
  digitalWrite(LED_PIN, LOW);
}
void loop() {
  // HIGH = พบการเคลื่อนไหว
  // LOW  = ไม่พบการเคลื่อนไหว
  int motion = digitalRead(PIR_PIN);
  if (motion == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Motion Detected");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("No Motion");
  }
  delay(500);
}
