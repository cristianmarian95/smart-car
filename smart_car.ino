/**
 * Smart Car
 * Fainisi Marian Cristian 
 * Email: marian.fainisi@gmail.com
 * Site: www.cristian-apps.xyz
 */

/** Diver N298 Pins **/
const int ena = 10;
const int in1 = 9;
const int in2 = 8;
const int in3 = 7;
const int in4 = 6;
const int enb = 5;

/** Ultrasonic sensors pins **/
const int trigPin = 13;
const int echoPin = 12;
const int trigPin2 = 4;
const int echoPin2 = 3;

/** Variabiles **/
long duration;
long duration2;
int distance;
int distance2;

boolean moveForward = true;
boolean moveBack = false;

void setup() {
  /** First motor **/
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  /** Second motor **/
  pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  /** Front sensor **/
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  /** Back sensor **/
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  /** Set the default for first motor **/
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  /** Set the default for second motor **/
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  /** Begin the serial console **/
  Serial.begin(9600);

}

void loop() {
   if(moveForward){
      getFrontDistance();
      if(distance < 20){
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        analogWrite(ena, 100);
        analogWrite(enb, 100);
        moveForward = false;
        moveBack = true;
      }
   }
   if(moveBack){
      getBackDistance();
      if(distance2 < 20){
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        analogWrite(ena, 100);
        analogWrite(enb, 100);
        moveForward = false;
        moveBack = true;
      }
   }
}

void getFrontDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
}

void getBackDistance(){
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2*0.034/2;
}

