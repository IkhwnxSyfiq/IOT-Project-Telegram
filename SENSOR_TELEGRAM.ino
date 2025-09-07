#include <WiFi.h> //Wifi library
#include <WiFiClientSecure.h> //WifiClient library
#include <UniversalTelegramBot.h>   // Universal Telegram Bot Library 

//----------------------------------------------------------------------------------------------
// Replace with your network credentials
const char* ssid = "Telegramtest"; //Fill in Wifi Name
const char* password = "11223344"; //Fill in Wifi Password

// Initialize Telegram BOT
#define BOTtoken "6054823198:AAHX93ECasnH-94ZuIuV8dcRgSAyFANo0SY"  // Fill in Bot Token (Get from Botfather)

#define CHAT_ID "796251004" // Fill in IDBot (Get from IDBot) click "start" on a bot before it can message you

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// Checks for new messages every 1 second.
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;

//----------------------------------------------------------------------------------------------
int sw0,sw1,condition; //For Analog Float Sensor 

// Sensor pins
#define sensorPin 4 // GPIO4 connected to the +ve pin Float Sensor 
#define rainAnalog 35 // GIOP35 connected to the control board analog output 
#define rainDigital 34 // GIOP34 connected to the control board digital output 

// Value for storing water level
int val = 0;
int valueAnalog; // declare value for sensor 

void setup() {
  Serial.begin(115200);
//----------------------------------------------------------------------------------------------
    // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
    client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  delay(1000);
  // Print ESP32 Local IP Address
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());
  
  
//-----------------------------------------------------------------------------------------------
  pinMode(rainAnalog,INPUT); // set ESP32 pin to input
  pinMode(rainDigital,INPUT); // set ESP32 pin to input
  sw0 = 0;
  sw1 = 0;
  condition = 0;
}

void loop() {

  int level = (digitalRead(sensorPin));
//  int level = readSensor();
  int rain = (digitalRead(rainDigital));

    sw1 = sw0; // copy previous
    sw0 = condition;
    
    //Serial.println(sw0);//boleh buang 
   // Serial.println(sw1);//boleh buang 
//------------------------------------------------------------------------------------------------

  if ((level == HIGH) && (digitalRead(rainDigital) == LOW)) {
    condition = 1; 
  }

  else if ((level == HIGH) && (digitalRead(rainDigital) == HIGH)) {
    condition = 2;
  }
  
  else if ((level == LOW) && (digitalRead(rainDigital) == LOW)) {
    condition = 3;
  }
  
  else if ((level == LOW) && (digitalRead(rainDigital) == HIGH)) {
    condition = 4;
  }

//-----------------------------------------------------------------------------------------------

 if(sw1 != sw0){
  if (condition == 1){
    bot.sendMessage(CHAT_ID, "low water level but rain detected ", "");
    Serial.println("Water Level: LOW");
    Serial.println("rain detected"); // print rain detected in serial monitor

  }
  else if (condition == 2) {
    bot.sendMessage(CHAT_ID, "low water level but no rain detected ", "");
    Serial.println("Water Level: LOW");
    Serial.println("no rain detected"); // print rain detected in serial monitor

  }
  else if (condition == 3) {
    bot.sendMessage(CHAT_ID, "HIGH WATER LEVEL AND HEAVY RAIN, PLEASE BE AWARE!!!", "");
    Serial.println("Water Level: HIGH");
    Serial.println("rain detected"); // print no rain detected in serial monitor

  }
  else if (condition == 4) {
    bot.sendMessage(CHAT_ID, "low water level but no rain detected", "");
    Serial.println("Water Level: HIGH");
    Serial.println("no rain detected"); // print no rain detected in serial monitor

  }
  }
  
  delay(1000);
}