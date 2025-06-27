#include <esp_now.h>
#include <WiFi.h>
#include <M5Core2.h>

// Receiver MAC Address (replace with your bot's ESP32 MAC)
uint8_t broadcastAddress[] = {0xA4, 0xCF, 0x12, 0x8D, 0x0E, 0x7C};

// IMU values
float accX = 0.0F, accY = 0.0F, accZ = 0.0F;
float gyroX = 0.0F, gyroY = 0.0F, gyroZ = 0.0F;
float pitch = 0.0F, roll = 0.0F, yaw = 0.0F;
float temp = 0.0F;

String success;

// Struct for sending gesture values
typedef struct struct_message {
  float xVal;
  float yVal;
} struct_message;

struct_message gestureData;

esp_now_peer_info_t peerInfo;

// Send status callback
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("Send Status: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Success ✅" : "Fail ❌");
  success = (status == ESP_NOW_SEND_SUCCESS) ? "✅ Delivered" : "❌ Failed";
  digitalWrite(2, status == ESP_NOW_SEND_SUCCESS ? HIGH : LOW);
  delay(100);
  digitalWrite(2, LOW);
}

void setup() {
  M5.begin();
  M5.IMU.Init();
  M5.Lcd.setTextSize(2);
  M5.Lcd.print("Tilt to control robot 🚗");

  Serial.begin(115200);
  pinMode(2, OUTPUT); // LED pin

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed ❌");
    return;
  }

  esp_now_register_send_cb(OnDataSent);

  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer ❌");
    return;
  }
}

void loop() {
  M5.IMU.getAccelData(&accX, &accY, &accZ);
  M5.IMU.getAhrsData(&pitch, &roll, &yaw);
  M5.IMU.getTempData(&temp);

  gestureData.xVal = accX;
  gestureData.yVal = accY;

  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &gestureData, sizeof(gestureData));

  if (result == ESP_OK) {
    Serial.print("Sent → ");
    if (accX > 0.5) Serial.println("Tilt Right →");
    else if (accX < -0.5) Serial.println("Tilt Left ←");
    else if (accY > 0.5) Serial.println("Tilt Forward ↑");
    else if (accY < -0.5) Serial.println("Tilt Back ↓");
    else Serial.println("Idle ▫");
  } else {
    Serial.println("Send Failed ❌");
  }

  delay(800);
}
