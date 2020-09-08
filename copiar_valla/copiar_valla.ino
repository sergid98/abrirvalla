#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

int llegit;

void setup() {
  Serial.begin(9600);
  mySwitch.enableTransmit(10);
  mySwitch.setRepeatTransmit(1);

}


void loop() {
        static const RCSwitch::Protocol protocolpreparar = { 387, {  0, 0 }, { 0,  10 }, { 1,  1 }, false }; //400us, 0,0 de senyal de sincronia (0x400 HIGH i 0x400 LOW),  el 0 es 0,10 (0x400 de HIGH i 10x400 de LOW) i el  el 1 es 1,1 (1x400 de HIGH i 1x400 de LOW)
        static const RCSwitch::Protocol protocoldata = { 387, {0, 0 }, {  1,  2 }, { 2,  1 }, false }; //400us, 0,0 de senyal de sincronia (0x400 HIGH i 0x400 LOW),  el 0 es 1,2 (1x400 de HIGH i 2x400 de LOW) i el  el 1 es 2,1 (2x400 de HIGH i 1x400 de LOW)
        mySwitch.setProtocol(protocolpreparar);
        mySwitch.send("1111111111110");
        mySwitch.setProtocol(protocoldata);
        mySwitch.send("1101110011");
        mySwitch.send("0000000010");
        mySwitch.send("0000011000");
        mySwitch.send("1100100000");
        mySwitch.send("0111001111");
        mySwitch.send("1000010101");
        mySwitch.send("101100");
        delay(200);
      }
