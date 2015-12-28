#include <LiquidCrystal.h>
 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(P2_0, P2_1, P2_2, P2_3, P2_4, P2_5);

#define echoPin P2_7 //echo pin
#define trigPin P1_6 //trig pin

long duration; //duration for the signal to return
float distance; //distance of the objbect

void setup() {
 lcd.begin(16, 2);
 pinMode(trigPin, OUTPUT); //set trig pin to output
 pinMode(echoPin, INPUT); //set echo pin to input
 digitalWrite(trigPin, LOW); //intialize the input pin to low
} 
void loop() {
 delay(1000); //wait a seconds
 
 digitalWrite(trigPin, HIGH); //send out a pulse
 delayMicroseconds(10); //wait 10 microseconds
 digitalWrite(trigPin, LOW); //stop sending out the pulse 
 duration = pulseIn(echoPin, HIGH); //Determine the pulse width
 distance = duration/56.01; // Calculate the distance to the object
 lcd.clear(); //print the distance
 lcd.setCursor(0, 0);
 lcd.print(distance);
 lcd.print(" cm");
 
}
