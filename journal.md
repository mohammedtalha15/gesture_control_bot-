---
title: "Gesture Controlled ESP32 Robot"
author: "Mohammed Talha (mohammedtalha15)"
description: "A robot that moves based on hand gestures using ESP-NOW between two ESP32 boards."
created_at: "2024-06-20"
total_time_hours: 28
---

# Journal – Gesture Controlled ESP32 Robot

## Week 1 – Idea and Planning (4 hours)

I started off thinking about what I could build with the ESP32 boards I already had. After checking out a few ideas, I came up with the concept of a gesture-controlled robot using ESP-NOW. It felt like a good mix of fun and challenge, and I hadn't seen too many people do it without a phone or remote.

## Week 2 – Research and Components (6 hours)

I looked up how the MPU6050 sensor works and how ESP-NOW can be used to send data between two ESP32s. I also listed all the parts I needed — like the motor driver, chassis, battery, etc. I already had some of them from old kits. I spent time going through tutorials and examples to understand how to structure the sender and receiver code.

## Week 3 – Coding and Prototyping (10 hours)

I started writing the code on both ends — one ESP32 reads the motion data and the other moves the motors based on that. I had to test and tune how the MPU6050 responds to tilt and how to format the data for ESP-NOW transmission. After some trial and error, I got consistent communication and reliable gesture detection.

## Week 4 – Assembly, Testing, and Documentation (8 hours)

I mounted the motor driver and receiver board on the robot chassis. The transmitter ESP32 and MPU6050 stayed on a breadboard. After connecting everything, the robot finally responded to hand movement as expected. I also made a circuit schematic, wrote the project report, added a README, created the BOM and this journal, and took a photo of the final setup to include in the repo.

Then I submitted everything to the Hack Club Highway repo and posted in the Slack channel.

---

This project helped me understand ESP-NOW really well and gave me hands-on experience with wireless motion control. Glad I went with this idea!
