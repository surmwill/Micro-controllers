const int sensLeft = P1_5; //Left sensor connected to P2_1
const int sensCenter = P1_3; //Center sensor connected to P2_2
const int sensRight = P1_4; //Right sensor connected to P2_3

const int leftMotor = P2_1; //left motor
const int rightMotor = P1_6; //right motor

boolean lineLeft; //is the left sensor tripped?
boolean lineCenter;
boolean lineRight;

int hitLeft = 150; //values for whether we are on the black tape
int hitRight = 150;
int hitCenter = 150;

int motorSpeed = 75; //speed for the motor

int prevRight = 0; //were we previously going left or right?
int prevLeft = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop()
{
  // put your main code here, to run repeatedly:
  checkLeft(); //run function checkLeft to check the left sensor
  checkCenter(); //run function checkCenter to check the center sensor
  checkRight(); //run function checkRight to check the right sensor
 
    

   if(lineLeft) //sees if we hit a sensor, if we did turn the other way
   {
     Right();
     prevLeft = 1;
     prevRight = 0;
   }
   
   else if(lineRight)
   {
     Left();
     prevRight = 1;
     prevLeft = 0;
   }
   
   else if(lineCenter)
   {
     Forward();
   }
   
    //if for whatever reason all 3 sensors are off the track keep track of the previous hit to get back on track 
   else if(prevRight == 1) Left();
   else if(prevLeft == 1) Right();
   else 
   {
     analogWrite(leftMotor, 0);
     analogWrite(rightMotor, 0);
   }
}


//**************************  functions  ********************

// motor outputs

//motor speeds for the different directions
void Forward(){
  analogWrite(rightMotor, motorSpeed);
  analogWrite(leftMotor, motorSpeed);
}
void Right(){
  analogWrite(rightMotor, motorSpeed);
  analogWrite(leftMotor, 0);
}
void Left(){
  analogWrite(rightMotor, 0);
  analogWrite(leftMotor, motorSpeed);
}


//sensor checks
void checkLeft() {  //checks if left sensor is over the black line
  long duration = RCTime(sensLeft); //make a variable called duration and make it equal to the output of the left sensor
  Serial.println(duration);
  
  if (duration > hitLeft) lineLeft = true;   //the sensor has been tripped 
  else lineLeft = false;   //otherwise boolean variable lineCenter will be false
}

void checkCenter() {  //checks if center sensor is over the black line
  long duration = RCTime(sensCenter); //make a variable called duration and make it equal to the output of the centor sensor
  Serial.println(duration);
  
  if (duration > hitCenter) lineCenter = true;   
  else lineCenter = false;   //otherwise boolean variable lineCenter will be false
}


void checkRight() {  //checks if right sensor is over the black line
  long duration = RCTime(sensRight); //make a variable called duration and make it equal to the output of the right sensor
  Serial.println(duration);
  
  if (duration > hitRight) lineRight = true;   
  else lineRight = false;   //otherwise boolean variable lineCenter will be false
}

//measure sensor value
long RCTime (int sensorln){ //Code to activate sensors and have them output a value
  long duration = 0;
  pinMode(sensorln, OUTPUT);
  digitalWrite(sensorln, HIGH);
  delay(5);
  pinMode(sensorln, INPUT);
  digitalWrite(sensorln, LOW);
  while(digitalRead(sensorln)){
    duration++;
  }
  return duration;
}
