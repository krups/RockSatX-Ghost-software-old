/* RadioLoggerStation sketch
 *  
 * Matt Ruffner @KREPE 2020
 * 
 * This code is meant to run on a Feather M0 w/ Radio tethered to a computer
 * this acts as a transparent serial bridge via RFM69 radio
 * all it does is wait for a packet and dump it verbatim to the serial console.
 */

#include "RadioLogger/RadioLoggerStation.h"

#define LED           13

RadioLoggerStation station;

void setup() 
{
  Serial.begin(115200);
  //while (!Serial) { delay(1); } // wait until serial console is open, remove if not tethered to compute

  pinMode(LED, OUTPUT);
  
  if( station.begin() ){
    digitalWrite(LED, HIGH);
    //Serial.println("radio initialized");
  } else {
    digitalWrite(LED, LOW);
    //Serial.println("radio failed to init");
  }
}

void loop() {
  if( station.waitForAndPrintMessage() ){
    digitalWrite(LED, !digitalRead(LED));
  }
}