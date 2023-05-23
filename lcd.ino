#include <LiquidCrystal.h>
LiquidCrystal LCD(12, 11, 10, 9, 8, 7);
#define moistPin A0
#define power A1
int moisture;
float moisturePercentage;

void setup()
{
  // put your setup code here, to run once:
    pinMode(power, OUTPUT);
    pinMode(moistPin, INPUT);
    Serial.begin(9600);
}

void loop()
{
    // Apply power to the soil moisture sensor
    digitalWrite(power, HIGH);
    delay(10); // Wait for 10 millisecond(s)
    moisture = analogRead(moistPin);
    moisturePercentage = (float) 100 * moisture / 1023;
    // Turn off the sensor to reduce metal corrosion over time
    digitalWrite(power, LOW);
    Serial.print("moisture: ");
    Serial.println(moisture);
    Serial.print("moisturePercentage: ");
    Serial.println(moisturePercentage);
    LCD.setCursor(1, 0);
    LCD.print("Moisture: ");
    LCD.print(int(moisturePercentage));
    LCD.print("%");
    // Wait for 100 millisecond(s)
    delay(100);
    LCD.clear();
}
