# 💧 Water Level Detector Using Arduino

## 📌 Project Overview

* This project is an **Arduino-based water level detection system**.
* An **HC-SR04 ultrasonic sensor** is used to measure the distance between the sensor and the water surface.
* The ultrasonic sensor is mounted above the water container/tank.
* The sensor sends ultrasonic waves toward the water surface and receives the reflected waves.
* Arduino calculates the distance between the sensor and the water surface.
* The measured distance is used to determine the approximate **water level** inside the container.
* The system can be used to monitor water levels without requiring the sensor to be in direct contact with the water.

---

## 🧰 Components Required

* Arduino Uno
* HC-SR04 Ultrasonic Sensor
* LED / Indicator
* Resistor (typically 220Ω for LED)
* Breadboard
* Jumper wires
* USB cable
* Water container/tank

---

## 🔌 Connections

### HC-SR04 → Arduino Uno

| HC-SR04 Pin | Arduino Uno    |
| ----------- | -------------- |
| VCC         | 5V             |
| GND         | GND            |
| TRIG        | Digital Pin 9  |
| ECHO        | Digital Pin 10 |

### LED → Arduino Uno

| LED Pin     | Arduino Uno                     |
| ----------- | ------------------------------- |
| Anode (+)   | Digital Pin 13 through resistor |
| Cathode (-) | GND                             |

> The LED can be used as a basic indication of the detected water level. The exact indication logic can be modified in the Arduino program.

---

## ⚙️ Working Principle

* The HC-SR04 ultrasonic sensor is positioned above the water surface.
* Arduino sends a short trigger pulse to the **TRIG pin** of the ultrasonic sensor.
* The HC-SR04 emits an ultrasonic sound wave toward the water surface.
* The ultrasonic wave reflects from the water surface and returns to the sensor.
* The sensor generates a signal on the **ECHO pin**.
* Arduino measures the duration for which the ECHO signal remains HIGH.
* This time represents the round-trip travel time of the ultrasonic wave.
* Arduino converts the measured time into distance.
* Since the sensor is mounted at a known height above the bottom of the container, the water level can be calculated from the measured distance.

---

## 📐 Water Level Calculation

Let:

```text
Tank Height = H
Distance from sensor to water surface = D
```

Then:

```text
Water Level = H - D
```

### Example

If:

```text
Tank Height = 30 cm
Distance from sensor to water surface = 10 cm
```

Then:

```text
Water Level = 30 - 10
            = 20 cm
```

Therefore, approximately **20 cm of the tank contains water**.

---

## 🔄 Complete Working Flow

```text
              START
                ↓
        Initialize Arduino
                ↓
      Initialize Ultrasonic
             Sensor
                ↓
        Send Trigger Pulse
                ↓
      Ultrasonic Wave Sent
                ↓
        Water Surface
                ↓
      Echo Wave Received
                ↓
       Measure Echo Time
                ↓
       Calculate Distance
                ↓
    Calculate Water Level
                ↓
       Display / Indicate
        Water Level
                ↓
       Repeat Continuously
```

---

## 🧠 Program Working

* Arduino configures the **TRIG pin as OUTPUT** and the **ECHO pin as INPUT**.
* The sensor measurement starts by setting the TRIG pin HIGH for approximately 10 microseconds.
* The HC-SR04 sends an ultrasonic pulse toward the water surface.
* `pulseIn()` is used to measure the duration of the returning ECHO signal.
* The measured time is converted into distance using the speed of sound.
* The distance between the sensor and water surface is obtained.
* The water level is calculated by subtracting this distance from the known tank height.
* The calculated water level can then be used to control an LED, display, buzzer, or other output.
* The process repeats continuously so that changes in the water level can be monitored in real time.

---

## 📊 Example

Assume the sensor is mounted **30 cm above the bottom of the tank**.

| Distance to Water | Calculated Water Level | Condition  |
| ----------------: | ---------------------: | ---------- |
|             25 cm |                   5 cm | Low        |
|             20 cm |                  10 cm | Low/Medium |
|             15 cm |                  15 cm | Medium     |
|             10 cm |                  20 cm | High       |
|              5 cm |                  25 cm | Very High  |

> The actual level thresholds can be changed according to the size of the container and project requirements.

---

## 📡 Distance Measurement

The HC-SR04 determines distance using the time taken by the ultrasonic wave to travel to the water surface and return.

```text
Distance = (Time × Speed of Sound) / 2
```

The division by **2** is required because the measured time represents:

```text
Sensor → Water Surface
       +
Water Surface → Sensor
```

---

## 🛠️ Main Concepts Used

* Arduino Uno
* Embedded C/C++
* Ultrasonic sensing
* Digital input/output
* GPIO
* Time-of-flight measurement
* `digitalWrite()`
* `pulseIn()`
* Distance calculation
* Conditional statements
* Sensor interfacing
* Real-time monitoring

---

## 🎯 Applications

* Water tank level monitoring
* Household water storage monitoring
* Overhead tank monitoring
* Automatic water management systems
* Industrial liquid-level monitoring prototypes
* Smart-home projects
* IoT-based water monitoring systems

---

## 🚀 Future Improvements

The project can be extended by:

* Adding an **LCD/OLED display** to show the water level.
* Adding a **buzzer** when the water level becomes too low or too high.
* Adding multiple LEDs for different water-level ranges.
* Adding a **relay and pump-control system** for automatic water filling.
* Using an **ESP32** to monitor the water level remotely through Wi-Fi.
* Sending notifications when the tank reaches a predefined level.
* Calculating the water level as a **percentage**.
* Adding data logging to monitor water consumption over time.

---

