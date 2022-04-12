const int buttonPin8 = 8;     // the number of the pushbutton pin
const int buttonPin9 = 9;     // the number of the pushbutton pin
const int buttonPin10 = 10;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
// variables will change:
int button8State = 0;         // variable for reading the pushbutton status
int button9State = 0; 
int button10State = 0; 

void setup() {
  Serial.begin(9600);
 
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin8, INPUT);
  pinMode(buttonPin9, INPUT);
  pinMode(buttonPin10, INPUT);
}
void loop() {
  // read the state of the pushbutton value:
  button8State = digitalRead(buttonPin8);
  button9State = digitalRead(buttonPin9);
  button10State = digitalRead(buttonPin10);
  // Show the state of pushbutton on serial monitor
  Serial.print(button8State);
  Serial.print(", ");
  Serial.print(button9State);
  Serial.print(", ");
  Serial.println(button10State);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (button8State != HIGH) {
    // turn LED on:
    Serial.println("button 8 on");
  }
  if(button9State != HIGH){
    Serial.println("button 9 on");
  }
  if(button10State != HIGH){
    Serial.println("button 10 on");
  }
 
  // Added the delay so that we can see the output of button
  delay(200);
}
