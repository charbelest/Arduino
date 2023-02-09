#include <Servo.h> // include the Servo library

const int trigPin = 12; // trigger pin for ultrasonic sensor
const int echoPin = 11; // echo pin for ultrasonic sensor
const int servoPin = 9; // pin for the servo motor
const int LED = 13; // pin for the buzzer
const int LED1 = 10;
Servo myservo; // create an instance of the Servo library

void setup() {
  myservo.attach(servoPin); // attach the servo to the servo pin
  pinMode(trigPin, OUTPUT); // set the trigger pin as an output
  pinMode(echoPin, INPUT); // set the echo pin as an input
  pinMode(LED, OUTPUT); // set the buzzer pin as an output
  pinMode(LED1, OUTPUT); 
  // start the serial communication
  Serial.begin(9600);
}

void loop() {
  long duration, distance; // variables to store the duration and distance

  // send a 10us pulse on the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure the duration of the pulse on the echo pin
  duration = pulseIn(echoPin, HIGH);

  // calculate the distance in cm
  distance = duration * 0.034 / 2;

  // check if the distance is under 15 cm
  if (distance < 15) {
    // move the servo to 90 degrees
    myservo.write(90); 
    digitalWrite(LED, HIGH);
    digitalWrite(LED1, LOW);
    delay(100);
  } else {
    // move the servo to 0 degrees
    myservo.write(0);
    // turn off the buzzer
    digitalWrite(LED, LOW);
    digitalWrite(LED1, HIGH);
  }


}
