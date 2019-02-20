
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

  
