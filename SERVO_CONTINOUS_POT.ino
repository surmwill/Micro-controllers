#include <Servo.h>  //servo library
#include <LiquidCrystal.h> 
 
Servo myservo;  //servo object
 
void setup() 
{ 
    myservo.attach(4);  // servo is 4 pins down
    pinMode(P1_1, INPUT); //set pin 1 to input
} 
 
 
void loop() 
{    
    // map the analog input to a value from 0 to 180
    int x = analogRead(P1_1);
    x = map(x, 0, 1023, 0, 180);
    myservo.write(x); //set the servo to the previous calculated value                                                                  
} 

