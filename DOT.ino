#define echoPin P2_7 //echo pin
#define trigPin P1_6 //trig pin


long duration; //duration for the signal to return
float distance; //distance of the objbect

void setup() {
  
  pinMode(trigPin, OUTPUT); //set trig pin to output
 pinMode(echoPin, INPUT); //set echo pin to input
 digitalWrite(trigPin, LOW); //intialize the input pin to low
  // initialize the serial communication:
  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(trigPin, HIGH); //send out a pulse
 delayMicroseconds(10); //wait 10 microseconds
 digitalWrite(trigPin, LOW); //stop sending out the pulse 
 duration = pulseIn(echoPin, HIGH); //Determine the pulse width
  distance = duration/57.01; // Calculate the distance to the object (our radius)
  // send the value of the distance * 5 for the circle to be seeable
  Serial.println(distance * 5);
  // wait a bit to stabilize after the last reading:
  delay(200);
}


