# Deneyap Joystick Arduino Library
[FOR TURKISH VERSION](docs/README_tr.md) ![trflag](https://github.com/deneyapkart/deneyapkart-arduino-core/blob/master/docs/tr.png)

***** Add photo ****

Arduino library for Deneyap Joystick 

## :mag_right:Specifications 
- `Product ID` **M26**, **mpv1.0**
- `MCU` STM8S003F3
- `Weight` 
- `Module Dimension`
- `I2C address` 0x1A, 0x1B, 0x1C, 0x1D

| Address |  | 
| :---      | :---     |
| 0x1A | default address |
| 0x1B | address when ADR1 pad is shorted |
| 0x1C | address when ADR2 pad is shorted |
| 0x1D | address when ADR1 and ADR2 pads are shorted |

## :closed_book:Documentation
Deneyap Joystick

[How to install a Arduino Library](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap Joystick 
This Arduino library allows you to use Deneyap Joystick with I2C peripheral. You can use this library in your projects with any Arduino compatible board with I2C peripheral.

## :globe_with_meridians:Repository Contents
- `/docs ` README_tr.md and product photos
- `/examples ` Examples with .ino extension sketches
- `/src ` Source files (.cpp .h) 
- `keywords.txt ` Keywords from this library that will be highlighted in the Arduino IDE
- `library.properties ` General library properties for the Arduino package manager

## Version History

1.0.0 - initial release

## :rocket:Hardware Connections
- Deneyap Joystick and Board can be connected with I2C cable
- or 3V3, GND, SDA and SCL pins can be connected with jumper cables

| Joystick | Function | Board pins |
| :---     | :---    |   :---  |
| 3.3V     | Power   | 3.3V      |
| GND      | GND       | Ground  |
| SDA      | I2C Data  |SDA pin |
| SCL      | I2C Clock |SCL pin |
| SWIM 		|Debug| no connection |
| RES 		|Debug| no coneection |
| X 		| X Axes |any Analog pin|
| Y 		| Y Axes |any Analog pin|
| SW 		| Button pin |any GPIO pin|
| NC 		| no connection | |

## :bookmark_tabs:License Information
Please review the [LICENSE](https://github.com/deneyapkart/deneyap-kumanda-kolu-arduino-library/blob/master/LICENSE) file for license information.