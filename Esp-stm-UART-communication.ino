#include <SoftwareSerial.h>   //allows e.g.Serial1 to serial-receive
 
SoftwareSerial mySerial(0, 2); // enables RX, TX via d3 and d4 (Serial1-   port)

void setup() {
  Serial.begin(115200);
  mySerial.begin(115200); //(This port seems only to work with 8N1)
} //setup

void loop() {
  if (mySerial.available()) {      // If anything comes in d3
    Serial.write(mySerial.read());   // read it and send it out Serial0 (pin   TX)
    //for TX:
    if (Serial.available()) {      // If anything comes in RX (Serial0)
      mySerial.write(Serial.read());   // read it and send it out on d4     (Serial1)
    }
  }
}