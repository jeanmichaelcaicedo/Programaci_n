
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

void setup() 
{
  pinMode (PINSERVODERECHO,OUTPUT);
  pinMode (PINSERVOIZQUIERDO,OUTPUT);
  ServoDE.attach(PINSERVODERECHO);
  ServoIZQ.attach(PINSERVOIZQUIERDO);
  Serial.begin(9600);
  BT.begin(9600);

}

void loop() 
{
  if(BT.available()>0)
  {
    orden=BT.read();
    BT.println(orden);
  }
  if(Serial.available() > 0)
  {
    int orden=Serial.read();
    Serial.println(orden);

    switch(orden)//orden es la variable
    {
      case 'w': case 'W': //avanza 
      ServoDE.write(0);
      ServoIZQ.write(180);
      Serial.println("avanzo");
      break;

      case 's': case 'S': //retrocede
      ServoDE.write(180);
      ServoIZQ.write(0);
      Serial.println("retrocedo");
      break;

      case 'a': case 'A': //gira a la izquierda
      ServoDE.write(0);
      ServoIZQ.write(90);
      Serial.println("giro a la izquierda");
      break;

      case 'd': case 'D': //gira a la derecha
      ServoDE.write(90);
      ServoIZQ.write(180);
      Serial.println("giro a la derecha");
      break;

      case 'e': case 'E': //detenerse
      ServoDE.write(90);
      ServoIZQ.write(90);
      Serial.println("me detengo");
      break;

      case 'p': case 'P': //muestra
      ServoDE.write(0);
      ServoIZQ.write(180);
      delay(1000);
      ServoDE.write(180);
      ServoIZQ.write(0);
      delay(1000);
      ServoDE.write(90);
      ServoIZQ.write(90);
      Serial.println("cuchau");
      break;

      case 'L': case 'l': //regate al rival
      ServoDE.write(0);
      ServoIZQ.write(90);
      delay(500);
      ServoDE.write(90);
      ServoIZQ.write(180);
      delay(700);
      ServoDE.write(0);
      ServoIZQ.write(180);
      break;

      case 'q': case 'Q': //regate 2 al rival
      ServoDE.write(90);
      ServoIZQ.write(90);
      delay(6000);
      ServoDE.write(90);
      ServoIZQ.write(180);
      delay(700);
      ServoDE.write(0);
      ServoIZQ.write(180);
      delay(3000);
      ServoDE.write(90);
      ServoIZQ.write(90);
      delay(200);
      break;

      case 'x': case 'X': //pase a la derecha
      ServoDE.write(90);
      ServoIZQ.write(90);
      Serial.println("Pase a la derecha");
      delay (2000);
      ServoDE.write(90);
      ServoIZQ.write(180);
      delay (2000);
      ServoDE.write(90);
      ServoIZQ.write(90);
      delay (8000);
      break;

      case 'z': case 'Z': //pase a la izquierda
      ServoDE.write(90);
      ServoIZQ.write(90);
      Serial.println("Pase a la izquierda");
      delay (2000);
      ServoDE.write(0);
      ServoIZQ.write(90);
      delay (2000);
      ServoDE.write(90);
      ServoIZQ.write(90);
      delay (8000);
      break;
    }
  }
}
