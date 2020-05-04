# NFC_Readings_plus_MP3_Shield
 Technical implementation of NFC Reader with MP3 Shield for Viewer device prototype.
 <!-- Every README should start with an H1 -->
## Readme
<!-- A one sentence description of the project or assignment -->
This documentation is part of a student group project for Access and Assistive Technology in Historic Sites and Museums in NYU. This readme is for a project to tackle Information Overload in museums and historical sites. 

<img src="https://github.com/themiscadiz/NFC_Readings_plus_MP3_Shield/blob/master/Images%20for%20NFC%20Reader/1.png?raw=true" width="60%">

<!-- It is good practice to add an about or summary -->
## About

The code documented here is for a circuit that triggers audio when the NFC reader identifies an specific NFC tag. Here is the code, information about libraries, arduino shields and any other related material. 

Most of the development of this test code was using an example code for PN532 Library **readMifare** code and the example code **PlayATrack** from the CytronEasyMP3 library.

This documentation is for educational purposes and meant to build a prototype.
<!-- It is essential to describe how to set up your project -->
## Setup

<!-- Any knowledge or tools you will need before hand -->
### Prerequisites

You need:

1. Arduino (I am using the Arduino Uno) with USB cable to connected to computer.
2. NFC Shield - PN532 NFC/RFID Shield
3. Assorted of NFC tags (I used stickers)
4. MP3 Shield - [Cytron Easy MP3 Shield](https://www.cytron.io/p-cytron-easy-mp3-shield)
5. Computer
6. Arduino Software
7. Micro SD Card


## Table of main materials

| Materials  | Image | Description  | Seller  |   |
|---|---|---|---|---|
| Arduino Uno  |<img src="https://github.com/themiscadiz/NFC_Readings_plus_MP3_Shield/blob/master/Images%20for%20NFC%20Reader/Screenshot%202020-04-21%2018.15.10.png?raw=true" width="100%"> | ARDUINO UNO REV3 Code: 8058333490090  | [Arduino](https://store.arduino.cc/usa/arduino-uno-rev3)  |    |
|  PN532 NFC/RFID Shield |  <img src="https://github.com/themiscadiz/NFC_Readings_plus_MP3_Shield/blob/master/Images%20for%20NFC%20Reader/Screenshot%202020-04-21%2018.14.58.png?raw=true" width="100%"> | Adafruit PN532 NFC/RFID Controller Shield for Arduino + Extras  | [Adafruit](https://www.adafruit.com/product/789)  |   |
|  MP3 Shield |  <img src="https://github.com/themiscadiz/NFC_Readings_plus_MP3_Shield/blob/master/Images%20for%20NFC%20Reader/Screenshot%202020-04-21%2018.14.31.png?raw=true" width="100%"> |Cytron ezMP3 shield | [Cytron](https://www.cytron.io/p-cytron-easy-mp3-shield) |   |


<!-- any installation needs should be defined -->
### Installation
1. Download [Arduino](https://www.arduino.cc/en/Main/Software)

For this particular project you need to install a few libraries for Arduino:

* [CytronEZMP3 Library](https://github.com/CytronTechnologies/Cytron-EasyMP3-Shield)
* [Adafruit NFCShield_I2C Library](https://github.com/adafruit/Adafruit_NFCShield_I2C)

**Note:** Until the moment that I am write this note, the last available version of the Adafruit NFC Lirary was broken for my Adafruit NFC Shield. I used this previous version for the prototype. 
Please, refer to the [Adafruit PN532 RFID/NFC Breakout and Shiel documentation](https://learn.adafruit.com/adafruit-pn532-rfid-nfc) for more information


<!-- Write instructions on how to start working on your project -->
### Develop

To develop this prototype, you can follow the steps provided below:

1. Add an MP3 file in to the Micro SD Card. A short and clear audio it better for testing.

2. In the Cytron Easy MP3 Shield, in the VART Selector Sections change the jumper selectors into pins into D9 and D8. This changes the Jumper selectors of the example to select different Control pins. In this case its changed it from 2 and 3 pins to 8 and 9 pins.

 <img src="https://github.com/themiscadiz/NFC_Readings_plus_MP3_Shield/blob/master/Images%20for%20NFC%20Reader/2.png?raw=true" width="60%">

3. The Cytron Easy MP3 Shield comes with an audiojack, but in case you prefers speakers, you can attach through the audio jack or by soldering onto the shield. 

4. Stack the Arduino Uno &rarr; Cytron Easy MP3 Shield &rarr; PN532 NFC/RFID Shield

 <img src="https://github.com/themiscadiz/NFC_Readings_plus_MP3_Shield/blob/master/Images%20for%20NFC%20Reader/1.png?raw=true" width="60%">

5. Connect the Arduino to the computer.

6. Download and run the Arduino code from in this repository.

<!-- Notes about the deployment -->
### Deployment

The code has annotations of which part was modified to change the ID numbers of the NFC tags to your NFC tags ID

## Built with

* [Arduino](https://www.arduino.cc/en/Main/Software)

## Resources

* Adafruit PN532 RFID/NFC Breakout and Shield - [Manual](https://learn.adafruit.com/adafruit-pn532-rfid-nfc)
* Cytron MP3 Shield - [Product User’s Manual – SHIELD-EZMP3](https://docs.google.com/document/d/101Qs505IN7JQJY7b37-N_AsBFobXRuo6P5pLzN-WvWk/view#)
* [Adafruit NFCShield_I2C Library](https://github.com/adafruit/Adafruit_NFCShield_I2C) - **readMifare** example 
* CytronEasyMP3 library - **PlayATrack** example

## Authors

* [Themis Garcia](https://themis.design) -- student -- [NYU ITP](https://itp.nyu.edu)

## Code of Conduct

Please read the [CODE OF CONDUCT](https://www.mozilla.org/en-US/about/governance/policies/participation/) 

<!-- thank and reference all the things that made your project happen -->
## Acknowledgements

* **Thanks to Antonio M Guimaraes for recommendations on the technical and accessibility aspect of this project.** 
* [Cytron Easy MP3 Shield](https://www.cytron.io/p-cytron-easy-mp3-shield) for their product and documentation
* [Adafruit](https://learn.adafruit.com/adafruit-pn532-rfid-nfc) for their product and documentation


