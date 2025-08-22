
#include <EEPROM.h>
#include <Wire.h>
#include <SensirionI2cSht4x.h>

// Constants
const int EEPROM_SIZE = 512;
const int INTERVAL = 10000; // Interval for measurements (milliseconds)

// Global variables
unsigned long previousMillis = 0;
SensirionI2cSht4x sensor;
static char errorMessage[64];
static int16_t error;

// Structure for sensor data
struct SensorData {
  unsigned long timestamp;
  float aTemperature;
  float aHumidity;
};

void setup() {
  Serial.begin(115200);
  Wire.begin();
  sensor.begin(Wire, SHT40_I2C_ADDR_44);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= INTERVAL) {
    previousMillis = currentMillis;
    float aTemperature = 0.0;
    float aHumidity = 0.0;
    delay(20);
    error = sensor.measureLowestPrecision(aTemperature, aHumidity);
    if (error != NO_ERROR) {
      Serial.print("Error trying to execute measureLowestPrecision(): ");
      errorToString(error, errorMessage, sizeof errorMessage);
      Serial.println(errorMessage);
      return;
    }
    writeDataToEEPROM(currentMillis, aTemperature, aHumidity);
  }
}

void writeDataToEEPROM(unsigned long timestamp, float aTemperature, float aHumidity) {
  int addr = 0;
  SensorData data;
  data.timestamp = timestamp;
  data.aTemperature = aTemperature;
  data.aHumidity = aHumidity;
  EEPROM.put(addr, data);
  addr += sizeof(SensorData);
  EEPROM.commit();
}

void readDataFromEEPROM() {
  int addr = 0;
  SensorData data;

  while (addr < EEPROM_SIZE) {
    EEPROM.get(addr, data);
    Serial.print("Timestamp: ");
    Serial.print(data.timestamp);
    Serial.print(", Temperature: ");
    Serial.print(data.aTemperature);
    Serial.print(", Humidity: ");
    Serial.println(data.aHumidity);
    addr += sizeof(SensorData);
  }
}
