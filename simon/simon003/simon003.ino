/* vim: set ft=c : */


#define LEDS 4
#define SEQ_LEN 5

const int speaker = 12;

const int leds[LEDS] = {4, 5, 6, 7};
const int buttons[LEDS] = {8, 9, 10, 11};
const int tones[LEDS] = {1519, 1432, 1275, 1136};

int seq[SEQ_LEN];


void turn_on(int led) {
    digitalWrite(leds[led], HIGH);
    tone(speaker, tones[led]);
}

void turn_off(int led) {
    digitalWrite(leds[led], LOW);
    noTone(speaker);
}

void start() {
    for (int i = 0; i < LEDS; i++) {
        turn_on(i);
        delay(50);
        turn_off(i);
        delay(50);
    }
}

void turn_on_all() {
    for (int i = 0; i < LEDS; i++) {
        turn_on(i);
    }
}

void turn_off_all() {
    for (int i = 0; i < LEDS; i++) {
        turn_off(i);
    }
}

void win() {
    for (int i = 0; i < 5; i++) {
        turn_on_all();
        tone(speaker, 956);
        delay(50);
        turn_off_all();
        delay(50);
    }
}

void lose() {
    turn_on_all();
    tone(speaker, 1915);
    delay(1000);
    turn_off_all();
}

void setup() {

    for (int i = 0; i < LEDS; i++) {
        pinMode(leds[i], OUTPUT);
        pinMode(buttons[i], INPUT);
    }
    pinMode(speaker, OUTPUT);

    start();
    delay(100);

    /* Gen and show sequence */
    randomSeed(analogRead(0));
    for (int i = 0; i < SEQ_LEN; i++) {
        seq[i] = random(LEDS);
    }

}


char status = 's'; // s = show; p = play; l = lose; w = win
int index = -1;
int push_index;

void show_sequence() {
    index++;
    delay(500);
    for (int i = 0; i <= index; i++) {
        turn_on(seq[i]);
        delay(250);
        turn_off(seq[i]);
        delay(250);
    }
}


void loop() {

    switch (status) {
        case 's':
            show_sequence();
            push_index = 0;
            status = 'p';
            break;

        case 'p':
            bool push;

            for (int i = 0; i < LEDS; i++) {
                push = false;
                while (digitalRead(buttons[i]) == HIGH) {
                    if (!push) {
                        turn_on(i);
                        push = true;

                        if (i == seq[push_index]) {
                            if (push_index == (SEQ_LEN - 1)) {
                                status = 'w';
                            }
                            else if (push_index == index) {
                                    status = 's';
                            }
                            push_index++;
                        }
                        else {
                            status = 'l';
                        }

                    }
                }
                if (push) {
                    turn_off(i);
                }
            }
            delay(10);
            break;

        case 'l':
            lose();
            status = 'x';
            break;

        case 'w':
            win();
            status = 'x';
            break;
    }


}


