#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

Adafruit_BME280 bme;

const int soilMoisturePin = A0;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }

  if (!bme.begin(0x76)) {
    while (1);
  }
}

void loop() {
  int soilMoistureValue = analogRead(soilMoisturePin);

  float temperature = bme.readTemperature();
  float humidity = bme.readHumidity();
  float pressure = bme.readPressure() / 100.0F;

  Serial.print("Soil Moisture: ");
  Serial.println(soilMoistureValue);
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");

  String url = "http://your_server_endpoint.com/?soil_moisture=" + String(soilMoistureValue) +
               "&temperature=" + String(temperature) +
               "&humidity=" + String(humidity) +
               "&pressure=" + String(pressure);

  WiFiClient client;
  if (client.connect("your_server_endpoint.com", 80)) {
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: your_server_endpoint.com\r\n" +
                 "Connection: close\r\n\r\n");
    delay(10);
    while (client.available()) {
      String line = client.readStringUntil('\r');
    }
    client.stop();
  }

  delay(5000);
}
