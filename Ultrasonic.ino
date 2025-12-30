#define BLYNK_TEMPLATE_ID "TMPL6jbl3KWKU"
#define BLYNK_TEMPLATE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "4O-2eQ4XBM7lMHUri9f6sArMMdqTXzmO"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Blynk authentication token

char auth[] = BLYNK_AUTH_TOKEN;

char ssid1[] = "Infinix Smart 3 Plus";  // type your wifi name
char pass1[] = "Shakaibnaqvi";          // type your wifi password

char ssid2[] = "R28 TRANSWORLD NET";  // type your wifi name
char pass2[] = "16507203";            // type your wifi password

char ssid3[] = "R28 TRANSWORLD NET";  // type your wifi name
char pass3[] = "16507203";            // type your wifi password

BlynkTimer timer;

int tank_height = 250;  //in centimeter

#define VPIN_ULTRASONIC V7
#define TRIG 12
#define ECHO 27


bool connectToWiFi(const char* ssid, const char* password) {
  Serial.print("Connecting to Wi-Fi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  int retries = 0;
  while (!WiFi.isConnected() && retries < 10) {
    delay(1000);
    retries++;
  }
  if (WiFi.isConnected()) {
    Serial.println("Connected to Wi-Fi");
    return true;
  } else {
    Serial.println("Failed to connect to Wi-Fi");
    return false;
  }
}

void setup() {
  Serial.begin(115200);

  if (connectToWiFi(ssid1, pass1)) {
    Blynk.config(auth, "blynk.cloud", 80);
    Blynk.connect();
    if (Blynk.connected()) {
      Serial.println("Connected to Wi-Fi 1 and Blynk");
      // Additional code for Blynk or other operations
    }
  } else if (connectToWiFi(ssid2, pass2)) {
    Blynk.config(auth, "blynk.cloud", 80);
    Blynk.connect();
    if (Blynk.connected()) {
      Serial.println("Connected to Wi-Fi 2 and Blynk");
      // Additional code for Blynk or other operations
    }
  } else if (connectToWiFi(ssid3, pass3)) {
    Blynk.config(auth, "blynk.cloud", 80);
    Blynk.connect();
    if (Blynk.connected()) {
      Serial.println("Connected to Wi-Fi 3 and Blynk");
      // Additional code for Blynk or other operations
    }
  } else {
    Serial.println("Failed to connect to any Wi-Fi network");
    // Additional error handling or fallback actions
  }



  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
  timer.setInterval(100L, UltrasonicSensor);
}

void loop() {
  Blynk.run();  // Run Blynk
  UltrasonicSensor();
}




/****************************************************************************************************
 * UltrasonicSensor Function
*****************************************************************************************************/
void UltrasonicSensor() {
  //--------------------------------------------------
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  //--------------------------------------------------
  long t = pulseIn(ECHO, HIGH);
  long cm = (t * 0.034) / 2;  //SOUND_SPEED = 0.034 i.e. 343m/s
  //--------------------------------------------------
  if (cm <= tank_height) { Blynk.virtualWrite(VPIN_ULTRASONIC, tank_height - cm); }
  //--------------------------------------------------
  delayMicroseconds(100);
  Serial.println("Water Level:"); Serial.println(cm);
  //--------------------------------------------------
}