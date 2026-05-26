# ESP32 Pin Mapping for Automated Grow Chamber

This file describes the ESP32 pin connections used in the automated grow chamber firmware.

## Control board

| Item | Description |
|---|---|
| Microcontroller | ESP32 development board |
| Firmware file | `esp32_control.ino` |
| Programming environment | Arduino IDE / PlatformIO |
| Serial baud rate | 115200 |

---

## Sensor pin mapping

| Component | Signal | ESP32 pin | Notes |
|---|---|---|---|
| DHT11 temperature-humidity sensor | VCC | 3.3 V / 5 V | Use according to sensor module rating |
| DHT11 temperature-humidity sensor | GND | GND | Common ground |
| DHT11 temperature-humidity sensor | DATA | GPIO 4 | Digital data pin |
| Soil moisture sensor | VCC | 3.3 V / 5 V | Use according to sensor module rating |
| Soil moisture sensor | GND | GND | Common ground |
| Soil moisture sensor | Analog output | GPIO 34 | ADC input pin |

---

## Relay pin mapping

| Output device | Relay channel | ESP32 GPIO pin | Purpose |
|---|---|---:|---|
| Grow Light 1 | Relay channel 1 | GPIO 16 | Switch Grow Light 1 |
| Grow Light 2 | Relay channel 2 | GPIO 17 | Switch Grow Light 2 |
| Peristaltic Pump 1 | Relay channel 3 | GPIO 18 | Pump water / treatment solution 1 |
| Peristaltic Pump 2 | Relay channel 4 | GPIO 19 | Pump treatment solution 2 |
| Peristaltic Pump 3 | Relay channel 5 | GPIO 21 | Pump treatment solution 3 |
| Peristaltic Pump 4 | Relay channel 6 | GPIO 22 | Pump treatment solution 4 |
| Exhaust Fan | Relay channel 7 | GPIO 23 | Switch air-circulation fan |

---

## Relay logic

Many low-cost relay modules are active LOW.

| Relay state | GPIO output for active-LOW relay |
|---|---|
| Relay ON | LOW |
| Relay OFF | HIGH |

In the firmware, this is controlled using:

```cpp
#define RELAY_ACTIVE_LOW true


If your relay module is active HIGH, change it to:

#define RELAY_ACTIVE_LOW false



Power notes
Component	Recommended supply
ESP32	USB / regulated 5 V
DHT11 sensor	3.3 V or 5 V depending on module
Soil moisture sensor	3.3 V or 5 V depending on module
Relay module			5 V
Raspberry Pi	Stable 5 V supply
Grow lights		According to selected module rating
Peristaltic pumps	Usually 12 V DC
Exhaust fan	5 V or 12 V DC depending on selected fan

Grow lights	According to selected module rating
Peristaltic pumps	Usually 12 V DC
Exhaust fan	5 V or 12 V DC depending on selected fan

Safety notes
Keep ESP32, Raspberry Pi, relay modules, and power adapters away from water and tubing outlets.
Use common ground where required for reliable control signals. Peristaltic pumps and exhaust fans are inductive loads.
Use relay modules with driver circuitry and flyback protection.
If bare relay circuits are used, add flyback diodes across motor terminals.
Check all wiring before powering the system.
Do not touch live wiring during operation.

