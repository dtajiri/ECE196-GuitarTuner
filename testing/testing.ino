// include the library code:
#include <ShiftedLCD.h>
#include <SPI.h>

// initialize the library with the number of the sspin 
// (or the latch pin of the 74HC595)
LiquidCrystal lcd(10);

#include "arduinoFFT.h"
 
#define SAMPLES 128             //SAMPLES-pt FFT. Must be a base 2 number. Max 128 for Arduino Uno.
#define SAMPLING_FREQUENCY 2000 //Ts = Based on Nyquist, must be 2 times the highest expected frequency.
 
arduinoFFT FFT = arduinoFFT();
 
unsigned int samplingPeriod;
unsigned long microSeconds;
 
double vReal[SAMPLES]; //create vector of size SAMPLES to hold real values
double vImag[SAMPLES]; //create vector of size SAMPLES to hold imaginary values
int anaPin = 0;
int digPin = 2;
int digitalValue = 0;
int led1 = A5;
int led2 = A4;
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
int rounded;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Baud rate for the Serial Monitor
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(buttonPin, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 1);
  lcd.print("desired:");
  lcd.setCursor(0, 0);
  lcd.print("current:");
  samplingPeriod = round(1000000*(1.0/SAMPLING_FREQUENCY)); //Period in microseconds 
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
    lcd.print("desired:        ");
    lcd.setCursor(0, 0);
    lcd.print("current:         ");
    oldState = 0;
    break;
  }
  
  digitalValue=digitalRead(digPin);
  Serial.println(digitalValue);
    if(digitalValue==HIGH){ 
      /*Sample SAMPLES times*/
      for(int i=0; i<SAMPLES; i++)
      {
          microSeconds = micros();    //Returns the number of microseconds since the Arduino board began running the current script. 
       
          vReal[i] = analogRead(anaPin); //Reads the value from analog pin 0 (A0), quantize it and save it as a real term.
          vImag[i] = 0; //Makes imaginary term 0 always
  
          /*remaining wait time between samples if necessary*/
          while(micros() < (microSeconds + samplingPeriod))
          {
            //do nothing
          }
      }
   
      /*Perform FFT on samples*/
      FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
      FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
      FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);
  
      /*Find peak frequency and print peak*/
      double peak = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);
      Serial.println(peak);     //Print out the most dominant frequency.
      lcd.setCursor(0, 0);
      lcd.print("current: ");lcd.println(peak);
   }
}
