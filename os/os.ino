#include <Wire.h>
#include "SSD1306Wire.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>

#define SDA 4
#define SCL 5
#define OLED_RST 16

const char* ssid; //YOUR SSID;
const char* password; //YOUR WiFi Password;

SSD1306Wire display(0x3c, SDA, SCL, GEOMETRY_128_32);

String dateTimeHost = "https://dt.kootahkon.ir/datetime"; 
String smileHost = "https://dt.kootahkon.ir/smile";

void setup() {
  pinMode(OLED_RST, OUTPUT);
  digitalWrite(OLED_RST, HIGH);
  display.init();
  display.setFont(ArialMT_Plain_10);
  display.drawString(1, 1, "Robolens OS 0.0.1");
  display.display();
  delay(1000);
  display.clear();
  display.display();
  display.drawString(1, 1, "Connecting to the \nwifi network...");
  display.display();
  delay(2500);
  WiFi.begin(ssid, password);
  display.clear();
  display.display();
  while (WiFi.status() != WL_CONNECTED) {

    display.drawString(1, 1, "Connecting to: " + String(ssid));
    display.display();
    delay(500);

    display.clear();
    display.display();
    delay(500);
  }

  display.clear();
  display.display();
  display.drawString(1, 1, "Connected!");
  display.display();

  display.clear();
  display.display();

}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {

    WiFiClientSecure client;
    HTTPClient http;

    client.setInsecure();
    client.connect(dateTimeHost, 443);
    
    http.begin(client, dateTimeHost); //API to be changed
    
    int httpCode = http.GET();

    if (httpCode > 0) {
      String payload = http.getString();
      display.drawString(1, 1, payload);
      display.display();
    } else {
      display.drawString(1, 1, "Error code: " + String(httpCode));
      display.display();
    }

    http.end();
  }
  delay(20000);
  display.clear();
  display.display();
  delay(1000);
  if (WiFi.status() == WL_CONNECTED) {

    WiFiClientSecure client;
    HTTPClient http;

    client.setInsecure();
    client.connect(smileHost, 443);
    
    http.begin(client, smileHost); //API to be changed
    
    int httpCode = http.GET();

    if (httpCode > 0) {
      String payload = http.getString();
      display.drawString(1, 1, payload);
      display.display();
    } else {
      display.drawString(1, 1, "Error code: " + String(httpCode));
      display.display();
    }

    http.end();
  }
  delay(2000);
  display.clear();

}
