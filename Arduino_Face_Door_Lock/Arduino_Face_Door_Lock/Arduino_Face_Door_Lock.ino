#include <cvzone.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 
SerialData serialData(1,1);
int valsRec[1];
int lock = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  serialData.begin();

  pinMode(2,OUTPUT);
  digitalWrite(2,1);
}

void loop() {

  serialData.Get(valsRec);
  lock = valsRec[0];
  lcd.setCursor(2,0);
  if (lock ==0){
    lcd.print("Door Closed");
    digitalWrite(2,1);
  }
  else if (lock ==1){
       lcd.print("Door Opened");
    digitalWrite(2,0);
  }
  }
