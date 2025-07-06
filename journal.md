# Journal – Gesture Controlled ESP32 Robot

## Week 1 – Brainstorming & Planning (6 hours)

In the first few days, I was going through different ideas for the Hack Club Highway project. I knew I wanted to do something with hardware, and I already had an ESP32 board at home. After thinking through some project options like home automation or obstacle detection bots, I finalized on building a gesture-controlled robot — the idea of controlling a robot with just hand movements sounded fun and a bit different.

I started checking if this was possible using ESP-NOW and if I could pair an MPU6050 sensor with one ESP32 and use that to control motors connected to another ESP32. I sketched out a rough design and what components I’d need.

---

## Week 2 – Research and Ordering Parts (5 hours)

I spent time reading about ESP-NOW communication and how others had used it for wireless data transfer. I also went through tutorials and docs to understand how to interface MPU6050 with ESP32 and how to get pitch/roll values.

I made a list of all the components I would need and looked for affordable options online. I had to compare prices across Amazon, Robu, and Flipkart. I ordered a 4WD chassis kit, a pair of ESP32 DevKit V1 boards, the MPU6050 sensor, an L298N motor driver, and a 12V battery pack. While waiting for delivery, I continued reading up and watching a few build videos.

---

## Week 3 – Setting Up and Initial Testing (7 hours)

The parts arrived, and I started by testing each one individually. I got the MPU6050 wired with one ESP32 on a breadboard. I used some sample Arduino code to get pitch and roll values. It was noisy at first, but after calibrating and tweaking delays, I got clean data.

Then I set up the second ESP32 with the motor driver and tested basic forward/backward motion. I wrote a small script to control each motor and verified the wiring was solid. I also figured out how to get the MAC addresses of the ESP32s to make ESP-NOW work.

I then wrote a basic sender and receiver script — one ESP32 reads the pitch/roll and sends them via ESP-NOW; the other receives it and prints values to Serial. This took trial and error to get working.

---

## Week 4 – Finalizing Code & Movement Logic (6 hours)

I focused on mapping gesture data to robot movements. I used simple thresholds: pitch forward = move forward, pitch back = reverse, roll left = left turn, roll right = right turn. If both values were near zero, it stopped.

It took some time to tune the thresholds. I had to test holding the sensor in different angles and check if it was behaving consistently. I also added print statements to debug, and after a few refinements, the bot started moving accurately based on hand tilt.

I also made sure the wiring was secure and rerouted wires on the robot using zip ties. I hot glued the ESP32 to the chassis to prevent wobbling during motion.

---

## Week 5 – Documentation & Submission (4 hours)

I created a full wiring diagram using a schematic builder. I took a picture of the final robot with everything mounted. I wrote the README explaining how the robot works and what files are in the repo. I also filled out the BOM with links and converted everything to both INR and USD as required.

Then I prepared this journal, made sure everything in the repo was organized, and submitted the project via pull request. I also posted about it in the Hack Club #highway channel and shared my GitHub repo.

---

**Total Time: 28 hours**

This project taught me a lot — not just about ESP-NOW and sensors, but also how to document properly and manage an electronics build from start to finish. Thanks to Hack Club for the push and guidance!

During the build 
![image](https://github.com/user-attachments/assets/376358d2-5348-4e3e-8cd2-8fea38ce9c92)

had to change the wires due to some issues
![image](https://github.com/user-attachments/assets/fb443dd2-37f2-4131-94c4-ab3ac9a75ba0)

![image](https://github.com/user-attachments/assets/a5c72e78-71df-4f6c-b91f-f3c79f9f2bf4)

Final build of the bot
![image](https://github.com/user-attachments/assets/5a6a33c0-3814-444a-9cf9-2060f27a072d)


