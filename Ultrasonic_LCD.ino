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
