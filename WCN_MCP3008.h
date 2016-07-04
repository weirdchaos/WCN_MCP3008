/*
  MCP3008.h - Library for communicating with MCP3008 Analog to digital converter.
  Created by Uros Petrevski, Nodesign.net 2013
  Released into the public domain.
  
  ported from Python code originaly written by Adafruit learning system for rPI :
  http://learn.adafruit.com/send-raspberry-pi-data-to-cosm/python-script
*/

#ifndef WCN_MCP3008_h
#define WCN_MCP3008_h

#include <SPI.h>

class WCN_MCP3008
{
  public:
    WCN_MCP3008(int cspin);
    void begin(void);
    int readADC(byte channel);
  private:
      int _cspin;
};

#define ADC_SINGLE_CH0		0x08     // ADC Channel 0
#define ADC_SINGLE_CH1		0x09     // ADC Channel 1
#define ADC_SINGLE_CH2		0x0A     // ADC Channel 2
#define ADC_SINGLE_CH3		0x0B     // ADC Channel 3
#define ADC_SINGLE_CH4		0x0C     // ADC Channel 4
#define ADC_SINGLE_CH5		0x0D     // ADC Channel 5
#define ADC_SINGLE_CH6		0x0E     // ADC Channel 6
#define ADC_SINGLE_CH7		0x0F     // ADC Channel 7

#endif
