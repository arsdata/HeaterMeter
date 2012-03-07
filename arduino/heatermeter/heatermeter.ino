// HeaterMeter Copyright 2011 Bryan Mayland <bmayland@capnbry.net> 
#include "Arduino.h"
#include "hmcore.h"

// See hmcore.h for most options and tweaks

#ifdef HEATERMETER_BUTTONLCD
#include "ShiftRegLCD.h"
#endif /* HEATERMETER_BUTTONLCD */

#ifdef HEATERMETER_WIRELESS_NETWORKING
// these are redundant but if you don't include them, the Arduino build 
// process won't include them to the temporary build location
#include "WiServer.h"
#include "dataflash.h"
#include "wishieldconf.h"
#endif /* HEATERMETER_WIRELESS_NETWORKING */

#ifdef HEATERMETER_RFM12 || HEATERMETER_JEENODE
#include "JeeLib.h"
#endif /* HEATERMETER_RFM12 || HEATERMETER_JEENODE*/

#ifdef HEATERMETER_JEENODE
#include <enc28j60.h>
#include <EtherCard.h>
#include <net.h>
#endif /* HEATERMETER_JEENODE */

int main(void)
{
  init();
  hmcoreSetup();
  for (;;)
    hmcoreLoop();
  return 0;
}

