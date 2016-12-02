/*
Code adapted from 
http://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/
HC-SR04 Ping distance sensor
VCC to arduino 5v 
GND to arduino GND
Echo to Arduino pin 13 
Trig to Arduino pin 12
*/

#define trigPin 5
#define echoPin 6

float cm_per_microsecond = 0.03432;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration;
  float distance;
  digitalWrite(trigPin, LOW);
  // code from the internet has these fairly specific delays
  // they seem arbitrary; I have not read the spec on the sonar
  // sensor to know if they are required or if they are the best values
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  //  delayMicroseconds(1000);//<-- internet code said the author had
  //                                removed this line
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);//<-- this is a pretty cool Arduino function
  //                                       You may want to bring up it
  //                                       documentation from the Arduino website
  Serial.print("duration: ");
  Serial.println(duration);
  distance = (duration/2) * cm_per_microsecond;
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}