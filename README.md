# moist-and-colorful

A team project that I participated in a year ago and was responsible  for the coding part, It is an Arduino-powered machine that measures the moisture of some soil and represents the level of moisture on five colored LEDs.  
We were going to use an LCD screen but found the LED bulbs idea to be more practical. Nevertheless, this repo shows the project in both ways.
- - - -

## Project Characteristics

The project consists of:
* 1 Arduino Mega 2560
* 1 Breadboard
* 1 Moisture sensor
* 1 220 Ω resistor
* 1 LCD screen of size 2×16 (used in LCD part only)
* 1 250 kΩ potentiometer (used in LCD part only)
* 5 LEDs of various colors (used in LED part only)
- - - -

## Arduino Type

Arduino Mega 2560 microcontroller, with Arduino C++ as the programming language used.  
Arduino Uno (used in Tinkercad simulation).
- - - -

## Code

### Global Variables

* moistPin (Analog, INPUT), power (Digital, OUTPUT): the signal and power pins of the moisture sensor respectively, the power is not connected to a conventional 5V pin as we need to repeatedly switch the sensor on and off to reduce metal corrosion over time.
* moisture, moisturePercentage: variables to save the reading of the sensor and and turn it into a percentage by multiplying it by the factor 100 / 1023 (100 for the percentace divided by the maximum value of an analog reading).
* red, orange, yellow, green, blue (Digital, OUTPUT): pins for the five LEDs of those colors (used in the LED part of the project).

### Main Loop

The code powers the sensor for 10 ms, saves the reading of the sensor to *moisture*, then turns of the sensor to try to avoid corrosion.

#### LCD

The LCD code calculates the *moisturePercentage* in the way we discussed above, prints it on the LCD for 100 ms, then clears the screen to print the new *moisturePercentage* value.

#### LED

The LED code turns off the five LED pins then does something for 100 ms depending on the value of *moisture*  
If *moisture*:
* is less than or equal 50, nothing happens.
* is between 50 and 200, the red LED is turned on.
* is between 200 and 400, the orange LED is turned on.
* is between 400 and 600, the yellow LED is turned on.
* is between 600 and 800, the green LED is turned on.
* is more than or equal 800, the blue LED is turned on.
- - - -

## Project in Action

### Simulation

This is a link for the Tinkercad simulation of the [LCD](https://www.tinkercad.com/things/hcEEwr028Jx?sharecode=G5QvSJPuiPU12i9WjUoDbIdLhy1j9a7VYkJ7YUvHuDY) sequence, while this is for the [LED](https://www.tinkercad.com/things/2gfS2zC43sc?sharecode=VrkaaIsXNckLXB1ZxpS0ABcfuWLIzO6jvE8BFt6LbB4) part.

The following are screenshots of the simulation of both LCD and LED parts of the project. The simulation was made using Tinkercad.

The LCD part:  
<img src="./media/lcd-tinker.png" alt="An image of the lcd part of the project in simulation" width="600" height="382">

The LED part:  
<img src="./media/led-tinker.png" alt="An image of the led part of the project in simulation" width="600" height="355">

### Usage

[This video](https://drive.google.com/file/d/1kBvzGpKA6uddxynxiIed6QckIImA4Hxz/view?usp=share_link) demonstrates the project in action.

The following are some images of the project:  
<img src="./media/led.jpg" alt="An image of the isometric view of the project" width=60% height=60%>  
<img src="./media/orange.jpg" alt="An image of the project with the orange led on" width=60% height=60%>  
<img src="./media/green.jpg" alt="An image of the project with the green led on" width=60% height=60%>  
