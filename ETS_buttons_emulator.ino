#include <Keyboard.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// ----------Settings----------- 
int long_start = 0;

const int buttonPin8 = 8;
// ------------------------------
unsigned long actual_time = 0;
unsigned long first_timer = 0;
unsigned long second_timer = 0;


int engine_status_flag = 0;

int hours = 0;
int minutes = 0;
int seconds = 0;

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

byte Filled[8] =
{
0b11111,
0b11111,
0b11111,
0b11111,
0b11111,
0b11111,
0b11111,
0b11111
};

     // the number of the pushbutton pin

// variables will change:
int button8State = 0;         // variable for reading the pushbutton status


void setup() {
  actual_time = millis();
  //Serial.begin(9600);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin8, INPUT);
  Keyboard.begin();

  lcd.init();                      // initialize the lcd 
  lcd.backlight();                  // turn on the backlight
  
  greeting();
}
void loop() {
  actual_time = millis();
  // Read button state from 8 digital pin
  button8State = digitalRead(buttonPin8);
  
  if (button8State == HIGH && engine_status_flag == 0) {
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("Ignition ON");
    lcd.setCursor(3,1);
    lcd.print("Engine ON");
    Keyboard.press('E');    // keyboard press
    Keyboard.releaseAll();
    button8State = LOW;
    engine_status_flag = 1;
    delay(2000);
    lcd.clear();   
  }
  else if(button8State == HIGH && engine_status_flag == 1){
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("Ignition OFF");
    lcd.setCursor(3,1);
    lcd.print("Engine OFF");
    Keyboard.press('E');    // keyboard pressEE
    Keyboard.releaseAll();
    button8State = LOW;
    engine_status_flag = 0;
    delay(2000);
    lcd.clear(); 
  }
  
  always_on_display();
  
}

void greeting(){
  lcd.setCursor(0,0);
  lcd.print("Konichiwaa");
  
  lcd.createChar(0, Heart);
  lcd.setCursor(11,0);
  lcd.write(byte(0));
  delay(2000);
  lcd.clear(); 
  
  if(long_start){
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
  }
  lcd.setCursor(1,0);
  lcd.print("Enjoy the ride");
  delay(3000);
  lcd.clear();   
}

void always_on_display(){
  stopwatch();
 
}

void stopwatch(){
  if (actual_time - first_timer >= 1000UL) {
    //Zapamietaj aktualny czas
    first_timer = actual_time;
    
    if (seconds > 59){
      minutes++;
      seconds = 0;
      lcd.clear();
    }
    if(minutes == 60){
      hours++;
      minutes = 0;
      lcd.clear();
    }
    seconds++;
    // stopwatch location
    lcd.setCursor(0,0);
    lcd.print("Trip time: ");
    if(hours < 10){
      lcd.print("0");
    }
    lcd.print(hours);
    lcd.print(":");
    if(minutes < 10){
      lcd.print("0");
    }
    lcd.print(minutes);
  }
  
}
