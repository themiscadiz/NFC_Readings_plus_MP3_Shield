/**************************************************************************/

/*
    Test Code for Information Overload Viewer
    
    @file     NFC_Readings_plus_MP3_Shield.ino
    @author   Themis Garcia

    Code based makes use of Adafriut readMiFare for NFC Shield.
    Using depracated library because the new one is not working at this time
    https://github.com/adafruit/Adafruit_NFCShield_I2C
    
*/

/*! 
    @file     readMifare.pde
    @author   Adafruit Industries
    @license  BSD (see license.txt)

    This example will wait for any ISO14443A card or tag, and
    depending on the size of the UID will attempt to read from it.
   
    If the card has a 4-byte UID it is probably a Mifare
    Classic card, and the following steps are taken:
   
    - Authenticate block 4 (the first block of Sector 1) using
      the default KEYA of 0XFF 0XFF 0XFF 0XFF 0XFF 0XFF
    - If authentication succeeds, we can then read any of the
      4 blocks in that sector (though only block 4 is read here)
   
    If the card has a 7-byte UID it is probably a Mifare
    Ultralight card, and the 4 byte pages can be read directly.
    Page 4 is read by default since this is the first 'general-
    purpose' page on the tags.


    This is an example sketch for the Adafruit PN532 NFC/RFID breakout boards
    This library works with the Adafruit NFC breakout 
      ----> https://www.adafruit.com/products/364
 
    Check out the links above for our tutorials and wiring diagrams 
    These chips use I2C to communicate

    Adafruit invests time and resources providing this open source code, 
    please support Adafruit and open-source hardware by purchasing 
    products from Adafruit!
*/



/**************************************************************************/
#include <Wire.h>
#include <Adafruit_NFCShield_I2C.h>

#define IRQ   (2)
#define RESET (3)  // Not connected by default on the NFC Shield

Adafruit_NFCShield_I2C nfc(IRQ, RESET);

// here we establish save the tag we are looking to trigger audio playback

uint8_t testTag[] = {4, 121, 10, 42, 34, 75, 132};

// MP3 Shield setup

#include <CytronEZMP3.h>
CytronEZMP3 mp3;


void setup(void) {
  Serial.begin(115200);
  Serial.println("Hello!");

  pinMode(LED_BUILTIN, OUTPUT);

  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    Serial.print("Didn't find PN53x board");
    while (1); // halt
  }
  // Got ok data, print it out!
  Serial.print("Found chip PN5"); Serial.println((versiondata>>24) & 0xFF, HEX); 
  Serial.print("Firmware ver. "); Serial.print((versiondata>>16) & 0xFF, DEC); 
  Serial.print('.'); Serial.println((versiondata>>8) & 0xFF, DEC);
  
  // configure board to read RFID tags
  nfc.SAMConfig();
  
  Serial.println("Waiting for an ISO14443A Card ...");

  // MP3 Shield Setup.
  // Notice the use of pins 8 and 9.
  // On the shield, make sure the jumpers are placed correctly.
  
  if(!mp3.begin(8, 9))
  {
    Serial.println("Init failed");
    while(1);
  }
  mp3.setVolume(50);
  Serial.print("Device: ");
  Serial.println(mp3.getCurrentDevice()==1?"U-Disk":"microSD");

  Serial.print("Total files: ");
  Serial.println(mp3.getTotalFiles());
  
}


void loop(void) {
  uint8_t success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
  uint8_t uidLength;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
    
  // Wait for an ISO14443A type cards (Mifare, etc.).  When one is found
  // 'uid' will be populated with the UID, and uidLength will indicate
  // if the uid is 4 bytes (Mifare Classic) or 7 bytes (Mifare Ultralight)
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);

  
  
  if (success) {
    // Display some basic information about the card
    Serial.println("Found an ISO14443A card");
    Serial.print("  UID Length: ");
    Serial.print(uidLength, DEC);Serial.println(" bytes");
    Serial.print("  UID Value: ");
    nfc.PrintHex(uid, uidLength);

    // We will compare the sum of the values in our testTag[] array
    // with the sum of the values in the the that is currently being read.
    // If the sum is the same, then we will consider them equal.
    
    int uidSum = 0;
    int testTagSum = 0;

    for (uint8_t i=0; i < uidLength; i++) 
    {
      // sum up values in the arrays
      uidSum += uid[i];
      testTagSum += testTag[i];


      // Print the UID values for the tag being read
      Serial.print(String(uid[i])); //currently printing in decimal (DEC), originally printed HEX
      Serial.print(" "); 

    }
    Serial.println("");
    

    // testTag - just printing the values of our testTag - not needed to function
    for (uint8_t i=0; i < uidLength; i++) 
    {
      Serial.print(String(testTag[i])); //currently printing in decimal (DEC), originally printed HEX
      Serial.print(" ");

    }
    Serial.println("");


    // We are using miFares with uidLength of 7, scroll down to 'uidLength == 7'
    
    
    if (uidLength == 4)
    {
      // We probably have a Mifare Classic card ... 
      Serial.println("Seems to be a Mifare Classic card (4 byte UID)");
    
      // Now we need to try to authenticate it for read/write access
      // Try with the factory default KeyA: 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF
      Serial.println("Trying to authenticate block 4 with default KEYA value");
      
      uint8_t keya[6] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
    
      // Start with block 4 (the first block of sector 1) since sector 0
      // contains the manufacturer data and it's probably better just
      // to leave it alone unless you know what you're doing
      success = nfc.mifareclassic_AuthenticateBlock(uid, uidLength, 4, 0, keya);
    
      if (success)
      {
        Serial.println("Sector 1 (Blocks 4..7) has been authenticated");
        uint8_t data[16];
    
        // If you want to write something to block 4 to test with, uncomment
        // the following line and this text should be read back in a minute
        //memcpy(data, (const uint8_t[]){ 'a', 'd', 'a', 'f', 'r', 'u', 'i', 't', '.', 'c', 'o', 'm', 0, 0, 0, 0 }, sizeof data);
        //success = nfc.mifareclassic_WriteDataBlock (4, data);

        // Try to read the contents of block 4
        success = nfc.mifareclassic_ReadDataBlock(4, data);
    
        if (success)
        {
          // Data seems to have been read ... spit it out
          Serial.println("Reading Block 4:");
          nfc.PrintHexChar(data, 16);
          Serial.println("");
      
          // Wait a bit before reading the card again
          delay(1000);
        }
        else
        {
          Serial.println("Ooops ... unable to read the requested block.  Try another key?");
        }
      }
      else
      {
        Serial.println("Ooops ... authentication failed: Try another key?");
      }
    }
    
    if (uidLength == 7)
    {

      // Compare sums of testTag and uid
      // If they are equal, trigger audio playback
      if(testTagSum == uidSum){
        //Serial.println("We have a match");

        // If the UID is correct play the audio track
        mp3.playTrack(1);
        
        Serial.println("Now playing track " + (String)mp3.getTrackNo());
      }
      else{
        Serial.println("No match");
      }

      
      // We probably have a Mifare Ultralight card ...
      Serial.println("Seems to be a Mifare Ultralight tag (7 byte UID)");
    
      // Try to read the first general-purpose user page (#4)
      Serial.println("Reading page 4");
      uint8_t data[32];
      success = nfc.mifareultralight_ReadPage (4, data);
      if (success)
      {
        // Data seems to have been read ... spit it out
        nfc.PrintHexChar(data, 4);
        Serial.println("");
    
        // Wait a bit before reading the card again
        delay(1000);
      }
      else
      {
        Serial.println("Ooops ... unable to read the requested page!?");
      }
    }
  }
}
