/*
  esp32_control.ino

  Firmware for Open-Source Automated Grow Chamber

  Functions:
  - Reads DHT11 temperature and humidity sensor
  - Reads soil moisture sensor
  - Controls grow lights, exhaust fan, and four peristaltic pumps using relay modules
  - Prints sensor and actuator status to Serial Monitor

  Board:
  ESP32 Development Board

  Required library:
  - DHT sensor library by Adafruit
  - Adafruit Unified Sensor
*/

#include <DHT.h>

// =========================
// Sensor configuration
// =========================

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

#define SOIL_MOISTURE_PIN 34   // Analog input pin

// =========================
// Relay pin configuration
// =========================

#define RELAY_GROW_LIGHT_1  16
#define RELAY_GROW_LIGHT_2  17
#define RELAY_PUMP_1        18
#define RELAY_PUMP_2        19
#define RELAY_PUMP_3        21
#define RELAY_PUMP_4        22
#define RELAY_EXHAUST_FAN   23

// =========================
// Relay logic configuration
// =========================

// Many relay modules are active LOW.
// If your relay turns ON when GPIO is LOW, keep this as true.
// If your relay turns ON when GPIO is HIGH, change this to false.

#define RELAY_ACTIVE_LOW true

// =========================
// Timing configuration
// =========================

unsigned long previousSensorReadTime = 0;
const unsigned long sensorReadInterval = 5000;   // 5 seconds

// Example actuator timing
const unsigned long pumpRunTime = 5000;          // 5 seconds
const unsigned long fanRunTime = 10000;          // 10 seconds

// =========================
// Helper functions
// =========================

void relayOn(int relayPin) {
  if (RELAY_ACTIVE_LOW) {
    digitalWrite(relayPin, LOW);
  } else {
    digitalWrite(relayPin, HIGH);
  }
}

void relayOff(int relayPin) {
  if (RELAY_ACTIVE_LOW) {
    digitalWrite(relayPin, HIGH);
  } else {
    digitalWrite(relayPin, LOW);
  }
}

void allRelaysOff() {
  relayOff(RELAY_GROW_LIGHT_1);
  relayOff(RELAY_GROW_LIGHT_2);
  relayOff(RELAY_PUMP_1);
  relayOff(RELAY_PUMP_2);
  relayOff(RELAY_PUMP_3);
  relayOff(RELAY_PUMP_4);
  relayOff(RELAY_EXHAUST_FAN);
}

void setupRelayPins() {
  pinMode(RELAY_GROW_LIGHT_1, OUTPUT);
  pinMode(RELAY_GROW_LIGHT_2, OUTPUT);
  pinMode(RELAY_PUMP_1, OUTPUT);
  pinMode(RELAY_PUMP_2, OUTPUT);
  pinMode(RELAY_PUMP_3, OUTPUT);
  pinMode(RELAY_PUMP_4, OUTPUT);
  pinMode(RELAY_EXHAUST_FAN, OUTPUT);

  allRelaysOff();
}

void readSensors() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int soilMoistureRaw = analogRead(SOIL_MOISTURE_PIN);

  Serial.println("====================================");

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT11 reading failed.");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %RH");
  }

  Serial.print("Soil moisture raw ADC value: ");
  Serial.println(soilMoistureRaw);

  Serial.println("====================================");
}

void testActuatorsOnce() {
  Serial.println("Testing Grow Light 1...");
  relayOn(RELAY_GROW_LIGHT_1);
  delay(2000);
  relayOff(RELAY_GROW_LIGHT_1);

  Serial.println("Testing Grow Light 2...");
  relayOn(RELAY_GROW_LIGHT_2);
  delay(2000);
  relayOff(RELAY_GROW_LIGHT_2);

  Serial.println("Testing Exhaust Fan...");
  relayOn(RELAY_EXHAUST_FAN);
  delay(3000);
  relayOff(RELAY_EXHAUST_FAN);

  Serial.println("Testing Pump 1...");
  relayOn(RELAY_PUMP_1);
  delay(2000);
  relayOff(RELAY_PUMP_1);

  Serial.println("Testing Pump 2...");
  relayOn(RELAY_PUMP_2);
  delay(2000);
  relayOff(RELAY_PUMP_2);

  Serial.println("Testing Pump 3...");
  relayOn(RELAY_PUMP_3);
  delay(2000);
  relayOff(RELAY_PUMP_3);

  Serial.println("Testing Pump 4...");
  relayOn(RELAY_PUMP_4);
  delay(2000);
  relayOff(RELAY_PUMP_4);

  Serial.println("Actuator test completed.");
}

// =========================
// Setup
// =========================

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Automated Grow Chamber ESP32 Control Started");

  dht.begin();

  pinMode(SOIL_MOISTURE_PIN, INPUT);

  setupRelayPins();

  // Run once during startup to confirm relay mapping.
  // Comment this line before long experiments if not needed.
  testActuatorsOnce();
}

// =========================
// Loop
// =========================

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - previousSensorReadTime >= sensorReadInterval) {
    previousSensorReadTime = currentTime;
    readSensors();
  }

  /*
    Example manual control logic:

    Uncomment these lines only if you want automatic periodic operation.

    relayOn(RELAY_GROW_LIGHT_1);
    relayOn(RELAY_GROW_LIGHT_2);

    relayOn(RELAY_EXHAUST_FAN);
    delay(fanRunTime);
    relayOff(RELAY_EXHAUST_FAN);

    relayOn(RELAY_PUMP_1);
    delay(pumpRunTime);
    relayOff(RELAY_PUMP_1);
  */
}