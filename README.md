#  Arduino Motor Control & Obstacle Detection

> An Arduino-based control system designed to control four DC motors and detect obstacles using an HC-SR04 ultrasonic sensor and an SG90 servo motor.

---

##  Project Overview

This project is divided into two main parts:

- **Part 1:** Four DC motor movement control using L293D motor drivers.
- **Part 2:** Obstacle detection and response using an ultrasonic sensor and servo motor.

---

#  Part 1 — DC Motor Control

Four DC motors are programmed to perform a specific movement sequence:

- ⬆️ **Forward:** 30 seconds
- ⬇️ **Backward:** 60 seconds
- ➡️ **Right:** 30 seconds
- ⬅️ **Left:** 30 seconds

The movement sequence repeats automatically.

###  Demonstration





https://github.com/user-attachments/assets/d23ef988-9a66-4122-9df1-d4b0b46592b9



---

#  Part 2 — Obstacle Detection

An **HC-SR04 ultrasonic sensor** continuously measures the distance in front of the system.

When an obstacle is detected at **10 cm or less**:

-  The four motors stop immediately.
-  The SG90 servo scans the area from right to left.
-  The servo returns to the center position.
-  The motors move backward for 2 seconds.
-  The motors stop.

### 📡 HC-SR04 Ultrasonic Sensor

The **HC-SR04 ultrasonic sensor** is responsible for detecting obstacles by measuring the distance between the system and the object in front of it.

<img width="709" height="568" alt="HC-SR04 Pinout" src="https://github.com/user-attachments/assets/b0904857-c1a2-4aa4-a13f-fa550d42de13" />

### 🎥 Demonstration




https://github.com/user-attachments/assets/8ff3aa79-0307-4a2b-8a20-7a2a1f7c2a7d




---

##  Components

- Arduino UNO
- L293D Motor Driver ×2
- DC Motor ×4
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- Breadboard
- 9V Battery
- Jumper Wires

---

## ⚙️ Technologies

- Arduino C/C++
- Arduino Servo Library
- Tinkercad Circuits

---

##  Project Objectives

- Control four DC motors using L293D motor drivers.
- Implement programmed movement sequences.
- Detect obstacles using an ultrasonic sensor.
- Control a servo motor for obstacle scanning.
- Automatically stop and reverse the motors when an obstacle is detected.
- Simulate and test the system using Tinkercad.

---

##  Tinkercad Simulation

https://www.tinkercad.com/things/8X98jASBM8T/editel?returnTo=%2Fdashboard
---

##  Project Files

```text
Arduino-Motor-Control-and-Obstacle-Detection/
│
├── Arduino-Motor-Control.ino
├── README.md
│
├── images/
│   └── HC-SR04.png
│
└── videos/
    ├── Part1-Motor-Control.mp4
    └── Part2-Obstacle-Detection.mp4
