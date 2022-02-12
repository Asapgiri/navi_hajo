#include <Arduino.h>
#include "ESP8266WiFi.h"
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>
#include "htmls.h"
#include <queue>
#include <SoftwareSerial.h>

#define __DEBUG true
#define HASHING_CONST 7
#define BUFFER_SIZE 100

const PROGMEM char *_ssid = "Telekom-t3RCER";
const PROGMEM char *_password = "3u66tbuumtxp";
// const PROGMEM char *_ssid = "Nem";
// const PROGMEM char *_password = "nemnemnem";

SoftwareSerial ss(14, 12);

ESP8266WebServer server(80);
void handleIndex();
void handleAuto();
void requestData();
void sendData();
void readIncoming();

String waitForAnswer();
String hash(const String &str);
void handleIncomingData();

std::queue<String> serial_buffer;

void setup() {
  Serial.begin(9600);         // Start the Serial communication to send messages to the computer
  ss.begin(9600);
  while (!Serial);
  if (__DEBUG) Serial.println('\n');

  WiFi.begin(_ssid, _password);             // Connect to the network
  if (__DEBUG) Serial.print("Connecting to ");
  if (__DEBUG) { Serial.print(_ssid); Serial.println(" ..."); }

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    if (__DEBUG) { Serial.print(++i); Serial.print('.'); }
  }

  if (__DEBUG) Serial.println('\n');
  if (__DEBUG) Serial.println("Connection established!");
  if (__DEBUG) Serial.print("IP address:\t");
  if (__DEBUG) Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer

  server.on("/",handleIndex);
  server.on("/auto",handleAuto);
  server.on("/request_data", readIncoming);
  server.on("/send_data",sendData);
  server.begin();
}


uint64_t time_loop = 0;

void loop() {
  server.handleClient();
  if (millis() > time_loop) {
    handleIncomingData();
    time_loop = millis() + 50;
  }
  //delay(10);
}

void handleIndex() {
  server.send(200, "text/html", index_html);
}

void handleAuto() {
  server.send(200, "text/html", auto_html);
}

/*void requestData() {
  DynamicJsonDocument doc(1024);
  doc["tt"] = "req";
  serializeJson(doc,Serial);
  boolean messageReady = false;
  String message = "";
  unsigned long timer = millis();
  if (__DEBUG) Serial.println("Waiting for response...");
  while(messageReady == false) { // blocking but that's ok
    if(Serial.available()) {
      message = Serial.readStringUntil('\n');
      messageReady = true;
    }
    //Serial.print('.');
    if (millis() > timer + 5000) {
      messageReady = true;
      message = "FAILED.";
    }
  }
  // Attempt to deserialize the JSON-formatted message
  DeserializationError error = deserializeJson(doc,message);
  if(error && __DEBUG) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    //return;
  }
  server.send(200,"text/plain", message);
  Serial.println();
}*/

void sendData() {
  DynamicJsonDocument doc(1024);
  String message;
  doc["t"] = "ds";
  for (int i = 0; i < server.args(); i++) {
    doc[server.argName(i)] = server.arg(i);
  }
  serializeJson(doc, message);
  //Maybe a wait for data function is needed...
  ss.print(message);
  ss.print("#");
  ss.println(hash(message));
  server.send(200, "text/plain", "");
}

String hash(const String &str) {
  uint64_t hash = 0;
  for (int i = 0; i < str.length(); i++) {
    uint8_t sz = (HASHING_CONST * i) % 256;
    uint8_t hashed = (uint8_t)str[i] * sz;
    uint64_t shifted = (uint64_t)hashed << ((i % 8) * 8);

    hash += shifted;
  }

  //Serial.println(hash);
  String ret = "";

  for (int i = 0; i < 8; i++) {
    char c = (char)(hash & (uint64_t)0xff);
    // Serial.print((int)c);
    // Serial.println(", ");
    ret += c;
    hash = hash >> 8;
  }  

  return ret;
}

void readIncoming() {
  Serial.print("Requested data from client... ");
  if (serial_buffer.size() > 0) {
    Serial.print("data exists (");
    Serial.print(serial_buffer.size());
    Serial.print(")");
    server.send(200, "text/plain", serial_buffer.front());
    serial_buffer.pop();
  }
  else {
    server.send(200, "text/plain", "");
    Serial.println("no data");
  }
}

void handleIncomingData() {
  //uint64_t time = millis();
  bool messageReady = false;
  String message, hashed, chash;
  while (ss.available()) {
    // Serial.print((char)ss.read());

    const char c = ss.read();
    //Serial.print(c);
    if (c == '{') {
      Serial.println("Handle incoming...");
      message = c;
      message += ss.readStringUntil('#');
      hashed = ss.readStringUntil('\n');
      chash = hash(message);
      Serial.println(message);
      Serial.println(hashed);
      Serial.println(chash);

      messageReady = true;
      for (int i = 0; i < 8; i++) {
        if (hashed[i] != chash[i]) messageReady = false;
      }
      // Serial.println(messageReady);
    }
    // else serial_buffer.push("{\"t\":\"empty\"}");
  }

  if (messageReady) {
    if (serial_buffer.size() >= BUFFER_SIZE) serial_buffer.pop();
    serial_buffer.push(message);
    Serial.print("New buffer size: ");
    Serial.println(serial_buffer.size());
  }
  //Serial.print("Tile ellapsed: ");
  //Serial.print(millis() - time);
  //Serial.println("ms");
}

//String waitForAnswer() {}
