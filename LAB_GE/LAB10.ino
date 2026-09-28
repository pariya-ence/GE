#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_TEMPLATE_NAME "YourTemplateName"
#define BLYNK_AUTH_TOKEN "YourAuthToken"
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
char ssid[] = "wifiname"; // ชื่อ Wi-Fi ตนเอง
char pass[] = "wifipassword";// Password Wi-Fi ตนเอง
#define DHTPIN 18
#define DHTTYPE DHT22
BlynkTimer timer;
DHT dht(DHTPIN, DHTTYPE);
void sendSensorData() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  // ส่งอุณหภูมิและความชื้นไปยัง Blynk
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);
  // ตรวจสอบอุณหภูมิและส่งข้อความสถานะ
  if (temperature > 25) {
    Blynk.virtualWrite(V2, "อุณหภูมิสูง");
  } else {
    Blynk.virtualWrite(V2, "อุณหภูมิปกติ");
  }
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C  Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}
void setup() {
  Serial.begin(115200);
  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // อ่านและส่งข้อมูลทุก 2 วินาที
  timer.setInterval(2000L, sendSensorData);
}
void loop() {
  Blynk.run();
  timer.run();
}
