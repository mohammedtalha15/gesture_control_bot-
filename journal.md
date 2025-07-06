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



Final build of the bot
https://private-user-images.githubusercontent.com/205971717/460258413-94322965-7725-4556-8e8b-44a2718bec8c.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NTE4MTQyMDcsIm5iZiI6MTc1MTgxMzkwNywicGF0aCI6Ii8yMDU5NzE3MTcvNDYwMjU4NDEzLTk0MzIyOTY1LTc3MjUtNDU1Ni04ZThiLTQ0YTI3MThiZWM4Yy5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwNzA2JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDcwNlQxNDU4MjdaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1lNDQyZWQ5YjA4Yzg1MzU5Y2Y3ZTlmMzlhNWQwZjhiYWQ4NmM1YmQzMDE0ZjhmZGQyYTM3MjA4MjIyYzFlMDg5JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.q_Sx3Bz0Pxz6KBZaetHriMH5544KyIQALzq9tfLcYEk![image](https://github.com/user-attachments/assets/8d2ffb9a-d20b-48fe-b93f-c2193cf4fdab)


