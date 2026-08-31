/* การเชื่อมต่ออุปกรณ์
  Soil Moisture Sensor
    VCC -> 3.3V
    GND -> GND
    AO  -> GPIO34 (ADC Input)
    DO  -> ไม่ต้องใช้งาน
*/
const int SOIL_PIN = 34;// กำหนดขา Analog ที่ใช้รับค่าจากเซ็นเซอร์
const int RED_LED_PIN = 2; // ขาต่อ LED สีแดง (แสดงสถานะดินแห้ง) 
const int BLUE_LED_PIN = 4; // ขาต่อ LED สีน้ำเงิน (แสดงสถานะดินเปียก)
int soil = 0;// ตัวแปรสำหรับเก็บค่าความชื้น
int moisture;
void setup() {
  Serial.begin(115200);// เริ่มต้นการสื่อสารผ่าน Serial Monitor
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(SOIL_PIN, INPUT);
}
void loop() {
  soil = analogRead(SOIL_PIN);// อ่านค่าจากเซ็นเซอร์ (0-4095)
  Serial.print("Soil Moisture Value : ");
  Serial.println(soil);
  moisture= map(soil, 0, 4095, 0, 100);//แปลงแรงดันไฟฟ้า 0 ถึง 4095 เป็น %
  Serial.print("Soil Moisture (%) : ");
  Serial.println(moisture);
if (moisture < 30) { // กรณีความชื้นน้อยกว่า 30%: ถือเป็น "ดินแห้ง" 
digitalWrite(RED_LED_PIN, HIGH); // เปิด LED สีแดง 
digitalWrite(BLUE_LED_PIN, LOW); // ปิด LED สีน้ำเงิน 
Serial.println("ดินแห้ง"); 
} 
else { // กรณีความชื้นมากกว่าหรือเท่ากับ 30%: ถือเป็น "ดินเปียก" 
digitalWrite(RED_LED_PIN, LOW); // ปิด LED สีแดง
digitalWrite(BLUE_LED_PIN, HIGH); // เปิด LED สีน้ำเงิน 
Serial.println("ดินเปียก"); }
delay(1000);
}

