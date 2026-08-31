// กำหนดขา Pin ของอุปกรณ์
const int SOIL_PIN = 34;      // ขา Analog Output (AO) จากเซ็นเซอร์ เข้า GPIO34 (ADC1_CH6)
const int RED_LED_PIN = 2;    // ขาต่อ LED สีแดง (แสดงสถานะดินแห้ง)
const int BLUE_LED_PIN = 4;   // ขาต่อ LED สีน้ำเงิน (แสดงสถานะดินเปียก)
void setup() {
  // เริ่มต้นการสื่อสาร Serial Monitor ที่ความเร็ว 115200 bps
  Serial.begin(115200);
  // กำหนดโหมดของขา GPIO สำหรับควบคุม LED ให้เป็นขา Output
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  // กำหนดขาอ่านเซ็นเซอร์เป็น Input (ขา GPIO34 บน ESP32 เป็น Input Only)
  pinMode(SOIL_PIN, INPUT);
  // ปิด LED ทั้งสองดวงก่อนเริ่มทำงาน
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(BLUE_LED_PIN, LOW);
}
void loop() {
  // 1. อ่านค่าสัญญาณ Analog จากเซ็นเซอร์ (ความละเอียด 12-bit ของ ESP32 จะได้ช่วงค่า 0 - 4095)
  int soil = analogRead(SOIL_PIN);
  // 2. แปลงค่า Analog ช่วง 0–4095 เป็นเปอร์เซ็นต์ความชื้นช่วง 0–100%
  int moisture = map(soil, 0, 4095, 0, 100);

  // 3. แสดงผลค่า Analog และค่าเปอร์เซ็นต์ความชื้นออกทาง Serial Monitor
  Serial.print("Analog Value: ");
  Serial.print(soil);
  Serial.print(" | Moisture: ");
  Serial.print(moisture);
  Serial.print("% | Status: ");

  // 4. เงื่อนไขการจำแนกสถานะดิน และการสั่งงาน LED
  if (moisturePercent < 30) {
    // กรณีความชื้นน้อยกว่า 30%: ถือเป็น "ดินแห้ง"
    digitalWrite(RED_LED_PIN, HIGH);   // เปิด LED สีแดง
    digitalWrite(BLUE_LED_PIN, LOW);   // ปิด LED สีน้ำเงิน
    Serial.println("ดินแห้ง");
  } else {
    // กรณีความชื้นมากกว่าหรือเท่ากับ 30%: ถือเป็น "ดินเปียก"
    digitalWrite(RED_LED_PIN, LOW);    // ปิด LED สีแดง
    digitalWrite(BLUE_LED_PIN, HIGH);  // เปิด LED สีน้ำเงิน
    Serial.println("ดินเปียก");
  }

  // 5. หน่วงเวลา 1 วินาที (1000 มิลลิวินาที) ก่อนการอ่านค่ารอบถัดไป
  delay(1000);
}
