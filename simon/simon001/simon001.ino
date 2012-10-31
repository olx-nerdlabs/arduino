int SPKR = 7;
int LEDS[] = {2, 3, 4, 5};
int BTNS[] = {9, 10, 11, 12};

int FREQS[] = {1300, 1500, 1700, 1900};

void play(int number, int time=0) {
    tone(SPKR, FREQS[number], time);
    digitalWrite(LEDS[number], HIGH);
}
void noplay(int number) {
    noTone(SPKR);
    digitalWrite(LEDS[number], LOW);
}

void setup() {
    for (int i = 0; i < 4; i++) {
        pinMode(LEDS[i], OUTPUT);
        pinMode(BTNS[i], INPUT);
    }
    pinMode(SPKR, OUTPUT);
}

void loop() {
    for (int i = 0; i < 4; i++) {
        int val = digitalRead(BTNS[i]);
        if (val == HIGH) {
            play(i);
        } else {
            noplay(i);
        }
        delay(100);
    }
}


