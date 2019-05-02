# Arduino Ultrasonic LCD Project
###### by royal_Panic
---
## Introduction:
This is a simple project that allows an ultrasonic sensor to interface with an LCD screen through a simple Arduino sketch. This project makes use of the `NewPing` and `LiquidCrystal` libraries.

## Step One: Software Preparations
Firstly, we're going to have to make sure we have all the Arduino libraries we need in order to make this project work. The `LiquidCrystal` library came as default in my version of the Arduino IDE (version 1.8.9), but I had to download and install the `NewPing` library on my own.

To do this, you should first head to [this site](https://bitbucket.org/teckel12/arduino-new-ping/downloads/) and grab the `.zip` of the latest version of the library. After, you're going to want to open up the IDE and navigate to the "Sketch" menu. Once there, you're going to want to go to "Include Library". Continue to "Add .zip Library" Then, navigate to the `.zip` file of the library you just downloaded, and finish the prompt. Now if we return to the "Include Library" dropdown, we see that the `NewPing` library is listed at the bottom of the menu, ready to be used.

## Step Two: Hardware Preparations
### Materials:
First, you'll need the following to make this work:
* One `HC-SR04` ultrasonic sensor
* One 2x16 LCD with pin connections
* One 10k potentiometer
* One breadboard
* Twenty Male-to-Male pin cables (you can use any lengths or colours you want, but for visual simplicity I broke it down by colour)
 * Six Red cables
 * Five Black cables
 * One Light Blue cable
 * Six Orange cables
 * Two Blue cables

## Wiring:
* LCD VSS pin to Arduino GND
* LCD VDD pin to Arduino 5V
* LCD VO pin to 10k Potentiometer center pin
* LCD RS pin to digital pin 1
* LCD RW pin to Arduino GND
* LCD Enable pin to digital pin 2
* LCD D4 pin to digital pin 4
* LCD D5 pin to digital pin 5
* LCD D6 pin to digital pin 6
* LCD D7 pin to digital pin 7
* The 10k Potentiometer’s other legs connect to +5V and GND
* For the backlight of the display, pin 15 (A+) and 16 (K-) of the LCD connect to +5V and GND

![Wiring Diagram](https://github.com/royalPanic/Arduino-Ultrasonic-LCD/blob/master/Wiring_Diagram.png)

## Step Three: Coding
Now's where we get to part where we can plug the Arduino into your computer. We'll open up the IDE and start a new sketch. Copy and paste the following into your sketch, and save it.
```c++
#include <NewPing.h>
#include <LiquidCrystal.h>
#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 350
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);
void setup() {
    lcd.begin(16,2);
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}
void loop() {
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);
    lcd.setCursor(0,0);
    lcd.print("Distance: ");
    lcd.print(sonar.ping_in());
    lcd.print("  inches");
    delay(50);
}
```
Then, we can verify and upload the sketch, and watch your LCD come to life as the ultrasonic sensor sends out its first ping.
