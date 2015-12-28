import processing.serial.*;

Serial myPort; // The serial port
int xPos = 1; // horizontal position of the graph

void setup () {
  // set the window size:
  size(400, 400); 

  // List all the available serial ports
  println(Serial.list());
  // Open whatever port is the one you're using for the Launchpad.
  myPort = new Serial(this, Serial.list()[2], 9600);
  // don't generate a serialEvent() unless you get a newline character:
  myPort.bufferUntil('\n');
  // set inital background:
  background(0);
}
void draw () {
  // everything happens in the serialEvent()
}

void serialEvent (Serial myPort) {
  // get the ASCII string:
  String inString = myPort.readStringUntil('\n');
  


  if (inString != null) {
    delay(100);
    clear();
    // trim off any whitespace:
    inString = trim(inString);
    // convert radius from a string to a float 
    float inByte = float(inString); 

    // draw the ellipse
    stroke(255,0,0);
    fill(255,0,0);
    ellipse(200, 200, inByte, inByte);
    
  
  }
}

