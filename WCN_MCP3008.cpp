/*
  WCN_ MCP3008.cpp - Library for MAX3008 10 bit 8 channels DAC.
  Released into the public domain.
  
  
*/

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#ifdef __AVR
  #include <avr/pgmspace.h>
#elif defined(ESP8266)
  #include <pgmspace.h>
#endif

#include "WCN_MCP3008.h"

WCN_MCP3008::WCN_MCP3008(int cspin) {

  _cspin = cspin;

}

void WCN_MCP3008::begin() {

  pinMode(_cspin, OUTPUT);
  digitalWrite(_cspin, LOW);
  digitalWrite(_cspin, HIGH);
    
}

// read SPI data from MCP3008 chip
int WCN_MCP3008::readADC(byte channel) {
  byte dataMSB =    0;
  byte dataLSB =    0;
  byte JUNK    = 0x00;

  SPISettings MCP3008(2000000, MSBFIRST, SPI_MODE0);

  SPI.beginTransaction(MCP3008);
  digitalWrite(_cspin, LOW);
  SPI.transfer(0x01);                           // Start Bit
  dataMSB = SPI.transfer(channel << 4) & 0x03;  // Send readAddress and receive MSB data, masked to two bits
  dataLSB = SPI.transfer(JUNK);                 // Push junk data and get LSB byte return
  digitalWrite(_cspin, HIGH);
  SPI.endTransaction();

  return dataMSB << 8 | dataLSB;
}


