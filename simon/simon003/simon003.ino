/* vim: set ft=c : */


#define LEDS 2
#define SEQ_LEN 5

const int speaker = 12;

const int leds[LEDS] = {4, 6};
const int buttons[LEDS] = {8, 10};
const int tones[LEDS] = {880, 1480};

int seq[SEQ_LEN];


void setup() {

    for (int i = 0; i < LEDS; i++) {
        pinMode(leds[i], OUTPUT);
        pinMode(buttons[i], INPUT);
    }
    pinMode(speaker, OUTPUT);

    /* Gen and show sequence */
    randomSeed(analogRead(0));
    for (int i = 0; i < SEQ_LEN; i++) {
        seq[i] = random(LEDS);
        digitalWrite(leds[seq[i]], HIGH);
        tone(speaker, tones[seq[i]]);
        delay(500);
        digitalWrite(leds[seq[i]], LOW);
        noTone(speaker);
        delay(500);
    }

}

void loop() {

    bool done;

    for (int i = 0; i < LEDS; i++) {
        done = false;
        while (digitalRead(buttons[i]) == HIGH) {
            if (!done) {
                digitalWrite(leds[i], HIGH);
                tone(speaker, tones[i]);
                done = true;
            }
        }
        digitalWrite(leds[i], LOW);
        noTone(speaker);
    }

}


