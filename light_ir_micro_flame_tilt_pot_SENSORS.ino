const int microphonePin = A2;
int inf=8;
const int tilt=6;
int FlameSensorPin=A3;
int FlameSensorReading;
int green = 5;
int red= 4;
int buzz = 13;

void setup() {
 pinMode(tilt, INPUT);
 Serial.begin(9600);
 pinMode(green, OUTPUT);
 pinMode(red, OUTPUT);
 pinMode(buzz, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:




  int mn = 1024;
  int mx = 0;

  for (int i = 0; i < 10000; ++i) {

    int val = analogRead(microphonePin);
    
    mn = min(mn, val);
    mx = max(mx, val);
  }

  int delta = mx - mn;

  Serial.print("Min=");
  Serial.print(mn);
  Serial.print(" Max=");
  Serial.print(mx);
  Serial.print(" Delta=");
  Serial.println(delta);


  if (delta > 5) {
    digitalWrite(red, HIGH);  
    digitalWrite(green, LOW);
    digitalWrite(buzz,HIGH);
    delay(5000); 
     }

  else {
      digitalWrite(green, HIGH);
      digitalWrite(red, LOW); 
      digitalWrite(buzz, LOW);
    }
    

     if (digitalRead(8)== LOW)
  {
   
    digitalWrite(green,LOW);
    digitalWrite(red,HIGH);
    digitalWrite(buzz,HIGH);
    delay(5000);
    
    
    
  }
  else 
  {
    
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
    digitalWrite(buzz,LOW);
    delay(10);
    
  }






  unsigned int AnalogValue;
  AnalogValue = analogRead(0);
  int sensorValue = analogRead(A1);
  Serial.print("Potentiometer : ");
  Serial.println(sensorValue);
  Serial.print("Light Value :");
  Serial.println(AnalogValue);
if (AnalogValue < sensorValue)
{
    digitalWrite(green,LOW);
    digitalWrite(red,HIGH);
    digitalWrite(buzz,HIGH);
    delay(5000);
}
else {

  digitalWrite(green,HIGH);
  digitalWrite(red,LOW);
  digitalWrite(buzz, LOW);
    

}



int sensorValues = digitalRead(7);
    if(sensorValues==HIGH){ 
        Serial.println("ON-State");
        digitalWrite(green, LOW);
        digitalWrite(red, HIGH);
        digitalWrite(buzz,HIGH);
        delay(5000);
    }
    else{
        Serial.println("OFF-State");
        digitalWrite(red, LOW);
        digitalWrite(green, HIGH);
        digitalWrite(buzz, LOW);
        
    }


FlameSensorReading=analogRead(FlameSensorPin);
Serial.println(FlameSensorReading);
if (FlameSensorReading>3){
  digitalWrite(red,HIGH);
  digitalWrite(green,LOW);
  digitalWrite(buzz,HIGH);
  delay(5000); 
  }
  else{
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    digitalWrite(buzz, LOW);
    }










}