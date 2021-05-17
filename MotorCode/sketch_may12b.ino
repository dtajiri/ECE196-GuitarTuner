int speedPin = 10;
int dir1 = 8;
int dir2 = 12;
int mSpeed = 200;

void setup() {
  // put your setup code here, to run once:
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  Serial.begin(96000);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,HIGH);
  analogWrite(speedPin, mSpeed);

  delay(6120);
  
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  analogWrite(speedPin, mSpeed); 

  delay(6120);
}
