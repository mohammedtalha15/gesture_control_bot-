#include <esp_now.h>
#include <WiFi.h>

// Created by Mohammed Talha for Hack Club Highway Grant

// Motor control pins
int motor1Pin1 = 27; 
int motor1Pin2 = 26; 
int motor1Pin3 = 21; 
int motor1Pin4 = 22;

// Incoming gesture values
float xGesture;
float yGesture;

// ESP-NOW struct
typedef struct GesturePacket {
    float xGesture;
    float yGesture;
} GesturePacket;

GesturePacket incomingGesture;
esp_now_peer_info_t peerInfo;

// Callback when data is sent (not used here)
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("Send status: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "✅ Success" : "❌ Fail");
}

// Callback when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&incomingGesture, incomingData, sizeof(incomingGesture));
  Serial.print("Data received (bytes): ");
  Serial.println(len);

  xGesture = incomingGesture.xGesture;
  yGesture = incomingGesture.yGesture;
  updateMotors();
}

void setup() {
  Serial.begin(115200);

  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor1Pin3, OUTPUT);
  pinMode(motor1Pin4, OUTPUT);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("❌ ESP-NOW Init Failed");
    return;
  }

  esp_now_register_send_cb(OnDataSent);
  esp_now_register_recv_cb(OnDataRecv);

  Serial.println("🤖 Talha’s Gesture Robot Ready");
}

void loop() {
  // Nothing in loop – logic happens on data receive
}

void updateMotors() {
  if (xGesture > 0.5) {
    Serial.println("← LEFT");
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor1Pin3, LOW);
    digitalWrite(motor1Pin4, HIGH);
  }
  else if (xGesture < -0.5) {
    Serial.println("→ RIGHT");
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor1Pin3, HIGH);
    digitalWrite(motor1Pin4, LOW);
  }
  else if (yGesture > 0.5) {
    Serial.println("↓ BACK");
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor1Pin3, LOW);
    digitalWrite(motor1Pin4, HIGH);
  }
  else if (yGesture < -0.5) {
    Serial.println("↑ FRONT");
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor1Pin3, HIGH);
    digitalWrite(motor1Pin4, LOW);
  }
  else {
    Serial.println("■ STOP");
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor1Pin3, LOW);
    digitalWrite(motor1Pin4, LOW);
  }

  Serial.println();
}
