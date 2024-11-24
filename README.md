# SmartCare Diabetes

## Overview
This project is a smart bracelet that monitors heart rate, oxygen saturation, temperature, and sends this data via SMS to caregivers using an ESP32 microcontroller, MAX30102 sensor, DS18B20 temperature sensor, and an OLED display. When caregivers respond via SMS, the data is displayed on the OLED screen.

---

## Components Required
- **ESP32 Development Board**
- **MAX30102 Pulse Oximeter and Heart Rate Sensor**
- **DS18B20 Temperature Sensor**
- **OLED Display (e.g., 128x64 I2C OLED)**
- **GSM Module (e.g., SIM800L, SIM900)**
- **2 x 26650 Li-Ion Rechargeable Batteries (3.7V, 3000mAh each, Total: 6000mAh)**
- **Battery Management System (BMS)**
- **Jumper wires and Breadboard**
- **Resistors (for DS18B20 and MAX30102 connections)**

---

## Libraries Required
You will need to install the following libraries for your project:

1. **Adafruit MAX30105** (For MAX30102 sensor)
   - Install: `Sketch > Include Library > Manage Libraries`, search for "Adafruit MAX30105" and install it.

2. **OneWire** (For DS18B20 sensor)
   - Install: `Sketch > Include Library > Manage Libraries`, search for "OneWire" and install it.

3. **DallasTemperature** (For DS18B20 sensor)
   - Install: `Sketch > Include Library > Manage Libraries`, search for "DallasTemperature" and install it.

4. **Adafruit SSD1306** (For OLED Display)
   - Install: `Sketch > Include Library > Manage Libraries`, search for "Adafruit SSD1306" and install it.

5. **SoftwareSerial** (For GSM module communication, if not already available)
   - This is typically included by default in Arduino IDE.

6. **TinyGsmClient** (For GSM communication)
   - Install: `Sketch > Include Library > Manage Libraries`, search for "TinyGsmClient" and install it.

---

## Setting Up ESP32 in Arduino IDE

To use the ESP32 in Arduino IDE, follow these steps:

1. **Install the ESP32 Board Manager URL:**
   - Open Arduino IDE.
   - Go to `File > Preferences`.
   - In the "Additional Boards Manager URLs" field, add the following URL:
     ```
     https://dl.espressif.com/dl/package_esp32_index.json
     ```

2. **Install ESP32 Board:**
   - Go to `Tools > Board > Boards Manager`.
   - Search for `esp32` and click "Install" to add the ESP32 boards to your IDE.

3. **Select the Correct Board and Port:**
   - Go to `Tools > Board` and select `ESP32 Dev Module` (or your specific ESP32 model).
   - Go to `Tools > Port` and select the appropriate COM port for your ESP32.

---

## Wiring Diagram

Here is the wiring configuration for the components:

#### MAX30102 (Pulse Oximeter and Heart Rate Sensor)
| MAX30102 Pin     | ESP32 Pin  |
|------------------|------------|
| VCC              | 3.3V       |
| GND              | GND        |
| SDA              | GPIO 21    |
| SCL              | GPIO 22    |

#### DS18B20 (Temperature Sensor)
| DS18B20 Pin      | ESP32 Pin  |
|------------------|------------|
| VCC              | 3.3V       |
| GND              | GND        |
| Data             | GPIO 17    |
| Resistor (4.7kΩ) | Between Data and VCC |

#### OLED Display (128x64 I2C)
| OLED Pin         | ESP32 Pin  |
|------------------|------------|
| VCC              | 3.3V       |
| GND              | GND        |
| SDA              | GPIO 21    |
| SCL              | GPIO 22    |

#### GSM Module (e.g., SIM800L)
| GSM Pin          | ESP32 Pin  |
|------------------|------------|
| VCC              | 5V         |
| GND              | GND        |
| TX               | GPIO 16    |
| RX               | GPIO 17    |

#### Battery and BMS
| BMS Pin          | ESP32 Pin  |
|------------------|------------|
| VCC              | 5V         |
| GND              | GND        |

---

## Power Consumption
To estimate the runtime of the project with a combined 6000mAh battery capacity, we calculated the total current draw of all components.

### Current Draw of Components
- **ESP32**: ~80mA (average)
- **GSM Module**: ~200mA (average, can spike up to 2A during transmission)
- **MAX30102**: ~10mA (average)
- **DS18B20**: ~1mA (average)
- **OLED Display**: ~20mA (average)

### Total Average Current
\[ \text{Total average current} = 80mA (ESP32) + 200mA (GSM) + 10mA (MAX30102) + 1mA (DS18B20) + 20mA (OLED) = 311mA \]

### Combined Battery Capacity
\[ \text{Battery capacity} = 6000mAh \]

### Estimated Runtime
To find the runtime:
\[ \text{Runtime (hours)} = \frac{\text{Battery capacity (mAh)}}{\text{Total average current (mA)}} \]
\[ \text{Runtime} = \frac{6000mAh}{311mA} \approx 19.29 \text{ hours} \]

With a combined battery capacity of 6000mAh and an average current draw of 311mA, the project is estimated to run for approximately 19.29 hours. This is a theoretical estimate, and actual runtime may vary based on real-world factors such as peak current draws, battery health, and efficiency of the power management in the circuit.

---

## Power Management

1. **Battery Considerations:**
   - The **26650 Li-Ion** batteries with a **BMS** are responsible for powering the ESP32 and sensors.
   - Ensure the **BMS** is properly managing the charging and discharging of the batteries to prevent damage.
   - Consider adding a low battery detection system to avoid power loss.

---

## Conclusion

This project combines the ESP32's capabilities with multiple sensors to create a smart bracelet that monitors vital signs and sends updates to caregivers via SMS. The data is displayed on the OLED screen in real-time, ensuring that caregivers can always stay informed.

---

## License

This project is licensed under the MIT License.


