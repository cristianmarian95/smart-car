/**
 * Smart Car
 * Fainisi Marian Cristian 
 * Email: marian.fainisi@gmail.com
 * Site: www.cristian-apps.xyz
 * Version 1.1
 */


/** First motor **/
const int ena = 7;
const int en1 = 6;
const int en2 = 5;

/** Secont motor **/
const int enb = 4;
const int en3 = 3;
const int en4 = 2;

/** Ultrasonic sensors **/
const int SignalFront = 13;
const int SignalBack = 12;

/** Variabiles **/
boolean moveForward = true;
boolean moveBack = false;

/** Lights **/
const int lightStop = 8;

long durationFront;
long durationBack;

int distanceFront;
int distanceBack;

void setup() {
  
  pinMode(ena,OUTPUT);
  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);

  pinMode(enb,OUTPUT);
  pinMode(en3,OUTPUT);
  pinMode(en4,OUTPUT);
  
  pinMode(SignalFront, OUTPUT);
  pinMode(SignalBack, OUTPUT);
  
  Serial.begin(9600);
  
}
void loop() {
  if(moveForward){
    
    /** Stop the engines **/
    digitalWrite(lightStop, LOW);
    
    /** Direction **/
    digitalWrite(en1, HIGH);
    digitalWrite(en2, LOW);
    digitalWrite(en3, HIGH);
    digitalWrite(en4, LOW);
    
    /** Speed **/
    analogWrite(ena, 255);
    analogWrite(enb, 255);
    
    /** Calculate the distance **/
    digitalWrite(SignalFront, LOW);
    delayMicroseconds(2);
    digitalWrite(SignalFront, HIGH);
    delayMicroseconds(10);
    digitalWrite(SignalFront, LOW);
    pinMode(SignalFront, INPUT);
    durationFront = pulseIn(SignalFront, HIGH);
    distanceFront = durationFront * 0.034/2;
    pinMode(SignalFront, OUTPUT);
    
    if(distanceFront < 40){
      moveForward = false;
      moveBack = true;
    }
  }
  
  if(moveBack){
    
    /** Stop the engines **/
    digitalWrite(lightStop, HIGH);
    
    /** Direction **/
    digitalWrite(en1, LOW);
    digitalWrite(en2, HIGH);
    digitalWrite(en3, LOW);
    digitalWrite(en4, HIGH);
    
    /** Speed **/
    analogWrite(ena, 255);
    analogWrite(enb, 255);
    
    /** Calculate the distance **/
    digitalWrite(SignalBack, LOW);
  	delayMicroseconds(2);
  	digitalWrite(SignalBack, HIGH);
  	delayMicroseconds(10);
  	digitalWrite(SignalBack, LOW);
  	pinMode(SignalFront, INPUT);
  	durationBack = pulseIn(SignalBack, HIGH);
  	distanceBack = durationBack * 0.034/2;
  	pinMode(SignalBack, OUTPUT);
    
    if(durationBack < 40){
      moveForward = true;
      moveBack = false;
    }
  }
  
}
