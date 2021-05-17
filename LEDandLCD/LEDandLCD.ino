// include the library code:
#include <ShiftedLCD.h>
#include <SPI.h>

// initialize the library with the number of the sspin 
// (or the latch pin of the 74HC595)
LiquidCrystal lcd(10);

int led1 = 1;
int led2 = 2;
int led3 = 3;
int led4 = 4;
int led5 = 5;
int led6 = 6;
int buttonPin = 7;
int speedPin = 9;
int dir1 = 8;
int dir2 = 12;
int mSpeed = 200;
int buttonState;
int currentState = 0;
int oldState = 0;
int desired;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(buttonPin, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 1);
  lcd.print("desired:");
  lcd.setCursor(0, 0);
  lcd.print("current:");
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin); // Read whether or not the button is on or off
  if (buttonState == 1){ //button has been pressed
    delay(50);
    buttonState = digitalRead(buttonPin);
    if (buttonState == 0){//button pressed once
       currentState = oldState + 1;
    }
  }
  else {
    delay(100);
  }
  switch (currentState) {
    case 1:
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    lcd.setCursor(0, 1);
    lcd.print("desired: 82");
    desired = 82;
    oldState = currentState;
    break;

    case 2:
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    lcd.setCursor(0, 1);
    lcd.print("desired: 110");
    desired = 110;
    oldState = currentState;
    break;
    
    case 3:
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    lcd.setCursor(0, 1);
    lcd.print("desired: 147");
    desired = 147;
    oldState = currentState;
    break;

    case 4:
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    lcd.setCursor(0, 1);
    lcd.print("desired: 196");
    oldState = currentState;
    break;

    case 5:
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, LOW);
    lcd.setCursor(0, 1);
    lcd.print("desired: 247");
    oldState = currentState;
    break;

    case 6:
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("desired: 330");
    oldState = currentState;
    break;
    
    default:
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    lcd.setCursor(0, 1);
    lcd.print("desired:    ");
    oldState = 0;
    break;
  }
}
