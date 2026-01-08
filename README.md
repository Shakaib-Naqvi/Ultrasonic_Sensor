# ESP32 Water Level Monitoring with Blynk

This project uses an **ESP32**, an **ultrasonic sensor (HC-SR04)**, and **Blynk IoT** to monitor water level in a tank and display it on a mobile dashboard.

---

## Features
- Connects to **multiple Wi-Fi networks** (fallback supported)
- Measures **water level using ultrasonic sensor**
- Sends real-time water level data to **Blynk Cloud**
- Displays water level on **Blynk Virtual Pin (V7)**
- Serial monitoring for debugging

---

## Hardware Required
- ESP32 Development Board  
- Ultrasonic Sensor (HC-SR04 or equivalent)  
- Jumper Wires  
- Water Tank  

---

## Pin Configuration
| Component        | ESP32 Pin |
|------------------|----------|
| Ultrasonic TRIG  | GPIO 12  |
| Ultrasonic ECHO  | GPIO 27  |

---

## Blynk Configuration
- **Template Name:** Home Automation  
- **Virtual Pin:** V7 (Water Level Display)  
- **Connection:** blynk.cloud (Port 80)

 Keep your **Blynk Auth Token private** in production projects.

---

## Tank Settings
- **Tank Height:** `250 cm` (modifiable in code)

---

## ⚙️ How It Works
1. ESP32 connects to the first available Wi-Fi network.
2. Ultrasonic sensor measures distance from water surface.
3. Water level is calculated as:
   ` Water Level = Tank Height - Measured Distance `
4. Data is sent to Blynk using a virtual pin.
5. Values are updated in real time on the Blynk app.

---

## Libraries Used
- `WiFi.h`
- `WiFiClient.h`
- `BlynkSimpleEsp32.h`

---

## Notes & Improvements
- Avoid calling `UltrasonicSensor()` inside `loop()` when using `BlynkTimer`
- Add timeout to `pulseIn()` to prevent blocking
- Secure Wi-Fi and Blynk credentials using environment variables

---

## License
This project is for educational and personal use.

---

Happy Building!

