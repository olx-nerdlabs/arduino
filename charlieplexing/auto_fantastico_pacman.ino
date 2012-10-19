void playTone(int tone) {
  int duration = 25;
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(9, HIGH);
    delayMicroseconds(tone);
    digitalWrite(9, LOW);
    delayMicroseconds(tone);
  }
}


void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, INPUT);

  // 1
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  playTone(1915);  

  // 2
  digitalWrite(3, HIGH);
  digitalWrite(2, LOW);
  playTone(1700); 

  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  // 3
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  playTone(1519); 

  // 4
  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);
  playTone(1432);   

  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);

  // 5
  digitalWrite(4, HIGH);
  digitalWrite(2, LOW);
  playTone(1275);   

  // 6
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
  playTone(1136);

  // 5 (vuelta)
  digitalWrite(4, HIGH);
  digitalWrite(2, LOW);
  playTone(1275);

  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  // 4 (vuelta)
  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);
  playTone(1432);   

  // 3 (vuelta)
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  playTone(1519); 

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, INPUT);

  // 2 (vuelta)
  digitalWrite(3, HIGH);
  digitalWrite(2, LOW);
  playTone(1700); 
}
