// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  // LED 1
  digitalWrite(1, HIGH);
  digitalWrite(2, LOW);
  delay(100);
  
  // LED 2
  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);
  delay(100);
  
  pinMode(1, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  
  // LED 3
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  delay(100);
  
  // LED 4
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(100);
  
  pinMode(1, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  
  // LED 5
  digitalWrite(3, HIGH);
  digitalWrite(1, LOW);
  delay(100);
  
  // LED 6
  digitalWrite(3, LOW);
  digitalWrite(1, HIGH);
  delay(100);
}
