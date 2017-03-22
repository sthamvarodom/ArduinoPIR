/*
 * PIR sensor tester
 */

int green = 11;
int red = 12;
int blue = 13;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int val = 0;                    // variable for reading the pin status
int iPIR = 0;
 
void setup() {
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(inputPin, INPUT);
 
  Serial.begin(9600);
}
 
void loop(){
  digitalWrite(red, HIGH);
  delay(100);
  digitalWrite(green, HIGH);
  delay(100);
  digitalWrite(blue, HIGH);
  delay(500);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  checkPIR();
  delay(500);
}

void checkPIR() {
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    for(iPIR = 0; iPIR < 10; iPIR++) {
      digitalWrite(blue, HIGH);
      delay(100);
      digitalWrite(blue, LOW);
      delay(100);
    }
  }
}

