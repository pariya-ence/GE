#include <DHT.h>
// ขา DATA ของ DHT22
#define DHTPIN 18
#define DHTTYPE DHT22
#define RED_LED 25
#define BLUE_LED 26
DHT dht(DHTPIN, DHTTYPE);
float temperature = 0.0;
// เก็บค่าความชื้น
float humidity = 0.0;
void setup() {
  // เริ่มต้นการสื่อสารผ่าน Serial Monitor
  Serial.begin(115200);
  // เริ่มต้นการทำงานของเซ็นเซอร์ DHT22
  dht.begin();
  // กำหนดขา LED เป็นเอาต์พุต
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  // ปิด LED ทั้งสองดวงเมื่อเริ่มต้น
  digitalWrite(RED_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
}
void loop() {
  // อ่านค่าความชื้นจากเซ็นเซอร์
  humidity = dht.readHumidity();
  // อ่านค่าอุณหภูมิจากเซ็นเซอร์
  temperature = dht.readTemperature();
    // แสดงค่าอุณหภูมิ
    Serial.print("Temperature : ");
    Serial.print(temperature);
    Serial.println(" °C");
   // แสดงค่าความชื้น
    Serial.print("Humidity    : ");
    Serial.print(humidity);
    Serial.println(" %");
    //==================== ตรวจสอบอุณหภูมิ ====================
    if (temperature > 25.0) {
      digitalWrite(RED_LED, HIGH);  // เปิด LED สีแดง
    } else {
      digitalWrite(RED_LED, LOW); // ปิด LED สีแดง
    }
    //==================== ตรวจสอบความชื้น ====================
    if (humidity > 50.0) {
      digitalWrite(BLUE_LED, HIGH);  // เปิด LED สีน้ำเงิน
    } else {
      digitalWrite(BLUE_LED, LOW);// ปิด LED สีน้ำเงิน
    }
    Serial.println("----------------------------------------");
  delay(1000);
}
