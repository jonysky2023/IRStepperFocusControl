#include <Stepper.h>
#include <IRremote.h>

#define STEPS_PER_REV 32
#define MAX_SPEED 500

const int stepsPerBtnPress[] = {100, 50, 10, 5};
const int btnPressCodes[] = {16724175, 16743045, 16726215, 16730805}; 
const int btnReleaseCodes[] = {16718055, 16716015, 16734885, 16732845};

const int RECV_PIN = 11;

Stepper smallStepper(STEPS_PER_REV, 4, 6, 5, 7);
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    int i;
    for (i = 0; i < 4; i++) {
      if (results.value == btnPressCodes[i]) {
        smallStepper.setSpeed(MAX_SPEED);
        smallStepper.step(stepsPerBtnPress[i]);
        break;
      }
      else if (results.value == btnReleaseCodes[i]) {
        smallStepper.release();
        break;
      }
    }
    irrecv.resume();
  }
}
