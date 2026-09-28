#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_TEMPLATE_NAME "YourTemplateName"
#define BLYNK_AUTH_TOKEN "YourAuthToken"
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
char ssid[] = "wifiname"; // ชื่อ Wi-Fi ตนเอง
char pass[] = "wifipassword";// Password Wi-Fi ตนเอง
#define LED1 25
#define LED2 26
BLYNK_WRITE(V0) {
  int value = param.asInt();
  digitalWrite(LED1, value);
}
BLYNK_WRITE(V1) {
  int value = param.asInt();
  digitalWrite(LED2, value);
}
void setup() {
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}
void loop() {
  Blynk.run();
}
