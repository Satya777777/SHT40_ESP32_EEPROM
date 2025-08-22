SHT40 with EEPROM on ESP32

This project demonstrates how to interface the SHT40 Temperature and Humidity sensor with an ESP32, and store calibration/threshold data into the EEPROM for non-volatile memory usage. The project is useful for data logging, IoT applications, and sensor calibration persistence.

Features

Reads temperature and humidity values from the SHT40 sensor.

Stores and retrieves sensor-related data from EEPROM.

Ensures that data is preserved even after power cycles.

Displays real-time data on the Serial Monitor.

Hardware Requirements

ESP32 development board

SHT40 temperature & humidity sensor (I2C interface)

Jumper wires

Breadboard (optional)

Circuit Connections
ESP32 Pin	SHT40 Pin
3.3V	VCC
GND	GND
GPIO 21	SDA
GPIO 22	SCL

(Default I2C pins on ESP32: SDA = GPIO21, SCL = GPIO22. Modify in code if needed.)

Software Requirements

Arduino IDE

ESP32 board support installed in Arduino IDE

Required libraries:

Adafruit_SHT4x

EEPROM (comes preinstalled with ESP32 core)

To install the SHT4x library:

Open Arduino IDE

Go to Sketch > Include Library > Manage Libraries

Search for Adafruit SHT4x and install

Usage

Connect the ESP32 and SHT40 as per the circuit diagram.

Open the code file SHT40_EEPROM.ino in Arduino IDE.

Select the correct Board (ESP32 Dev Module) and COM port.

Upload the code.

Open Serial Monitor at 115200 baud to view readings.

EEPROM Functionality

On the first run, default calibration/threshold values are written to EEPROM.

On subsequent runs, stored values are retrieved from EEPROM automatically.

This ensures persistence of configuration across resets or power loss.

Example Serial Output
SHT40 EEPROM Demo
Temperature: 28.4 °C
Humidity: 62.1 %
Stored Threshold: 30 °C, 65 %

Applications

Weather monitoring stations

Smart agriculture (soil and environment monitoring)

Smart home (HVAC control)

Cold chain / warehouse monitoring

License

This project is open-source and available under the MIT License.