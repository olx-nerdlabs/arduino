int boton1 = 2;
int boton2 = 3;
int boton3 = 4;
int boton4 = 5;
 
int led1 = 9;
int led2 = 10;
int led3 = 11;
int led4 = 12;
void setup(){
    pinMode(boton1, INPUT);
    pinMode(boton2, INPUT);
    pinMode(boton3, INPUT);
    pinMode(boton4, INPUT);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
}
 
void loop(){
     digitalWrite(led1, digitalRead(boton1));
     digitalWrite(led2, digitalRead(boton2));
     digitalWrite(led3, digitalRead(boton3));
     digitalWrite(led4, digitalRead(boton4));
}
