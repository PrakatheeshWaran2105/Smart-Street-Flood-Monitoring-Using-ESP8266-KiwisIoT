# Smart-Street-Flood-Monitoring-Using-ESP8266-KiwisIoT
IoT-based street flood monitoring using NodeMCU ESP8266 and a water level sensor with real-time cloud data monitoring through KiwisIoT.
Smart Street Flood Monitoring System using ESP8266 and KiwisIoT

About the Project

The Smart Street Flood Monitoring System is an IoT-based project developed using NodeMCU ESP8266 and a water level sensor to detect rising water levels. The sensor continuously provides readings to the ESP8266, which processes the data and activates a green LED during normal conditions or a red LED and buzzer when the water level reaches the configured flood threshold.

KiwisIoT is integrated into this project for cloud communication and remote sensor monitoring. The ESP8266 connects to Wi-Fi and uses the KiwisIoT Arduino library to communicate with the platform through a configured Topic ID. Using kiwisiot.begin(), kiwisiot.run(), and kiwisiot.send(), the device publishes water-level readings and flood status to the KiwisIoT dashboard.

The KiwisIoT dashboard receives the published data through configured channels. Channel 0 is used to display water-level readings through a Gauge or Numeric Display, while Channel 1 carries the flood status for remote monitoring. This allows users to observe sensor information and identify flood-warning conditions through the cloud dashboard.
Software Requirements

Arduino IDE

ESP8266 Board Package

KiwisIoT Arduino Library

KiwisIoT Dashboard

Project Link:https://www.hackster.io/prakatheesh2105/smart-street-flood-monitoring-using-esp8266-kiwisiot-2d3a4b

KiwisIoT Platform: https://kiwisiot.com/

Hackster Project: Add your published Hackster project URL here.

Learn More

Explore KiwisIoT for connecting IoT devices, transmitting sensor data, and monitoring project information through its cloud dashboard.

Website: https://kiwisiot.com/
