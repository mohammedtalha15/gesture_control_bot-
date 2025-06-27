# Gesture Controlled ESP32 Robot 🤖✋

Hi! I'm Mohammed Talha, and this is my hardware project built for the Hack Club Highway.  
It's a gesture-controlled robot using ESP32 modules and ESP-NOW for wireless communication.

Basically, I move one ESP32 (with a motion sensor), and the robot receives the data and moves in that direction — forward, back, left, or right. No remote needed!

---

## 🧠 How It Works

- I used **ESP-NOW** to send data wirelessly between two ESP32 boards.
- On the controller side, I used motion data (from the accelerometer/gyroscope) to detect hand tilt.
- That data gets sent to the receiver ESP32, which controls the robot’s motors using a motor driver.
- Different tilts = different movements!

---

## 🛠 Tech & Components Used

- 2x ESP32 boards
- MPU6050 motion sensor
- L298N Motor Driver
- 4-wheel robot chassis
- 12V battery
- Arduino IDE (for coding)
- ESP-NOW protocol (for wireless)

---

## 📂 Files Included

- `gesture_control_robot.ino` – Main code for ESP32 controller
- `robot_receiver.ino` – Code for receiver robot ESP32
- `hardware_schematic.png` – Full wiring diagram
- `final_project_report.pdf` – 2-page explanation of idea, tech, and impact

---

## 📸 Preview

![Schematic](hardware_schematic.png)

---

## 💡 Why I Built This

I wanted to try something fun and different with ESP32. Gesture control felt futuristic and I wanted to see if I could pull it off — and it worked!

Big thanks to Hack Club for motivating this through the Highway project grants 🙌

---

### 🔗 GitHub Repo  
https://github.com/mohammedtalha15/gesture_control_bot-

Made with ❤️ from India 🇮🇳
