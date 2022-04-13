#include <Keyboard.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display


const int buttonPin8 = 8;     // the number of the pushbutton pin

// variables will change:
int button8State = 0;         // variable for reading the pushbutton status


void setup() {
  //Serial.begin(9600);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin8, INPUT);
  Keyboard.begin();

  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("konichiwaa");
}
void loop() {
  /*
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
 */

}
