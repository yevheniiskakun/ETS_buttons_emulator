#include <Keyboard.h>


const int buttonPin8 = 8;     // the number of the pushbutton pin

// variables will change:
int button8State = 0;         // variable for reading the pushbutton status


void setup() {
  //Serial.begin(9600);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin8, INPUT);
  Keyboard.begin();
}
void loop() {
  // read the state of the pushbutton value:
  
  button8State = digitalRead(buttonPin8);
  // if it is, the buttonState is HIGH:
  if (button8State == HIGH) {
    // turn LED on:
    //Serial.println("button 8 on");
    Keyboard.press('E');
    Keyboard.releaseAll();
    button8State = LOW;
    delay(500);
    
  }
 
  // Added the delay so that we can see the output of button
}
