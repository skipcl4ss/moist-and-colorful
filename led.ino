#define moistPin A0
#define power A1
int moisture;
int blue = 8;
int green = 9;
int yellow = 10;
int orange = 11;
int red = 12;

void setup()
{
  pinMode(power, OUTPUT);
  pinMode(moistPin, INPUT);
  Serial.begin(9600);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(orange, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop()
{
    // Apply power to the soil moisture sensor
    digitalWrite(power, HIGH);
    delay(10); // Wait for 10 millisecond(s)
    moisture = analogRead(moistPin);
    // Turn off the sensor to reduce metal corrosion over time
    digitalWrite(power, LOW);
    Serial.println(moisture);
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(orange, LOW);
    digitalWrite(red, LOW);
    // Turn on the LED based on the moisture level
    if (moisture > 50)
    {
        if (moisture < 200)
        {
            digitalWrite(red, HIGH);
        }
        else if (moisture < 400)
        {
            digitalWrite(orange, HIGH);
        }
        else if (moisture < 600)
        {
            digitalWrite(yellow, HIGH);
        }
        else if (moisture < 800)
        {
            digitalWrite(green, HIGH);
        }
        else if (moisture >= 800)
        {
            digitalWrite(blue, HIGH);
        }
    }
    // Wait for 100 millisecond(s)
    delay(100);
}
