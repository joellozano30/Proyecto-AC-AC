#ifndef GPIO_H
#define GPIO_H

#include <Arduino.h>

/*DCZ*/
#define DCZ_PIN 2
/*Positive Half SCRs Converter*/
#define PULSE1 3
#define PULSE2 4
#define PULSE3 5
#define PULSE4 6
/*Negative Half SCRs Converter*/
#define PULSE5 8
#define PULSE6 9
#define PULSE7 10
#define PULSE8 11
/*Detect Mode*/
#define DETECT_MODE_PIN A0
/*Logic States*/
#define true 1
#define false 0
/*Pulse Width*/
#define PULSE_WIDTH 100

void gpio_init(void);
void activate_positive_half(void);
void activate_negative_half(void);

#endif