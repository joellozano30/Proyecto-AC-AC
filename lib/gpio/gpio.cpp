#include "gpio.h"

void gpio_init(void){
    /*DCZ*/
    pinMode(DCZ_PIN, INPUT);
    /*SCRx Pulses*/
    pinMode(PULSE1, OUTPUT);
    pinMode(PULSE2, OUTPUT);
    pinMode(PULSE3, OUTPUT);
    pinMode(PULSE4, OUTPUT);
    pinMode(PULSE5, OUTPUT);
    pinMode(PULSE6, OUTPUT);
    pinMode(PULSE7, OUTPUT);
    pinMode(PULSE8, OUTPUT);
    /*Pin to detect mode*/
    /*Mode 0 - 10Hz*/
    /*Mode 1 - 20Hz*/
    /*Mode 2 - 30Hz*/
    /*Mode 4 - 40Hz*/
    pinMode(DETECT_MODE_PIN, INPUT);
}

void activate_positive_half(void){
    /*Generate Pulses*/
    digitalWrite(PULSE1, HIGH);
    digitalWrite(PULSE2, HIGH);
    digitalWrite(PULSE3, HIGH);
    digitalWrite(PULSE4, HIGH);
    delay(PULSE_WIDTH);
    digitalWrite(PULSE1, LOW);
    digitalWrite(PULSE2, LOW);
    digitalWrite(PULSE3, LOW);
    digitalWrite(PULSE4, LOW);
    delay(PULSE_WIDTH);
}

void activate_negative_half(void){
    /*Generate Pulses*/
    digitalWrite(PULSE5, HIGH);
    digitalWrite(PULSE6, HIGH);
    digitalWrite(PULSE7, HIGH);
    digitalWrite(PULSE8, HIGH);
    delay(PULSE_WIDTH);
    digitalWrite(PULSE5, LOW);
    digitalWrite(PULSE6, LOW);
    digitalWrite(PULSE7, LOW);
    digitalWrite(PULSE8, LOW);
    delay(PULSE_WIDTH);
}

