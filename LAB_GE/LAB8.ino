#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_TEMPLATE_NAME "YourTemplateName"
#define BLYNK_AUTH_TOKEN "YourAuthToken"
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
char ssid[] = "YourWiFiName";
char pass[] = "YourWiFiPassword";
BlynkTimer timer;
int value = 0;
void sendData() {
  value++;
  // ส่งค่าตัวแปรไปยัง V0
  Blynk.virtualWrite(V0, value);
  // ส่งข้อความไปยัง V1
  Blynk.virtualWrite(V1, "ESP32 Online");
  Serial.print("Value = ");
  Serial.println(value);
}
void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}
void loop() {
  Blynk.run();
  sendData();
  delay(2000);
}
