#include "Servo.h"
//int motorSpeed = 10;
int motorA1 = 4;
int motorA2 = 5;

Servo myServo;

int trigPin = 10;
int echoPin = 11;
int travelTime;
float distance;

#define S0 2
#define S1 6
#define S2 7
#define S3 9
#define Out 12
int x=0;
int blue = 0;
int red = 0;
int green = 0;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(3);
  myServo.write(90);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  //pinMode(motorSpeed, OUTPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);

  //analogWrite(motorSpeed, 100);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(Out, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);


}

void loop() {
  // put your main code here, to run repeatedly:
  //analogWrite(motorSpeed, 100);
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);//HIGH

  //red
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  red = pulseIn(Out, LOW);
  Serial.print("Red= ");
  Serial.print(red);
  Serial.print("  ");
  delay(100);

  //green
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  green = pulseIn(Out, LOW);
  Serial.print("Green= ");
  Serial.print(green);
  Serial.print("  ");
  delay(100);

  //blue
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blue = pulseIn(Out, LOW);
  Serial.print("Blue= ");
  Serial.print(blue);
  Serial.print("  ");
  delay(100);
  
  if(red>128&&green<70&&blue<70){
Serial.print("Red");
}
  else if(red<70&&green>=128&&blue<70){
Serial.print("Green");
}
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  travelTime = pulseIn(echoPin, HIGH);
  distance = 0.034 * travelTime/2;
  if (distance < 10) {
Serial.println("the distance is less than 10");
myServo.write(180);
delay(1500);
}
else {
myServo.write(90);
}
if (distance > 60 || distance <= 0){
myServo.write(90);
Serial.println("The distance is more than 60");
}
else {
Serial.print(distance);
Serial.println(" cm");
}



}
