#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h> 

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

const int green = 7;
const int servoPin = 4;
const int red = 6;
const int buzz= 5;
const byte id[4] = {0xB9, 0x94, 0xD1, 0x15};
Servo myservo; 
void setup() {
  myservo.attach(4); 
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(buzz, OUTPUT);
 
}

void loop() {
  delay(3000);
  myservo.write(0);
  
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

 

  bool cardMatch = true;
  for (int i = 0; i < 4; i++) {
    if (mfrc522.uid.uidByte[i] != id[i]) {
      cardMatch = false;
      break;
    }
  }

  if (!cardMatch) {
    Serial.println("Carte non reconnue");
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
   for (int i = 0; i < 3; i++) {
    digitalWrite(red, HIGH);
    digitalWrite(buzz, HIGH);
    delay(200);
    digitalWrite(red, LOW);
    digitalWrite(buzz, LOW);
    delay(200);
    myservo.write(0);

  }

    return;
  }

  Serial.println("Carte reconnue");

  for (int i = 0; i < 3; i++) {
    digitalWrite(green, HIGH);
    digitalWrite(buzz, HIGH);
    delay(50);
    digitalWrite(green, LOW);
    digitalWrite(buzz, LOW);
    delay(50);
    myservo.write(90);
    
  }

  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}
