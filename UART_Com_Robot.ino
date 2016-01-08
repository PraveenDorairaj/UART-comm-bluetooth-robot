
 
#include <AFMotor.h>

// DC motor on M1
AF_DCMotor motor(1);
// DC motor on M2
AF_DCMotor motor2(2);
// DC motor on M3
AF_DCMotor motor3(3);
// DC motor on M4
AF_DCMotor motor4(4);

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  
  motor.setSpeed(0);
  motor.run(RELEASE);
  
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  
  motor4.setSpeed(0);
  motor4.run(RELEASE);
  
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    Serial.println(inputString);
    // clear the string:
    if (inputString == "forwards" || inputString == "Forwards"){
        motor.run(FORWARD);
        motor2.run(FORWARD);
        motor3.run(FORWARD);
        motor4.run(FORWARD);
  
        motor.setSpeed(300); 
        motor2.setSpeed(300);
        motor3.setSpeed(300);
        motor4.setSpeed(300); 
        delay(10000);
        motor.setSpeed(0); 
        motor2.setSpeed(0);
        motor3.setSpeed(0);
        motor4.setSpeed(0);
    } else if (inputString == "backwards" || inputString == "Backwards"){
        motor.run(BACKWARD);
        motor2.run(BACKWARD);
        motor3.run(BACKWARD);
        motor4.run(BACKWARD);
  
        motor.setSpeed(255); 
        motor2.setSpeed(255);
        motor3.setSpeed(255);
        motor4.setSpeed(255); 
        delay(10000);
        motor.setSpeed(0); 
        motor2.setSpeed(0);
        motor3.setSpeed(0);
        motor4.setSpeed(0);
        
    } else if (inputString == "lefts" || inputString == "Lefts"){
        motor.run(FORWARD);
        motor2.run(FORWARD);
        motor3.run(BACKWARD);
        motor4.run(BACKWARD);
  
        motor.setSpeed(255); 
        motor2.setSpeed(255);
        motor3.setSpeed(255);
        motor4.setSpeed(255); 
        delay(10000);
        motor.setSpeed(0); 
        motor2.setSpeed(0);
        motor3.setSpeed(0);
        motor4.setSpeed(0);
        
    }else if (inputString == "rights" || inputString == "Rights"){
        motor.run(BACKWARD);
        motor2.run(BACKWARD);
        motor3.run(FORWARD);
        motor4.run(FORWARD);
  
        motor.setSpeed(255); 
        motor2.setSpeed(255);
        motor3.setSpeed(255);
        motor4.setSpeed(255); 
        delay(10000);
        motor.setSpeed(0); 
        motor2.setSpeed(0);
        motor3.setSpeed(0);
        motor4.setSpeed(0);
        
    }
    delay(100);
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == 's') {
      stringComplete = true;
    }
  }
}


