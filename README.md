# Gesture Controlled ESP32 Robot

This project implements a gesture-controlled robot using **ESP32** boards communicating via **ESP-NOW protocol**. The robot interprets hand gestures (based on X and Y axis motion) and performs actions like **FORWARD**, **BACKWARD**, **LEFT**, **RIGHT**, or **STOP** depending on threshold values.

---

## 📦 Features

- 🤝 ESP-NOW communication (no WiFi needed)
- 🖐️ Gesture-based control using accelerometer readings
- ⚡ Real-time robot movement control
- 🔧 Customizable motor control logic and gesture thresholds

---

## 🔧 Hardware Used

- 2 × ESP32 boards (1 for transmitter, 1 for robot)
- 1 × Accelerometer (e.g., MPU6050)
- L298N Motor Driver Module
- 4 × DC Motors with wheels
- Battery pack
- Robot chassis

---

## 📁 File Structure
├── gesture_control_sender.ino      # Code to collect and send gesture data
├── gesture_control_robot.ino      # Code to receive data and control motors
├── LICENSE                        # GNU GPL v3.0 license
└── README.md                      # This file
---

## 🚀 How to Run

### 1. 🛠️ Wiring and Setup

- Upload `gesture_control_sender.ino` to your ESP32 sender.
- Upload `gesture_control_robot.ino` to your ESP32 receiver.
- Connect motors to the receiver ESP32 through the motor driver.
- Ensure you set the correct `broadcastAddress[]` (receiver MAC address) in the sender code.

### 2. ⚙️ Motor Pin Setup (in robot code)

```cpp
int motor1Pin1 = 27; 
int motor1Pin2 = 26; 
int motor1Pin3 = 21; 
int motor1Pin4 = 22; 
3. 🎚️ Threshold Logic

In the updateDisplay() function:
	•	X-axis:
	•	X < -3 → LEFT
	•	X > 3 → RIGHT
	•	Y-axis:
	•	Y < -4 → FORWARD
	•	Y > 3 → BACKWARD
	•	Default → STOP

Adjust the thresholds based on testing and your accelerometer’s behavior.

⸻

📦 Libraries Required
	•	WiFi.h
	•	esp_now.h
	•	(Optional: Wire.h and accelerometer library for gesture input)

⸻

📄 License

This project is licensed under the terms of the GNU General Public License v3.0.
See the LICENSE file for more information.

⸻

👨‍💻 Author

Mohammed Talha
BMSIT | CSE | Robotics & IoT Enthusiast
GitHub: @mohammedtalha

⸻

🙌 Acknowledgements
	•	ESP-NOW Documentation (Espressif)
	•	Inspiration from similar gesture robot builds in robotics communities

⸻

🔧 Built with passion, debugged with patience, and run wirelessly.
---

Let me know if you want this updated with teammates, images/GIFs, or demo video links.

