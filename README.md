# Arduino Ultrasonic LCD Project
###### by royal_Panic
---
## Introduction:
This is a simple project that allows an ultrasonic sensor to interface with an LCD screen through a simple Arduino sketch. This project makes use of the `NewPing` and `LiquidCrystal` libraries.

## Step One: Software Preparations
Firstly, we're going to have to make sure we have all the Arduino libraries we need in order to make this project work. The `LiquidCrystal` library came as default in my version of the Arduino IDE (version 1.8.9), but I had to download and install the `NewPing` library on my own.

To do this, you should first head to [this site](https://bitbucket.org/teckel12/arduino-new-ping/downloads/) and grab the `.zip` of the latest version of the library. After, you're going to want to open up the IDE and navigate to the "Sketch" menu. Once there, you're going to want to go to "Include Library". Continue to "Add .zip Library" Then, navigate to the `.zip` file of the library you just downloaded, and finish the prompt. Now if we return to the "Include Library" dropdown, we see that the `NewPing` library is listed at the bottom of the menu, ready to be used.

## Step Two: Hardware Preparations
First, you'll need the following to make this work:
* One `HC-SR04` ultrasonic sensor
* One 2x16 LCD with pin connections
* One 10k Potentiometer
