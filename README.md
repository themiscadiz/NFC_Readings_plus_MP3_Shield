# NFC_Readings_plus_MP3_Shield
 Technical implementation of NFC Reader with MP3 Shield for Viewer device prototype.
 <!-- Every README should start with an H1 -->
## Readme
<!-- A one sentence description of the project or assignment -->
This documentation is part of a student group project for Access and Assistive Technology in Historic Sites and Museums in NYU. This readme is for a project to tackle Information Overload in museums and historical sites. 

![TechComponents](https://lh3.googleusercontent.com/EFM9miqGuEJ1OTFOHIwYFoqEBt3Xx3hkn_obwp70h6I-Zx1jVLuQnkH0T_rMP4FOSJVN6-2h-PyPoCX2G1j-2E1pghRyyVgCIByZp6SFeWW9dbTaqwzWAIOkE8dPH6xIwyF2b5hNuTaMPmtphnCOBurn2ML_4MXC3khVFDHXAx1dFrK69tiI3rM1SHm4PXjZ7svMlUfdbOkavEE3vM3FRMpuowAyQQyhvHtS5vzNlZEpDS2QlUvD1k6eV_-zlO34r2vdCY9Q3xtFWtVwlxT_39lmlsUQQ-lLGdaD1qmKwtONFqk-M9gecsnanRTyZjGqq8z_ec-Sentac93Jq5bshbQd73b4Zfd4vONFNJbGkPKk1SC6mcZC-2hc4dnlBXoJXK0k1BioqkR1s6ddQy9LraXtsjUGqySf5HGtzjAC46yhpYinWI0RPfld5msfizbM-BBCPq5t3OcM4VxBbvuv1Yd8en-wVrXpMfpLhPPwQs100phB8OL3Gh7zCC-1OUcsjlsPZxA1DGcwVtjUVB0s_YB_IaZ4ZqT5WAvm5FwIt_QpMj54f-ouMj-PZv9oFQdQTjsOYblJHOuS-1S-UtJEJF5WFSQzisxHaazLW4K0VQcGJpkTaEfcWVaxxz6K1DnRGm2pCV3YBmWzPceBb-HuKHk5xinswL_ItNXR-0n3pne2Li7cQr-bQD95P5MC=w849-h508-no)

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
| Arduino Uno  |<img src="https://lh3.googleusercontent.com/p9wPGGQjTKraU8UecpWOQmOhqP19NEq1HWoKVvg9BKJkFQdj0hQ4yPBFZnCQ2DMYqu0CRLndHy18ChJN0tGjkhDXwATZ5TMIALikhSCV3Z0fiuGg3iwyHVJkF5X6ZFFe8QkGGfKgL9qpa2_GQVQtVE6PxOl1wJdQjCt-aodDFCkcSV3u4Eg8cXcnBVOddMBGID0EzataBwmxqpUYAQIFSpgYK3yGNhaGElLX7eXS_tIuE18tR8Pjb9E5klzTmzZ5rCPJbBkDMrijTAfjsvygWYt7XjdQk8nnPcLDp3zyA2A1V7tT6zQ1oaPM_YTmPf0S8VvBopGeNpBa_TtSOXZdUU3flMnSmStBlsMeF9Adu6Gg-FenGN-fTJjgYh_Mq8lQOPmwCi5QhOAd7EQfLYw52EGWW86SexzEtscyfK17G5utnsjauGWwjWWz1OARHdSLcywus8Y4x8UzzagLAxwoZ-IfWtH9A3OePUyetY2vRE3uqol08WBmvhCXM5BLxbw0ozMArXDiECXeibc9HW9ESBq2nbel-ihjda0WDCDxJ2UKkVwsd6M4bIpOsTQMMnbFdHofZdcZeF3Vv7Td3gCmqX1dse4UnyI-ArLVGpCJTl_fnoXQMcIrzKnSzUCQjnw_9NnonVhEDOgbpdpzrtb8eCJtfeZr6Si-6UHisXOWkuswJ-JQYsPLkgkwoZYB=w507-h357-no" width="100%"> | ARDUINO UNO REV3 Code: 8058333490090  | [Arduino](https://store.arduino.cc/usa/arduino-uno-rev3)  |    |
|  PN532 NFC/RFID Shield |  <img src="https://lh3.googleusercontent.com/TQCVI1IqAFBrzRd6AE-hcBuNfJhjopN6WdNKaK5iExgNfyFZln1S___Knmpz2Q9QqGdF_WGh-Ns35RyGV3cD8JZufKs5pgjOH9uGP0LNRzpsOAKeW5QpL67QG7Z2q5SXdm9bQPbjxEn-F3uc7Ex5QSpbgcQrDweXkgX86lgFidi51HnARt27EKjyNX13etuxYoKhwCuion5piCPCY3_tMsJEWx_rb3k2JpD7y6SwCNxDSQ-LLoMvVGFrPSFeUtbTXEszUHtXdxRyJ8i4Os4KZcRpcWneZ1xukEfZpzZhhNXXlVzM3y7pO3kRivd2JbMag4r4Ur0WHPU2Ll6JUtZu_bMVJWmWQxxCYmr88DK7il2Kvml4V-XgtnSOkyL9wfYhUsOr4ayJVC0CjwQl7_GR6YqUrBTrT4SVjzjvwMNbOj4SS1fEvVl-uXbA3yvmagtBfiwvZHKANSGegQMtqmnhPVBZ9uNXs5A4PR6FLL732dtnKxoe_a1FVJh9sk-l8onSK5MIBFITsjOWyAhuVGlN2GbB8Oo_Js0_R6zpePeM5813QzLBREt2-7mP0sVyZQtL1tMuYm37FYTYRpoOyTv1m8T_aZeddJsd5ekwqdL5C9z075j82sOd2RtDejzxPwrjmZfikN8np1JrMgEfL_xE1Jrxab6amyGBCjPT46AjkNGVp4rqgNbk6F1HhcUJ=w597-h417-no" width="100%"> | Adafruit PN532 NFC/RFID Controller Shield for Arduino + Extras  | [Adafruit](https://www.adafruit.com/product/789)  |   |
|  MP3 Shield |  <img src="https://lh3.googleusercontent.com/clWSSw17DTuCz0d4DVzxK_wE-X4c0VWO0ghoiChjZvzN1yelxsAkfg5uR5G8drAw6j0cEoylhpHFVX8CONQjbgPpCD2BnwjtuI5ei3uEdje46Tvcy4yB0Ka4EWAREI__OMB0_rLSA-aQTYIH-0z8uhI7F6t_pyMFU2s6PyO4p2PZPI7XIqFQjsfMbNlOe3RArceucy1_yicxJPoBiv1JSWjVHRLvEPx1Uz23RsPiDAQh7w97f99Mm8Wl4hNKJkT-r0SuV8Rv8K0J6_UCPPG8_Icm27akcAAw_g1IlbrhknYWHPlrk-1qLCzvtl-KAsFqdXI2p-rzwWnC0K9qDOconQHSggeS3YjGEs02Z7nnni3VzaaTZ3lPYPZDwpId25mdkBEgXfAWijZuRgnV6PrZxVuQI3JAyi70KbuQuLQE_c2mDwdZYAth_uUutTBpwvmAdCsyN4Rbz5scB4KR8LvrfL5tTcQgIGhxnEAFj8-wT9NqWMshb30TolgmDxSBigm5co4L2oecZCBcyBB2MHKEj1nSjiygp26ehdvfEyPCbHnheQFXqm1NtaXbFm6M14VtRUdsp73tiCMSm44GpS0pS-GIKN1uX6q1XPc7JGdA0Xm7AaUPxPReXlzL_CTuk0nL40DtqoV7L25kTP6o4V8VdpxjEBxRZezm-7-5yl7JSoPGvcUYa3vIHC-O56L4=w447-h352-no" width="100%"> |Cytron ezMP3 shield | [Cytron](https://www.cytron.io/p-cytron-easy-mp3-shield) |   |


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

![TechComponents](https://lh3.googleusercontent.com/8pHnRbVk0Je327qLzQO2h2VPsgNQjRNwQELiMX8puksVei5NtS2yP1RlEhrjlrvzb7u6A0nh7KP1aoqWP0_2jCPOoG7BHRooDJEza0WCA0dQrkjBu7TP45xD2iD4MljFmzoHZvCQeqLAuAa-oEQvwjtQr2leSNOV4U7FavC48VuK4BZKbsYys42tuSUJ1nZbF-OVLKvt-dseV2xBCO2JVYtA477j8QoaKqsdQ9o48Z_dJDDXNAoGEdp2ebfSpWL0HfHpPTKM_IP5-dMIzd3cQGa0_GJiIY8WPvammRKfPnA-OWCAf4L8_cHR-pv69FhDBpzE9EYKWz7uqxBMJ0W5Ear9tst5AW1fOr6DRLiHufucQbbEIbHlYs-VpWtipDOGa7cmA41EjNQEe1-GT-R41Kcc55f0pFV0T7kS434D8U4F8pJy-Gr0JIU_MjmQ3FxwItQ22bzzyzKFiQmI4Pbw5gixwXVvk4yOtcPbHtTemQ9sC4WngBP_AYN6qrEfz8n6LaFB6nEhnPEwdX4i2zKjqyJ-L7uNuo9J9jRNeV4J0rrbqnRL9ipEawWhoERJSC8l0KbnWBd76hSZ8T-vGXznPjjazCsoqtOdIaloPrHK0AUaL9DNQHMyAG0uH1PgIj_0H3pAeXc0fFMi9MByUTifDOzeHi3ugPPNMpwpab2C_0pqZO0A5cykempkjGX1=w302-h240-no)

3. The Cytron Easy MP3 Shield comes with an audiojack, but in case you prefers speakers, you can attach through the audio jack or by soldering onto the shield. 

4. Stack the Arduino Uno &rarr; Cytron Easy MP3 Shield &rarr; PN532 NFC/RFID Shield

![TechComponents](https://lh3.googleusercontent.com/EFM9miqGuEJ1OTFOHIwYFoqEBt3Xx3hkn_obwp70h6I-Zx1jVLuQnkH0T_rMP4FOSJVN6-2h-PyPoCX2G1j-2E1pghRyyVgCIByZp6SFeWW9dbTaqwzWAIOkE8dPH6xIwyF2b5hNuTaMPmtphnCOBurn2ML_4MXC3khVFDHXAx1dFrK69tiI3rM1SHm4PXjZ7svMlUfdbOkavEE3vM3FRMpuowAyQQyhvHtS5vzNlZEpDS2QlUvD1k6eV_-zlO34r2vdCY9Q3xtFWtVwlxT_39lmlsUQQ-lLGdaD1qmKwtONFqk-M9gecsnanRTyZjGqq8z_ec-Sentac93Jq5bshbQd73b4Zfd4vONFNJbGkPKk1SC6mcZC-2hc4dnlBXoJXK0k1BioqkR1s6ddQy9LraXtsjUGqySf5HGtzjAC46yhpYinWI0RPfld5msfizbM-BBCPq5t3OcM4VxBbvuv1Yd8en-wVrXpMfpLhPPwQs100phB8OL3Gh7zCC-1OUcsjlsPZxA1DGcwVtjUVB0s_YB_IaZ4ZqT5WAvm5FwIt_QpMj54f-ouMj-PZv9oFQdQTjsOYblJHOuS-1S-UtJEJF5WFSQzisxHaazLW4K0VQcGJpkTaEfcWVaxxz6K1DnRGm2pCV3YBmWzPceBb-HuKHk5xinswL_ItNXR-0n3pne2Li7cQr-bQD95P5MC=w849-h508-no)

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


