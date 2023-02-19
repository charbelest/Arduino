#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Data wire is connected to GPIO2
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature sensors(&oneWire);

#define BLYNK_TEMPLATE_ID "TMPL6K-MtgBj"
#define BLYNK_TEMPLATE_NAME "Temperature"
#define BLYNK_AUTH_TOKEN "//yout blynk auth token //"
// Wi-Fi network credentials
char ssid[] = "//your wifi name //";
char pass[] = "//your wifi password//";
char auth[] = BLYNK_AUTH_TOKEN;

// Pin numbers for LEDs and relay

const int blueLedPin = 4;
const int redLedPin = 5;
const int greenLedPin = 16;
const int whiteLedPin = 16;
const int RELAY_PIN = 15;

// Initialize virtual pin for relay control
int relayState = LOW;
BLYNK_WRITE(V2)
{
  relayState = param.asInt();
  digitalWrite(RELAY_PIN, relayState);
}

void setup()
{
  // Start serial communication for debugging
  Serial.begin(9600);

  // Connect to Wi-Fi network
  Blynk.begin(auth, ssid, pass);

  // Start up the Dallas Temperature library
  sensors.begin();

  // Set pin modes for LEDs and relay
  pinMode(blueLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
}

void loop()
{
  // Send the command to get temperatures
  sensors.requestTemperatures();

  // Get the temperature in Celsius
  float temperatureC = sensors.getTempCByIndex(0);

  // Print the temperature for debugging
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  Blynk.virtualWrite(V1, temperatureC);

  // Check the temperature range and turn on the appropriate LED and relay
  if (temperatureC < 10.0) {
    digitalWrite(blueLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, LOW);
    digitalWrite(RELAY_PIN, relayState);

  } else if (temperatureC >= 13.0 && temperatureC <= 20.0) {
    digitalWrite(blueLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(RELAY_PIN, relayState);
  } else if (temperatureC > 20.0 && temperatureC <= 30.0) {
    digitalWrite(blueLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
    digitalWrite(RELAY_PIN, HIGH);
    
  } 

  delay(1000);
}
