/* การเชื่อมต่ออุปกรณ์
  Soil Moisture Sensor
    VCC -> 3.3V
    GND -> GND
    AO  -> GPIO34 (ADC Input)
    DO  -> ไม่ต้องใช้งาน
*/
const int SOIL_PIN = 34;// กำหนดขา Analog ที่ใช้รับค่าจากเซ็นเซอร์
int soil = 0;// ตัวแปรสำหรับเก็บค่าความชื้น
int moisture;
void setup() {
  Serial.begin(115200);// เริ่มต้นการสื่อสารผ่าน Serial Monitor
   pinMode(SOIL_PIN, INPUT);
}
void loop() {
  soil = analogRead(SOIL_PIN);// อ่านค่าจากเซ็นเซอร์ (0-4095)
  Serial.print("Soil Moisture Value : ");
  Serial.println(soil);
  moisture= map(soil, 0, 4095, 0, 100);//แปลงแรงดันไฟฟ้า 0 ถึง 4095 เป็น %
  Serial.print("Soil Moisture (%) : ");
  Serial.println(moistur);
  delay(1000);
}
