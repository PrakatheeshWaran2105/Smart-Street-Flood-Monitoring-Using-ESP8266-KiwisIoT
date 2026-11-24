
#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

// WiFi Credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT Topic
const char* topic = "YOUR_TOPIC_ID";

// KiwisIoT Initialization
KiwisIoT kiwisiot(ssid, pass, topic);

// Pin Configuration
#define WATER_SENSOR A0
#define GREEN_LED D5
#define RED_LED D6
#define BUZZER D7

// Flood detection threshold
int floodThreshold = 500;

void setup() {
  Serial.begin(115200);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER, LOW);

  // Start KiwisIoT
  kiwisiot.begin();

  Serial.println("Smart Street Flood Monitoring Started");
}

void loop() {

  // Maintain KiwisIoT connection
  kiwisiot.run();

  // Read water sensor
  int waterLevel = analogRead(WATER_SENSOR);

  Serial.print("Water Level: ");
  Serial.println(waterLevel);

  String status;

  if (waterLevel >= floodThreshold) {

    // Flood detected
    status = "FLOOD ALERT";

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH);

    Serial.println("WARNING! Flood Detected!");

  } else {

    // Normal water level
    status = "NORMAL";

    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);

    Serial.println("Water Level Normal");
  }

  // Send data to KiwisIoT
  kiwisiot.send("0", String(waterLevel));
  kiwisiot.send("1", status);

  delay(1000);
}
