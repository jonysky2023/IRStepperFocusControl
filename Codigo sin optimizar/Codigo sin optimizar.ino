//   1=1/4 CW
//   2=1/2 CW
//   3=3/4 CW
//   4=1/4 CCW
//   5=1/2 CCW
//   6=3/4 CCW
//   >> FULL TURN CW
//   << FULL TURN CCW



#include "Stepper.h"
#include "IRremote.h"

/*----- Variables, Pins -----*/
#define STEPS  32   // Number of steps per revolution of Internal shaft
int  Steps2Take;  // 2048 = 1 Revolution
int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 6

/*-----( Declare objects )-----*/
// Setup of proper sequencing for Motor Driver Pins
// In1, In2, In3, In4 in the sequence 1-3-2-4

Stepper small_stepper(STEPS, 4, 6, 5, 7);
IRrecv irrecv(receiver);    // create instance of 'irrecv'
decode_results results;     // create instance of 'decode_results'

void setup()
{ 
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
if (irrecv.decode(&results)) // have we received an IR signal?

  {
    switch(results.value)

    {

    

     
      case 16724175: //   >> button pressed2
                      small_stepper.setSpeed(500); //Max seems to be 700
                      Steps2Take  =  100;  // Rotate CW
                      small_stepper.step(Steps2Take);
                      //delay(200); 
                      break;

      case 16718055: //   << button pressed
                      small_stepper.setSpeed(500);
                      Steps2Take  =  -100;  // Rotate CW
                      small_stepper.step(Steps2Take);
                      //delay(200); 
                      break;
                      
      case 16743045: //   >> button pressed
                      small_stepper.setSpeed(500); //Max seems to be 700
                      Steps2Take  =  50;  // Rotate CW
                      small_stepper.step(Steps2Take);
                      //delay(200); 
                      break;

      case 16716015: //   << button pressed
                      small_stepper.setSpeed(500);
                      Steps2Take  =  -50;  // Rotate CCW
                      small_stepper.step(Steps2Take);
                      //delay(200); 
                      break;
                      
      case 16726215: //   >> button pressed
                      small_stepper.setSpeed(300); //Max seems to be 700
                      Steps2Take  =  10;  // Rotate CCW
                      small_stepper.step(Steps2Take);
                      //delay(200); 
                      break;

      case 16734885: //   << button pressed
                      small_stepper.setSpeed(300);
                      Steps2Take  =  -10;  // Rotate CCW
                      small_stepper.step(Steps2Take);
                      //delay(200); 
                      break;  
                      
     case 16730805: //   >> button pressed
                      small_stepper.setSpeed(300); //Max seems to be 700
                      Steps2Take  =  5;  // Rotate CCW
                      small_stepper.step(Steps2Take);
                      //delay(200); 
                      break;
                     
     case 16732845:  //   << button pressed
                      small_stepper.setSpeed(300);
                      Steps2Take  =  -5;  // Rotate CCW
                      small_stepper.step(Steps2Take);
                      //delay(200); 
                      break;   

                                         
    }
    
      irrecv.resume(); // receive the next value
  }  


}/* --end main loop -- */
