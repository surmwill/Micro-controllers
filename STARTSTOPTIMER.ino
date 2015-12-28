#include <LiquidCrystal.h> // include library for lcd
LiquidCrystal lcd(P2_0, P2_1, P2_2, P2_3, P2_4, P2_5); // define the ports
const int push = PUSH2; //variable for the push button
int time; //current time
int pauseTime; //pause time
int subValue = 0; //amount to subtract from the current time
int toggle = 0; //toggle for the push button

void setup()
{
  //intialize the screen
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Elapsed time: ");
  
  //assign the button variable to the button port
  pinMode(push, INPUT_PULLUP);   
  //interrupt to run myISR function when the button is pressed
  attachInterrupt(push, myISR, FALLING);
}

void loop() 
{
   //if the toggle is 1 
   if(toggle == 1)
   {
     //get and print the time
     lcd.setCursor(0, 1);
     time = millis() - subValue; //minus the subValue if we previously stopped the timer
     lcd.print(time/1000);
     lcd.print(".");
     lcd.print(time - ((time/1000)*1000));
   }
   else
   {
     //print the time but stop fetching the time every cycle
     lcd.setCursor(0, 1);
     lcd.print(time/1000);
     lcd.print(".");
     lcd.print(time - ((time/1000)*1000));
   }

}

//if the button is pressed
void myISR()
{
  //if the toggle is 0
   if(toggle == 0)
   {
     //set the toggle to 1
     toggle = 1;
     //get the time
     pauseTime = millis();
     //the value we need to subtract to remain with the same time after the
     // the time is resumed is equal to the current millis minus the time we had when
     //we paused 
     subValue = pauseTime - time;
   }
   //if the toggle is 1 then set it to 0
   else if(toggle == 1) toggle = 0;
}
