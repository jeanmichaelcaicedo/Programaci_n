
#include <Servo.h> //biblioteca del servo
#include <SoftwareSerial.h>
#define PINSERVODERECHO 12
#define PINSERVOIZQUIERDO 11
#define Txbluetooh 3
#define Rxbluetooh 2
//define los pines

Servo ServoDE,ServoIZQ;
//da los nombres a cada servo
SoftwareSerial BT(Rxbluetooh, Txbluetooh);//pines del bluetooh.
char orden;
 Serial.begin(9600);

  // Provide ground and power by using the analog inputs as normal digital pins.
  // This makes it possible to directly connect the breakout board to the
  // Arduino. If you use the normal 5V and GND pins on the Arduino,
  // you can remove these lines.
  pinMode(groundpin, OUTPUT);
  pinMode(powerpin, OUTPUT);
  digitalWrite(groundpin, LOW);
  digitalWrite(powerpin, HIGH);
}

void loop() {
  // print the sensor values:
  Serial.print(analogRead(xpin));
  // print a tab between values:
  Serial.print("\t");
  Serial.print(analogRead(ypin));
  // print a tab between values:
  Serial.print("\t");
  Serial.print(analogRead(zpin));
  Serial.println();
  // delay before next reading:
  delay(100);
}
