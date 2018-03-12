#include <Sweep.h>

Sweep device(Serial1);

void setup() {
  Serial.begin(9600);
  Serial1.begin(115200);

  // Set the motor speed to 5HZ (codes available from 1->10 HZ)
  bool bSuccess = device.setMotorSpeed(MOTOR_SPEED_CODE_5_HZ);
  if (bSuccess == false) { Serial.println("Erreur #1");}
  
  // Set the sample rate to 500HZ (codes available for 500, 750 and 1000 HZ)
  bSuccess = device.setSampleRate(SAMPLE_RATE_CODE_500_HZ);
  if (bSuccess == false) { Serial.println("Erreur #2");}

  bSuccess = device.startScanning();
  if (bSuccess == false) { Serial.println("Erreur #3");}
}


void loop() {
  bool success = false;
  ScanPacket reading = device.getReading(success);
  if (success) {
    //bool bFirstOfNewScan = reading.isSync();
    uint16_t angle = reading.getAngleRaw();
    uint16_t range = reading.getDistanceCentimeters();
    uint8_t confidence = reading.getSignalStrength();

    Serial.print(angle);
    Serial.print(" ");
    Serial.println(range);
    //Serial.print(" ");
    //Serial.println(confidence);
  }
}
