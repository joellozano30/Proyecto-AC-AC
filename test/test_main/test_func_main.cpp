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

void tearDown(void) {
    // clean stuff up here
}

int main(void){

    UNITY_BEGIN();

    RUN_TEST(test_freq_output_mode);

    UNITY_END(); // stop unit testing

    return 0;


}