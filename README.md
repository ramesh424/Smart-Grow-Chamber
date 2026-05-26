# Validation Protocol

## Open-Source Automated Grow Chamber for Seed Germination Monitoring

This document describes the validation procedure for the automated grow chamber. The protocol verifies environmental monitoring, soil moisture monitoring, relay-based actuator switching, pump-based liquid delivery, Raspberry Pi camera image acquisition, germination detection, and integrated system operation.

---

## 1. Validation Objectives

The validation procedure confirms that:

- The DHT11 sensor records chamber temperature and relative humidity.
- The soil moisture sensor records moisture variation near the germination medium.
- The relay module switches grow lights, pumps, and exhaust fan correctly.
- The peristaltic pumps deliver liquid through the assigned tube lines.
- The Raspberry Pi camera captures clear seed-tray images.
- The germination detection script annotates germinated and non-germinated seeds.
- The complete system operates as an integrated grow chamber.

---

## 2. Required Materials

| Item | Purpose |
|---|---|
| Assembled grow chamber | Hardware under test |
| ESP32 firmware | Sensor reading and relay switching |
| Raspberry Pi camera script | Seed-tray image capture |
| Germination detection script | Image processing and annotation |
| Germination tray | Seed/sample placement |
| Seeds | Germination test samples |
| Water or treatment solutions | Liquid delivery testing |
| Measuring cup / graduated cylinder | Pump flow measurement |
| Laptop / monitor | Serial output and image verification |
| Stopwatch / timer | Pump activation timing |
| Experiment log sheet | Recording validation results |

---

## 3. Environmental and Moisture Monitoring Validation

### 3.1 Purpose

To verify that the DHT11 temperature-humidity sensor and soil moisture sensor are connected correctly and provide readable values during chamber operation.

### 3.2 Procedure

1. Power the ESP32 control unit.
2. Open the Serial Monitor at 115200 baud.
3. Confirm that temperature, relative humidity, and soil moisture readings are displayed.
4. Record sensor values at fixed intervals.
5. Observe whether the readings change when the chamber condition or moisture condition changes.

### 3.3 Data to Record

| Parameter | Sensor used | Recorded range | Observation |
|---|---|---|---|
| Temperature | DHT11 | ___ °C to ___ °C | ___ |
| Relative humidity | DHT11 | ___ %RH to ___ %RH | ___ |
| Moisture condition | Soil moisture sensor | Raw ADC ___ to ___ / or ___ % to ___ % | ___ |

### 3.4 Acceptance Criteria

- Temperature and humidity readings are displayed without repeated sensor failure.
- Soil moisture reading changes when the moisture condition changes.
- Sensor readings are stable enough for experiment documentation.

---

## 4. Relay and Actuator Switching Validation

### 4.1 Purpose

To verify that each relay channel switches the assigned output device correctly.

### 4.2 Procedure

1. Power the ESP32 and relay module.
2. Run the actuator test function in the ESP32 firmware.
3. Switch each output device individually.
4. Confirm that the correct device turns ON and OFF.
5. Record the result for each channel.

### 4.3 Data to Record

| Output device | Control method | Validation check | Result |
|---|---|---|---|
| Grow Light 1 | Relay switching | ON/OFF response verified | Pass / Fail |
| Grow Light 2 | Relay switching | ON/OFF response verified | Pass / Fail |
| Pump 1 | Relay switching | Liquid flow verified | Pass / Fail |
| Pump 2 | Relay switching | Liquid flow verified | Pass / Fail |
| Pump 3 | Relay switching | Liquid flow verified | Pass / Fail |
| Pump 4 | Relay switching | Liquid flow verified | Pass / Fail |
| Exhaust fan | Relay switching | ON/OFF response verified | Pass / Fail |

### 4.4 Acceptance Criteria

- Each relay channel controls only the assigned device.
- No unintended device turns ON during testing.
- Grow lights, pumps, and exhaust fan switch reliably.

---

## 5. Pump Flow Characterization

### 5.1 Purpose

To estimate the liquid volume delivered by each peristaltic pump for a fixed activation time.

### 5.2 Procedure

1. Fill the reservoir with water or treatment solution.
2. Place the outlet tube of Pump 1 into a measuring cup or graduated cylinder.
3. Run Pump 1 for a fixed duration, such as 10 seconds.
4. Measure the delivered volume.
5. Repeat the procedure for Pump 2, Pump 3, and Pump 4.
6. Repeat each test if better accuracy is required.
7. Calculate the flow rate.

### 5.3 Formula

```text
Flow rate = Delivered volume / Pump activation time
