// Variables for the value of the moisture and its percentage
float val;
float valPercent;
// Saving the moisture sensor pin number in a variable
int moistPin = 5;
#include <LiquidCrystal.h>
LiquidCrystal LCD(12, 11, 10, 9, 8, 7);

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:
    val = analogRead(moistPin);
    valPercent = 100 * val / 1023;
    // Print the value and its corresponding percentage to the serial monitor
    Serial.print("val: ");
    Serial.println(int(val));
    Serial.print("valPercent: ");
    Serial.println(valPercent);
    // Print the value and its corresponding percentage to the LCD screen
    LCD.setCursor(1,0);
    LCD.print("Moisture: ");
    LCD.print(int(valPercent));
    LCD.print("%");
    delay(1000);
    LCD.clear();
}
