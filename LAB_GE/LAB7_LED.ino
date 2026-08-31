const int IR_PIN = 5;
const int RED_LED = 25;
int irValue = HIGH;
int lastState = HIGH;// เก็บสถานะก่อนหน้า
int count = 0;
void setup() {
  Serial.begin(115200);
  pinMode(IR_PIN, INPUT);
  pinMode(RED_LED, OUTPUT);
  digitalWrite(RED_LED, LOW);
}
void loop() {
  irValue = digitalRead(IR_PIN);// อ่านสถานะจากเซ็นเซอร์
 
  if (irValue == LOW && lastState == HIGH) { // LOW = ตรวจพบวัตถุ
    count++; // เพิ่มจำนวนวัตถุ
    digitalWrite(RED_LED, HIGH);   // กระพริบ LED 1 ครั้ง
    delay(200);
    digitalWrite(RED_LED, LOW);
  
    Serial.print("Object Count : ");
    Serial.println(count);
  }
  lastState = irValue;
  delay(50);
}
