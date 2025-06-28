# Journal – Gesture Controlled ESP32 Robot

## Week 1 – Idea and Planning

I started off by going through a few ideas for the Hack Club Highway project. I knew I wanted to do something hands-on with ESP32 because I had worked with it before. After exploring a few hardware concepts, I came up with the idea of controlling a robot using hand gestures — no remotes, just movement. It sounded like something fun and different, so I decided to go for it.

## Week 2 – Components and Research

I looked into what I would need for this build. I already had two ESP32 boards and an MPU6050 motion sensor. I also got a basic robot chassis, L298N motor driver, and a 12V battery. I spent time understanding how ESP-NOW works, and how I could use it to send sensor data wirelessly between the two ESP32 boards.

## Week 3 – Coding and Testing

I started coding both the transmitter and receiver ESP32s. On the controller side, I read data from the MPU6050 sensor (like acceleration and tilt), and on the robot side, I mapped that data to motor movements. The wireless part using ESP-NOW was tricky at first — I had to experiment with timing and data formats to make the communication smooth. After some testing and debugging, it started working as expected.

## Week 4 – Documentation and Wrap-up

Once the robot was moving based on hand gestures, I finalized the code and created a basic schematic to show how I wired it. I wrote a short project report (final_project_report.pdf) and added a README with all the details. I also created this journal to document how I built everything from scratch.

Then I submitted the project through a pull request to the Hack Club Highway repo and posted about it in the #highway Slack channel.

---

This was a great learning experience. I got to explore ESP-NOW in depth and build something I had never tried before. Thank you Hack Club for the opportunity and support!

