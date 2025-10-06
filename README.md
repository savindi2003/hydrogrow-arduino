# 🌾 HydroGrow IoT – ESP32 Soil Moisture Sensor Controller

[![Hardware](https://img.shields.io/badge/hardware-ESP32-green)]()
[![Language](https://img.shields.io/badge/language-Arduino%20C%2B%2B-blue)]()
[![Network](https://img.shields.io/badge/communication-WiFi-lightgrey)]()
[![Server](https://img.shields.io/badge/backend-Java-orange)]()

---

## 🌿 Overview

This repository contains the **Arduino sketch** for the HydroGrow IoT device.  
The ESP32 microcontroller reads **soil moisture levels** using a capacitive sensor and transmits the data to the **HydroGrow Java server** over Wi-Fi using HTTP requests.

---

## ⚙️ Features

- 🌱 Reads soil moisture sensor values  
- 📡 Sends data to Java server using HTTP POST  
- 🔁 Sends readings at regular intervals  
- ⚠️ Supports threshold-based alerts  
- 🧩 Easy integration with any backend  

---

## 🧠 Hardware Components

| Component | Description |
|------------|-------------|
| **ESP32** | Wi-Fi microcontroller |
| **Soil Moisture Sensor** | Detects soil water content |
| **Jumper Wires** | Connections |
| **Power Supply** | 5V |

---

## 🔌 Circuit Diagram
 - Soil Sensor → ESP32 (Analog Pin)
 - VCC → 3.3V
 - GND → GND
 - DATA → GPIO34

---

## 🔗 Related Repositories

- React Native mobile app: https://github.com/savindi2003/hydrogrow-app.git
- Java backend for data processing : https://github.com/savindi2003/hydrogrow-server.git

---

## 👩‍💻 Author
**Savindi Duleesha**  
📧 savindiduleesha@gmail.com  
🌐 [Portfolio](https://savindi2003.github.io/my-portfolio/)

---

## 📜 License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

