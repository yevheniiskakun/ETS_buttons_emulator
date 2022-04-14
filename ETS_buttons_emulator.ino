#include <Keyboard.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int engine_status_flag = 0;

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

byte Heart[8] = {
0b00000,
0b01010,
0b11111,
0b11111,
0b01110,
0b00100,
0b00000,
0b00000
};

const int buttonPin8 = 8;     // the number of the pushbutton pin

// variables will change:
int button8State = 0;         // variable for reading the pushbutton status


void setup() {
  //Serial.begin(9600);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin8, INPUT);
  Keyboard.begin();

  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Konichiwaa");
  
  lcd.createChar(0, Heart);
  lcd.setCursor(11,0);
  lcd.write(byte(0));
  delay(2000);
  lcd.clear(); 
  

  lcd.setCursor(2,0);
  lcd.print("Please wait");
  for(int i = 0; i <= 16; i++){
    lcd.setCursor(i,1);
    lcd.print("-");
    delay(500);
  }
  lcd.clear(); 
  lcd.setCursor(5,0);
  lcd.print("Done");
  delay(2000);
  lcd.clear(); 
  lcd.setCursor(1,0);
  lcd.print("Enjoy the ride");
  delay(3000);
  lcd.clear();   
}
void loop() {
  // Read button state from 8 digital pin
  button8State = digitalRead(buttonPin8);
  
  if (button8State == HIGH && engine_status_flag == 0) {
    lcd.setCursor(2,0);
    lcd.print("Ignition ON");
    lcd.setCursor(3,1);
    lcd.print("Engine ON");
    button8State = LOW;
    engine_status_flag = 1;
    delay(2000);
    lcd.clear();   
  }
  else if(button8State == HIGH && engine_status_flag == 1){
    lcd.setCursor(2,0);
    lcd.print("Ignition OFF");
    lcd.setCursor(3,1);
    lcd.print("Engine OFF");
    button8State = LOW;
    engine_status_flag = 0;
    delay(2000);
    lcd.clear(); 
  }
  /*
  
  
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

void greeting(){
  
}

void always_on_display(){

  
}
