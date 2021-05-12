int led13 = 13;
int led12 = 12;
int led11 = 11;
int led10 = 10;
int led9 = 9;
int led8 = 8;
int buttonPin = 7;
int buttonState;
int currentState = 0;
int oldState = 0;

void setup() {
  pinMode(led13,OUTPUT);
  pinMode(led12,OUTPUT);
  pinMode(led11,OUTPUT);
  pinMode(led10,OUTPUT);
  pinMode(led9,OUTPUT);
  pinMode(led8,OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
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
    digitalWrite(led13, HIGH);
    digitalWrite(led12, LOW);
    digitalWrite(led11, LOW);
    digitalWrite(led10, LOW);
    digitalWrite(led9, LOW);
    digitalWrite(led8, LOW);
    oldState = currentState;
    break;

    case 2:
    digitalWrite(led13, LOW);
    digitalWrite(led12, HIGH);
    digitalWrite(led11, LOW);
    digitalWrite(led10, LOW);
    digitalWrite(led9, LOW);
    digitalWrite(led8, LOW);
    oldState = currentState;
    break;
    
    case 3:
    digitalWrite(led13, LOW);
    digitalWrite(led12, LOW);
    digitalWrite(led11, HIGH);
    digitalWrite(led10, LOW);
    digitalWrite(led9, LOW);
    digitalWrite(led8, LOW);
    oldState = currentState;
    break;

    case 4:
    digitalWrite(led13, LOW);
    digitalWrite(led12, LOW);
    digitalWrite(led11, LOW);
    digitalWrite(led10, HIGH);
    digitalWrite(led9, LOW);
    digitalWrite(led8, LOW);
    oldState = currentState;
    break;

    case 5:
    digitalWrite(led13, LOW);
    digitalWrite(led12, LOW);
    digitalWrite(led11, LOW);
    digitalWrite(led10, LOW);
    digitalWrite(led9, HIGH);
    digitalWrite(led8, LOW);
    oldState = currentState;
    break;

    case 6:
    digitalWrite(led13, LOW);
    digitalWrite(led12, LOW);
    digitalWrite(led11, LOW);
    digitalWrite(led10, LOW);
    digitalWrite(led9, LOW);
    digitalWrite(led8, HIGH);
    oldState = currentState;
    break;
    
    default:
    digitalWrite(led13, LOW);
    digitalWrite(led12, LOW);
    digitalWrite(led11, LOW);
    digitalWrite(led10, LOW);
    digitalWrite(led9, LOW);
    digitalWrite(led8, LOW);
    oldState = 0;
    break;
  }
}
