#include <BMA220.h>

BMA220 bma;
int count;
float x, y, z, total;
void setup() {
    Serial.begin(115200);
    if (!bma.begin()) {
        Serial.println(F("No valid BMA220 sensor found, check wiring"));
        while (true)  // stop here, no reason to go on...
            ;
    }
    // Set sensor sensitivity to 4g
    bma.setRegister(SENSITIVITY_REG, SENS_2g);
    count = 0;
    
}

void loop() {
  if(Serial.read() > 0 ){
    count = 0;
  }
    Serial.print("Reading Number: ");
    Serial.println(count);
    x = bma.readAcceleration(XAXIS);
    y = bma.readAcceleration(YAXIS);
    z = bma.readAcceleration(ZAXIS);
    x = x/16;
    y = y/16;
    z = z/16;
    total = sq(x) + sq(y) + sq(z);
    total = sqrt(total); 
    Serial.print("x-axis: ");
    Serial.println(x,2);
    Serial.print("y-axis: ");
    Serial.println(y,2);
    Serial.print("z-axis: ");
    Serial.println(z,2);
    Serial.print("Total Accleration: ");
    Serial.println(total,2);
    delay(1000);
    count++;
}
