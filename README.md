# Gesture Controlled ESP32 Robot

This is a robot I built that moves based on hand gestures. I used two ESP32 boards — one for reading my hand movement using an MPU6050 sensor, and the other to control the motors on the robot. The ESP32 boards talk to each other wirelessly using ESP-NOW. I don't use any remote or phone — just hand tilt.

## What it does

- When I tilt my hand forward, the robot goes forward.
- If I tilt backward, it goes backward.
- Tilting left or right makes the robot turn left or right.
- When my hand is straight, the robot stops.

## Parts I used

- 2 ESP32 boards
- MPU6050 (to detect tilt)
- L298N motor driver
- 4 geared DC motors (12V)
- 4WD robot chassis
- 12V battery pack
- Jumper wires, pins, zip ties
- Soldering kit, multimeter, glue, etc.

## How I built it

I put the MPU6050 and one ESP32 on a breadboard — this is the controller.  
The other ESP32 is fixed on the robot chassis with the motor driver.  
I wrote code for both sides. The controller reads pitch/roll and sends values through ESP-NOW. The receiver gets the values and moves the motors based on that.
![image](https://github.com/user-attachments/assets/94322965-7725-4556-8e8b-44a2718bec8c)

I tested and tuned it till the robot started responding correctly to the gestures.

## Files in this repo

- `gesture_controller_sender.ino` → Transmitter side (MPU6050 + ESP32)
- `gesture_control_robot.ino` → Receiver side (ESP32 + motor driver)
- `hardware_schematic.png` → Circuit diagram
- `final_project_report.pdf` → Short report of the whole project
- `journal.md` → Week-by-week build journal
- `bom.md` → List of all components and their cost
- `robot_real_build.jpg` → Actual image of the built robot
- `README.md` → This file

## How to use it

1. Upload the sender code to the ESP32 with MPU6050.
2. Upload the receiver code to the ESP32 on the chassis.
3. Power both.
4. Tilt the controller board in your hand and the robot will move.

Make sure to put the correct MAC addresses in the code. Sensor readings may need some fine-tuning depending on your MPU6050.

## License

This project is under GNU GPLv3 License.

---

Built for Hack Club Highway.
![image](https://github.com/user-attachments/assets/56722625-7d3b-4e62-9199-191b1c779efa)
