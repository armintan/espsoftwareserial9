
#include <SoftwareSerial9.h>

SoftwareSerial9 swSer(5, 4, false, 256);

void setup() {
  Serial.begin(115200);
  swSer.begin(9600);

  Serial.println("\nSoftware Serial 9 Bit test started");
  while(!Serial);

  for (int ch = 0x100; ch <= 0x8FF; ch++) {
    swSer.write9(ch);
    if(swSer.overflow()) Serial.printf("Overflow: %04x", ch);
  }

}

void loop() {
  while (swSer.available() > 0) {
    Serial.printf("%04x ",swSer.read());
  }


  while (Serial.available() > 0) {
    swSer.write(Serial.read());
  }

}
