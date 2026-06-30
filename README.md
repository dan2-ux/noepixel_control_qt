# NoPixel NeoPixel Control System (Qt + ESP32)

A Windows-based desktop application built with Qt that provides real-time control of NeoPixel LED effects through an ESP32 microcontroller using HTTP communication.

The system allows users to interact with addressable LEDs via a simple graphical interface, where commands are sent from the Qt application to the ESP32 over a local network.

## Project Overview

This project acts as a bridge between a desktop UI and an embedded lighting system.

- The **Qt application (Windows)** provides the control interface
- The **ESP32** receives HTTP requests over Wi-Fi
- The **NeoPixel LEDs** update in real time based on received commands

This creates a simple and responsive system for controlling LED animations without needing direct wiring to a PC.

## What the system does

The application allows users to:

- Select different NeoPixel lighting modes
- Trigger predefined LED animations
- Send control commands to ESP32 over HTTP
- Update LED states in real time
- Manage lighting behavior through a graphical UI instead of manual coding

---

## System Architecture

Windows Qt App
↓ HTTP Requests
ESP32 Microcontroller
↓
NeoPixel LED Strip
