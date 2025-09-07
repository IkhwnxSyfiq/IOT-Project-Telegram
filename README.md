# 🌧️ ESP32 Water Level & Rain Detection with Telegram Alerts

This project uses an **ESP32**, a **float sensor**, and a **rain sensor** to monitor water levels and rain conditions in real time.  
Alerts are sent directly to a **Telegram Bot**, so you can monitor the situation from your phone.

---

## 🚀 Features
- Connects ESP32 to WiFi.
- Monitors **water level** using a float sensor.
- Monitors **rain condition** using a rain sensor (digital/analogue output).
- Sends **real-time alerts** to a Telegram chat using a bot.
- Provides different alert messages depending on the condition.

---

## 🛠️ Hardware Requirements
- ESP32 board  
- Float sensor (connected to GPIO4)  
- Rain sensor module (connected to GPIO34 & GPIO35)  
- WiFi connection  
- Telegram Bot (via [BotFather](https://core.telegram.org/bots#botfather))  

---

## 📡 Wiring
| Sensor          | ESP32 Pin |
|-----------------|-----------|
| Float Sensor    | GPIO4     |
| Rain Sensor OUT (digital) | GPIO34 |
| Rain Sensor OUT (analogue)  | GPIO35 |

---

## ⚙️ Setup Instructions
1. **Get Telegram Bot Token**
   - Open Telegram, search for **BotFather**, and create a new bot.
   - Copy the **Bot Token** provided.

2. **Get Your Chat ID**
   - Start a chat with **@userinfobot** on Telegram.
   - Copy your Chat ID.

3. **Update WiFi Credentials**
   - Open the code and update:
     ```cpp
     const char* ssid = "YourWiFiName";
     const char* password = "YourWiFiPassword";
     ```

4. **Update Telegram Bot Token & Chat ID**
   ```cpp
   #define BOTtoken "YOUR_BOT_TOKEN"
   #define CHAT_ID "YOUR_CHAT_ID"
