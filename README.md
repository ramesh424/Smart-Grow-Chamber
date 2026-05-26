# Operation Manual

## Open-Source Automated Grow Chamber for Seed Germination Monitoring

This document explains how to operate the automated grow chamber after assembly. The system supports seed germination monitoring using temperature-humidity sensing, soil moisture monitoring, relay-controlled grow lights, exhaust-fan-based air circulation, peristaltic pump-based liquid delivery, and Raspberry Pi camera-based image acquisition.

---

## 1. System Overview

The grow chamber includes the following operating subsystems:

| Subsystem | Function |
|---|---|
| ESP32 control unit | Reads sensors and switches actuators through relay modules |
| DHT11 temperature-humidity sensor | Records chamber temperature and relative humidity |
| Soil moisture sensor | Records moisture condition near the germination medium |
| Relay modules | Switch grow lights, peristaltic pumps, and exhaust fan |
| Grow lights | Provide artificial illumination |
| Peristaltic pumps | Deliver water or treatment solution to the germination tray |
| Liquid reservoirs | Store water or treatment solutions |
| Exhaust fan | Supports air circulation inside the chamber |
| Raspberry Pi camera | Captures seed-tray images at fixed intervals |
| Germination detection script | Processes captured images and annotates seed status |

---

## 2. Pre-Operation Checklist

Before starting the experiment, check the following:

| Item | Check |
|---|---|
| Chamber enclosure | Clean and dry |
| Germination tray | Properly placed at marked position |
| Camera view | Complete tray visible |
| Grow lights | Switch ON/OFF through relay |
| Exhaust fan | Switches through relay |
| Pumps | Each pump delivers liquid through correct tube |
| DHT11 sensor | Temperature and humidity readings displayed |
| Soil moisture sensor | Moisture readings displayed or logged |
| Tubing | No leakage or blockage |
| Reservoirs | Filled and labelled correctly |
| Raspberry Pi | Camera script runs correctly |
| ESP32 | Firmware uploaded and Serial Monitor working |
| Power supplies | Correct voltage and current ratings used |

---

## 3. Seed Tray Preparation

1. Clean and dry the germination tray.
2. Place the tray inside the chamber at the marked position.
3. Arrange seeds according to the experimental layout.
4. If multiple treatments are used, divide the tray into labelled regions.
5. Use a background that provides good contrast with the seeds and roots.
6. Make sure the seeds are visible from the camera view.
7. Avoid overlapping seeds because it can reduce detection accuracy.

---

## 4. Reservoir and Treatment Preparation

1. Fill the reservoirs with water or treatment solutions.
2. For salinity-stress experiments, prepare separate solutions, for example:
   - Water
   - 5 g/L salt solution
   - 10 g/L salt solution
   - 15 g/L salt solution
3. Label each reservoir clearly.
4. Label the corresponding tubing line.
5. Confirm that each tube outlet points to the correct tray region.
6. Ensure that the tubing is not bent, blocked, or leaking.

---

## 5. Starting the ESP32 Control Unit

1. Connect the ESP32 to the power supply or computer USB port.
2. Open the Serial Monitor if connected to a laptop.
3. Set the baud rate to:

```text
115200
