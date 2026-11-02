#include <DHT.h>
#include <WiFiS3.h>
#include <PubSubClient.h>
#include "passwd.h"

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  dht.begin();

  while(WiFi.status() != WL_CONNECTED) {
    delay(400);
    Serial.println("Waiting for Wi-Fi connection...");
  }

  Serial.print("Arduino IP: ");
  Serial.println(WiFi.localIP());

  mqttClient.setServer(localip, port);

  if(mqttClient.connect("arduino_uno_r4")) {
    Serial.println("Connection to MQTT successful!");
    mqttClient.publish("home/temperature", "31.2");
  } else {
    Serial.println("Connection to MQTT unsuccessful.");
    Serial.println(mqttClient.state());
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  float temp = dht.readTemperature();
  float humid = dht.readHumidity();

  if (isnan(temp) || isnan(humid)) {
    Serial.println("ERROR : failed to read Sensor!");
    return;
  }

  Serial.print("Temperature : ");
  Serial.print(temp);
  Serial.println(" C");

  Serial.print("Humidity : ");
  Serial.print(humid);
  Serial.println("%");
  delay(4000);
}
