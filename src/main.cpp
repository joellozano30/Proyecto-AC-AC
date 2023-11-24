#include <Arduino.h>
#include "gpio.h"
#include "main.h"

uint8_t pulse_detected = false;
uint8_t num_pulses = 0;
uint8_t mode = 0;
uint8_t new_mode = 0;
uint8_t print_mode = false;
uint8_t pulses_positive = 0;
uint8_t pulses_negative = 0;

void generate_wave(uint8_t cant_pulses_mode){

  if(pulse_detected == true){
    /*Alternate SCR Bridges*/
    if(num_pulses < cant_pulses_mode){
      num_pulses++; // Count Pulse
      pulses_positive++; //
      activate_positive_half();
    }
    else{
      pulses_negative++; //
      activate_negative_half();
      if(pulses_negative >= (cant_pulses_mode)){
        num_pulses = 0;
        pulses_positive = 0;
        pulses_negative = 0;
      }
    }
    /*Set Variable Pulses Detected*/
    pulse_detected = false;
  }
}

void set_freq_output(){
  /*Read Analog Value*/
  int value = analogRead(DETECT_MODE_PIN);
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
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(DCZ_PIN), detect_pulse, CHANGE);
  Serial.println("Setup finished");
}

void loop(){
  set_freq_output();
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

