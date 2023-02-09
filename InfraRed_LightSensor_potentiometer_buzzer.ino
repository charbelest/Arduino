int inf=12;
int LED=13;
int LED1 = 2;
int LED3 = 8;

const int buzzer = 9;
unsigned long Depart;

void setup()
{
  pinMode(13,OUTPUT);
  pinMode(2,OUTPUT);
 pinMode(8,OUTPUT);

  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  Depart = millis();
}
void loop()
{

  
  unsigned int AnalogValue;
  int sensorValuepot = analogRead(A1);
AnalogValue = analogRead(0);

  if (sensorValuepot > 511.5)
{
  digitalWrite(8,HIGH);
}

else {
  digitalWrite(8,LOW);
}
if (digitalRead(12)== LOW)
  {
   delay(4000);
      if(digitalRead(12)== LOW) {
    digitalWrite(13,LOW);
    digitalWrite(2,HIGH);
    
       
      tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);
        tone(buzzer, 1200); 
        delay(100);        
        noTone(buzzer);     
        delay(100);

    }
  }
else {
    noTone(buzzer);
    digitalWrite(13,HIGH);
    digitalWrite(2,LOW);
    delay(10);
    
  
}
    

  
  

  if (AnalogValue > sensorValuepot)
{
    digitalWrite(13,LOW);

}
else {

  digitalWrite(13,HIGH);

  tone(buzzer, 1200); 
  delay(100);        
  noTone(buzzer);     
  delay(100);    

}
}