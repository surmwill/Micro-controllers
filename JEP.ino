#include <LiquidCrystal.h> //include the library for the lcd display
 
// define the pins
LiquidCrystal lcd(P2_0, P2_1, P2_2, P2_3, P2_4, P2_5);
int endGame = 0;
void setup()
{
  //define the ports for the push buttons
  pinMode(P1_1, INPUT_PULLUP);
  pinMode(P1_2, INPUT_PULLUP);
  pinMode(P1_7, INPUT_PULLUP);
  pinMode(P1_3, INPUT_PULLUP);
  
  //define columns and rows for lcs 
  lcd.begin(16, 2);
  
  //attach intterupt to buttons
  attachInterrupt(P1_1, p2, RISING);
  attachInterrupt(P1_2, p1, RISING);
  attachInterrupt(P1_7, p3, RISING);
  attachInterrupt(P1_3, reset, RISING); //reset button
  
  //set the cursor to the top right
  lcd.setCursor(0, 0);
  lcd.print("Waiting...");
  
}
 
void loop()
{
  
  
}
void p1()
{
  if(endGame ==0 )
  {
    //print that player 1 won
     lcd.setCursor(0, 0);
     lcd.print("Player 1 Chosen!");
     
     //nobody else can answer
     endGame = 1;
  }
 
}

//same only for player 2
void p2()
{
  if(endGame == 0)
  {
     lcd.setCursor(0, 0);
     lcd.print("Player 2 Chosen!");
     endGame = 1;
  }
}

//same only for player 3
void p3()
{
  if(endGame == 0)
  {
     lcd.setCursor(0, 0);
     lcd.print("Player 3 Chosen!");
     endGame = 1;
  }
}

//reset the game
void reset()
{
  //If someone won
  if(endGame == 1)
  {
     lcd.clear(); //clear the screen
     lcd.setCursor(0, 0); //reset the display to waiting...
     lcd.print("Waiting....");
     
     //reset inputs 
     endGame = 0;
     
  }
}
