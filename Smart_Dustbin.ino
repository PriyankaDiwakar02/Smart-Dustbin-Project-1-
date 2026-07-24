#include <Servo.h>

Servo lid;

const int trigHand = 9;
const int echoHand = 10;

const int trigLevel = 7;
const int echoLevel = 8;

const int servoPin = 6;
const int buzzer = 5;
const int greenLed = 3;
const int redLed = 4;

long duration;
int distance;

void setup() {

pinMode(trigHand, OUTPUT);
pinMode(echoHand, INPUT);

pinMode(trigLevel, OUTPUT);
pinMode(echoLevel, INPUT);

pinMode(buzzer, OUTPUT);
pinMode(greenLed, OUTPUT);
pinMode(redLed, OUTPUT);

lid.attach(servoPin);
lid.write(0);

Serial.begin(9600);

}

int getDistance(int trig,int echo){

digitalWrite(trig,LOW);
delayMicroseconds(2);

digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

duration=pulseIn(echo,HIGH);

distance=duration*0.034/2;

return distance;

}

void loop(){

int handDistance=getDistance(trigHand,echoHand);

int levelDistance=getDistance(trigLevel,echoLevel);

if(handDistance<20){

lid.write(90);

delay(3000);

lid.write(0);

}

if(levelDistance<8){

digitalWrite(redLed,HIGH);

digitalWrite(greenLed,LOW);

digitalWrite(buzzer,HIGH);

}

else{

digitalWrite(redLed,LOW);

digitalWrite(greenLed,HIGH);

digitalWrite(buzzer,LOW);

}

delay(200);

}
