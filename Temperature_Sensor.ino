#include "LiquidCrystal.h" // include the liquid crystal library
LiquidCrystal lcd(P2_0,P2_1,P2_2,P2_3,P2_4,P2_5);
void setup() {
analogReference(INTERNAL1V5); // the 1.5V internal reference is selected
lcd.begin(16, 2); //
lcd.print("Thermometer"); //Print out a text on the first line,
}
void loop() {
long mysum = 0; //this result is summed
for(int i=0; i<1500; i++) {
mysum += analogRead(A4);
}
float voltage = mysum>>10; //Divide by 1024
float tempC = (voltage-500)/10; //Conversion of a degree
lcd.setCursor(0, 1); //Cursor to the beginning of the second line
lcd.print(tempC,1); //the results are printed
lcd.print(" C");
delay(1000);
}
