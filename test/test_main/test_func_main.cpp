#include <unity.h>
#include <Arduino.h>
#include "main.h"
#include "gpio.h"

using namespace fakeit;

void setUp(void) {
    // set stuff up here
}

void test_freq_output_mode(void){
    uint8_t mode;

    When(Method(ArduinoFake(), analogRead)).AlwaysReturn(500);

    /*Read Analog Value*/
    uint16_t value = analogRead(DETECT_MODE_PIN);

    Verify(Method(ArduinoFake(), analogRead).Using(DETECT_MODE_PIN)).Once();

    /*Evaluate Value*/
    if(value < VALUE_BTWN_MODE0_MODE1)
        mode = 0;
    else if(value >= VALUE_BTWN_MODE0_MODE1 && value < VALUE_BTWN_MODE1_MODE2)
        mode = 1;
    else 
        mode = 2;

    TEST_ASSERT_EQUAL_MESSAGE(mode,1,"Mode not asigned");
}

void test_generate_wave_mode0(void){

    uint8_t pulse_detected = true;
    uint8_t cant_pulses_mode = NUM_PULSES_MODE0;
    uint8_t num_pulses = 0;
    uint8_t pulses_positive = 0;
    uint8_t pulses_negative = 0;

    for(int i = 0; i < 9; i++){
        pulse_detected = true;
        if(pulse_detected == true){
            /*Alternate SCR Bridges*/
            if(num_pulses < cant_pulses_mode){
                num_pulses++; // Count Pulse
                pulses_positive++; //activate_positive_half();
            }
            else{
                pulses_negative++; //activate_negative_half();
                if(pulses_negative == NUM_PULSES_MODE0){
                    num_pulses = 0;
                    pulses_positive = 0;
                    pulses_negative = 0;
                }
            }
            /*Set Variable Pulses Detected*/
            pulse_detected = false;
        }
    }
    TEST_ASSERT_EQUAL(6, pulses_positive);
    TEST_ASSERT_EQUAL(3, pulses_negative);

}

void tearDown(void) {
    // clean stuff up here
}

int main(void){

    UNITY_BEGIN();

    RUN_TEST(test_freq_output_mode);
    RUN_TEST(test_generate_wave_mode0);

    UNITY_END(); // stop unit testing

    return 0;


}