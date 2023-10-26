#include <Arduino.h>
#include "gpio.h"

#define NUM_PULSES_MODE0 6
#define NUM_PULSES_MODE1 3
#define NUM_PULSES_MODE2 2

#define VALUE_BTWN_MODE0_MODE1 256
#define VALUE_BTWN_MODE1_MODE2 768

uint8_t pulse_detected = false;
uint8_t num_pulses = 0;
uint8_t mode = 0;

void generate_wave(uint8_t cant_pulses_mode){
  if(pulse_detected == true){
    /*Count Pulses*/
    if(num_pulses < cant_pulses_mode)
      num_pulses++;
    else
      num_pulses = 0;
    /*Alternate SCR Bridges*/
    if(num_pulses < cant_pulses_mode)
      activate_positive_half();
    else
      activate_negative_half();
    /*Set Variable Pulses Detected*/
    pulse_detected = false;
  }
}

void set_freq_output(){
  /*Read Analog Value*/
  uint8_t value = analogRead(DETECT_MODE_PIN);
  /*Evaluate Value*/
  if(value < VALUE_BTWN_MODE0_MODE1)
    mode = 0;
  else if(value >= VALUE_BTWN_MODE0_MODE1 && value < VALUE_BTWN_MODE1_MODE2)
    mode = 1;
  else 
    mode = 2;
}

void detect_pulse(){
  pulse_detected = true;
}

void setup(){
  gpio_init();
  attachInterrupt(digitalPinToInterrupt(DCZ_PIN), detect_pulse, RISING);
}

void loop(){
  switch(mode){
    case 0: /*10 Hz*/
      generate_wave(NUM_PULSES_MODE0);
      break;
    case 1: /*20 Hz*/
      generate_wave(NUM_PULSES_MODE1);
      break;
    case 2: /*30 Hz*/
      generate_wave(NUM_PULSES_MODE2);
    default:
      break;
  }
}

