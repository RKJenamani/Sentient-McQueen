#include <Ultrasonic.h>
Ultrasonic ultrafront(8,9);
Ultrasonic ultraleft(10,11);
Ultrasonic ultraright(6,7);
const int out1 = 5;
const int out2 = 4;
const int out3 = 3;
const int out4 = 2;
const int backoff =10;

void setup() 
{
  pinMode (out1, OUTPUT);
  pinMode (out2, OUTPUT);
  pinMode (out3, OUTPUT);
  pinMode (out4, OUTPUT);
    pinMode(12 , OUTPUT);
  Serial.begin(9600);
   analogWrite(12,200);
}
long dfront, dleft, dright;
void loop()
{      
  dfront = ultrafront.Ranging(CM);
  Serial.print("front: ");
  Serial.print(ultrafront.Ranging(CM)); // CM or INC
  Serial.print(" cm  \n   " );
  delay(10);
  //left
  dleft = ultraleft.Ranging(CM);
  Serial.print("left: ");
  Serial.print(ultraleft.Ranging(CM)); // CM or INC
  Serial.print(" cm   \n  " );
  delay(10);
  //right
  dright = ultraright.Ranging(CM);
  Serial.print("Right: ");
  Serial.print(ultraright.Ranging(CM)); // CM or INC
  Serial.print(" cm   \n  " );
  delay(10);
  if(dfront<15 && (dright-dleft>8))
{
   digitalWrite(out1,HIGH);
      digitalWrite(out2,LOW);
      digitalWrite(out3,LOW);
      digitalWrite(out4,HIGH);
      delay(1000);
}
else if(dfront<15 && (dleft-dright>8))
{
      digitalWrite(out1,LOW);
      digitalWrite(out2,HIGH);
      digitalWrite(out3,HIGH);
      digitalWrite(out4,LOW);
      delay(500);
}
else if(dfront>15 && dleft>3 && dright>3)
{
   digitalWrite(out1,HIGH);
      digitalWrite(out2,LOW);
      digitalWrite(out3,HIGH);
      digitalWrite(out4,LOW);
      delay(500);
}
else if(dleft<5)
{
    digitalWrite(out1,HIGH);
      digitalWrite(out2,LOW);
      digitalWrite(out3,LOW);
      digitalWrite(out4,HIGH);
      delay(100);
}
else if(dright<5)
{
    digitalWrite(out1,LOW);
      digitalWrite(out2,HIGH);
      digitalWrite(out3,HIGH);
      digitalWrite(out4,LOW);
      delay(100);
}   

}
