#include <LiquidCrystal.h>
 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(P2_0, P2_1, P2_2, P2_3, P2_4, P2_5);

#define echoPin P2_7 //echo pin
#define trigPin P1_6 //trig pin
#define led P1_2 //led pin

long duration; //duration for the signal to return
float distance; //distance of the objbect

void setup() {
 lcd.begin(16, 2);
 pinMode(trigPin, OUTPUT); //set trig pin to output
 pinMode(echoPin, INPUT); //set echo pin to input
 pinMode(led, OUTPUT); //set the led to output
 digitalWrite(trigPin, LOW); //intialize the input pin to low
} 
void loop() {
 //delay(500); //wait a seconds
 
 digitalWrite(trigPin, HIGH); //send out a pulse
 delayMicroseconds(10); //wait 10 microseconds
 digitalWrite(trigPin, LOW); //stop sending out the pulse 
 duration = pulseIn(echoPin, HIGH); //Determine the pulse width
 distance = duration/57.01; // Calculate the distance to the object

 if(distance > 30) distance = 0; //if we are ata distance > 30 cut off sound
 else if(distance < 5) distance = 0; //same thing only for distances < 5
 else
 {
   distance = map(distance, 5, 30, 255, 0); //map a distance between 5 and 30cm witha value from 0 to 255
 }
 tone(P1_2, distance); //create the tone
 lcd.clear(); //print the distance for debugging
 lcd.setCursor(0, 0);
 lcd.print(distance);
 lcd.print(" cm");
 
}
