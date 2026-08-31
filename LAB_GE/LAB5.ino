#include <DHT.h>// ไลบรารีสำหรับจัดการเซ็นเซอร์ DHT
// กำหนดขา Pin และชนิดของเซ็นเซอร์
const int DHT_PIN = 18; // ขา DATA ต่อเข้ากับ GPIO18
#define DHTTYPE DHT22 // ระบุประเภทเซ็นเซอร์เป็น DHT22 (AM2302)
// ประกาศออบเจกต์ dht สำหรับดึงฟังก์ชันใช้งาน
DHT dht(DHT_PIN, DHTTYPE);
void setup() {
Serial.begin(115200);
// เริ่มต้นการทำงานของตัวอ่านเซ็นเซอร์ DHT22
dht.begin();
}

void loop() {
// อ่านค่าความชื้นสัมพัทธ์ (%) เก็บเข้าตัวแปร humidity
float humidity = dht.readHumidity();
// อ่านค่าอุณหภูมิ (องศาเซลเซียส) เก็บเข้าตัวแปร temperature
float temperature = dht.readTemperature();
// แสดงผลค่าอุณหภูมิและความชื้นผ่าน Serial Monitor
Serial.print("Humidity: ");
Serial.print(humidity);
Serial.print(" % | Temperature: ");
Serial.print(temperature);
Serial.println(" °C");
delay(1000);
}
