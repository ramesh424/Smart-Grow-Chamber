# Assembly Guide

## Open-Source Automated Grow Chamber for Seed Germination Monitoring

This document provides step-by-step assembly instructions for building the automated grow chamber. The system includes a transparent chamber enclosure, ESP32-based sensing and relay control, Raspberry Pi camera imaging, grow lights, exhaust fan, peristaltic pumps, liquid reservoirs, tubing, and a germination tray.

---

## 1. Required Components

| Component | Quantity | Purpose |
|---|---:|---|
| Transparent plastic/acrylic chamber | 1 | Main enclosure |
| Germination tray | 1 | Seed placement |
| ESP32 development board | 1 | Sensor reading and actuator control |
| DHT11 temperature-humidity sensor | 1 | Chamber temperature and humidity monitoring |
| Soil moisture sensor | 1 | Moisture monitoring near germination medium |
| Raspberry Pi board | 1 | Image acquisition and processing |
| Raspberry Pi camera module | 1 | Seed-tray image capture |
| Relay module | 1 set | Switching grow lights, pumps, and exhaust fan |
| LED grow lights | 2 | Artificial illumination |
| Peristaltic pumps | 4 | Liquid or treatment-solution delivery |
| Exhaust fan | 1 | Air circulation |
| Liquid reservoirs | 4 | Water or treatment solutions |
| Flexible tubing | 1 set | Fluid delivery |
| Jumper wires/connectors | As required | Electrical connections |
| Power supply adapters | As required | Power for controller, Raspberry Pi, lights, pumps, and fan |
| Mounting accessories | As required | Fixing components |

---

## 2. Tools Required

- Screwdriver
- Cutter or drill for small cable/tube openings
- Hot glue gun or adhesive tape
- Cable ties
- Measuring scale
- Marker pen
- Multimeter
- Laptop with Arduino IDE or PlatformIO
- Raspberry Pi OS setup

---

## 3. Chamber Preparation

1. Select a transparent plastic or acrylic enclosure large enough to hold the germination tray, lights, camera field of view, sensors, and tubing.
2. Clean the inside surface of the chamber.
3. Mark the position of the germination tray at the bottom center of the chamber.
4. Create small openings on the side or rear wall for routing:
   - sensor wires,
   - relay wires,
   - power cables,
   - liquid-delivery tubes.
5. Create an additional side-wall opening for mounting the exhaust fan.
6. Seal unused gaps using tape, silicone sealant, or removable rubber grommets.

---

## 4. Germination Tray Placement

1. Place the germination tray at the marked position inside the chamber.
2. Ensure the tray is flat and stable.
3. If multiple treatment groups are used, divide the tray into labelled regions.
4. Use a background that provides good contrast between seeds, roots, and the tray surface.
5. Mark the tray position so that it can be placed in the same location after cleaning.

---

## 5. Grow-Light Installation

1. Mount two LED grow lights on the upper or side wall of the chamber.
2. Position the lights symmetrically above the germination tray.
3. Avoid direct glare into the Raspberry Pi camera.
4. Route the grow-light wires outside the chamber.
5. Connect the grow-light supply line through the relay output terminals.
6. Test each light individually before starting the biological experiment.

---

## 6. Raspberry Pi Camera Mounting

1. Mount the Raspberry Pi camera above the germination tray.
2. Keep the camera lens perpendicular to the tray surface.
3. Fix the camera using a rigid mount, bracket, or adhesive support.
4. Capture a test image to confirm:
   - full tray visibility,
   - good focus,
   - proper lighting,
   - no major glare,
   - no obstruction from wires or tubes.
5. Once the field of view is correct, tighten or fix the camera mount.

---

## 7. Liquid Reservoir and Pump Installation

1. Place four liquid reservoirs outside or beside the chamber.
2. Label the reservoirs clearly, for example:
   - Water,
   - 5 g/L salt solution,
   - 10 g/L salt solution,
   - 15 g/L salt solution.
3. Connect each reservoir to one peristaltic pump using inlet tubing.
4. Route each pump outlet tube into the chamber.
5. Position each tube outlet near the assigned tray region.
6. Fix tube ends using tape, clips, or small holders.
7. Flush each tube line with clean water before use.
8. Confirm that there are no leaks, blockages, or incorrect tube connections.

---

## 8. Sensor Installation

### 8.1 DHT11 Temperature-Humidity Sensor

1. Mount the DHT11 sensor inside the chamber.
2. Keep it away from direct water contact.
3. Avoid placing it directly under grow lights to reduce heating error.
4. Connect:
   - VCC to ESP32 3.3 V or 5 V,
   - GND to ESP32 GND,
   - DATA to the assigned ESP32 GPIO pin.

### 8.2 Soil Moisture Sensor

1. Place the soil moisture sensor near the germination medium or tray region.
2. Ensure the sensing part is positioned where moisture variation needs to be monitored.
3. Connect:
   - VCC to ESP32 3.3 V or 5 V,
   - GND to ESP32 GND,
   - analog output to the assigned ESP32 ADC pin.

---

## 9. ESP32 and Relay Module Installation

1. Mount the ESP32 board outside or on the top surface of the chamber.
2. Keep the ESP32 away from moisture, reservoirs, and tube outlets.
3. Mount the relay module near the ESP32 but away from wet areas.
4. Connect ESP32 GPIO pins to relay input pins.
5. Connect relay VCC and GND according to relay module requirements.
6. Connect output devices through relay output terminals:
   - Grow Light 1,
   - Grow Light 2,
   - Peristaltic Pump 1,
   - Peristaltic Pump 2,
   - Peristaltic Pump 3,
   - Peristaltic Pump 4,
   - Exhaust Fan.
7. Use the normally open relay terminal so the device remains OFF when the relay is inactive.

---

## 10. Electrical Wiring Summary

| Connection | From | To | Purpose |
|---|---|---|---|
| DHT11 VCC | DHT11 sensor | ESP32 3.3 V / 5 V | Sensor power |
| DHT11 GND | DHT11 sensor | ESP32 GND | Common ground |
| DHT11 DATA | DHT11 sensor | ESP32 digital GPIO | Temperature-humidity data |
| Soil moisture VCC | Soil moisture sensor | ESP32 3.3 V / 5 V | Sensor power |
| Soil moisture GND | Soil moisture sensor | ESP32 GND | Common ground |
| Soil moisture signal | Soil moisture sensor | ESP32 analog GPIO | Moisture monitoring |
| Relay IN pins | Relay module | ESP32 digital GPIO pins | Relay control |
| Relay VCC/GND | Relay module | 5 V supply and GND | Relay power |
| Grow-light supply | Power supply | Relay output terminal | Light switching |
| Pump supply | Power supply | Relay output terminal | Pump switching |
| Exhaust fan supply | Power supply | Relay output terminal | Fan switching |
| Raspberry Pi camera | Camera module | Raspberry Pi CSI port | Image acquisition |

---

## 11. Power Distribution

1. Use a stable 5 V supply for the Raspberry Pi.
2. Power the ESP32 through USB or regulated 5 V.
3. Power grow lights, peristaltic pumps, and exhaust fan according to their rated voltage.
4. Use separate power lines where required for controller and actuator loads.
5. Share common ground where required for reliable signal reference.
6. Check all wiring using a multimeter before powering the system.

---

## 12. Safety Notes

- Keep electronics away from water and tube outlets.
- Do not touch live wiring during operation.
- Use insulated wires and secure all connections.
- Use relay modules with driver circuitry and flyback protection.
- If bare relay circuits are used, add flyback diodes across motor terminals.
- Do not overload the power supply.
- Ensure that all pumps and fans match the supply voltage.
- If AC-powered lighting is used, keep AC wiring enclosed and insulated.

---

## 13. Firmware Upload

1. Open `firmware/esp32_control/esp32_control.ino` in Arduino IDE or PlatformIO.
2. Select the correct ESP32 board.
3. Select the correct serial port.
4. Install required libraries:
   - DHT sensor library,
   - Adafruit Unified Sensor.
5. Upload the firmware.
6. Open the Serial Monitor at 115200 baud.
7. Check:
   - temperature reading,
   - humidity reading,
   - soil moisture reading,
   - relay switching status.

---

## 14. Raspberry Pi Camera Setup

1. Install Raspberry Pi OS.
2. Connect the camera module to the Raspberry Pi CSI port.
3. Enable the camera interface if required.
4. Install required packages.
5. Run the image capture script:

```bash
python3 image_capture.py
