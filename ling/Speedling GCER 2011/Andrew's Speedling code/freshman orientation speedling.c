#include "lib.freshmovement.h"
#include "lib.Advanced Movement.h"
#include "lib.Rotation.h"
//#include "lib.Assignments.h"
#include "lib.freshmanstrategyselect.h"
#include "lib.freshmanstrategies.h"


int main()
{
	enable_servos();

	
	side = left;
		motorLT = 3; //Write all programs with the Zergling on left side of board!
		motorLB = 2;
		motorRT = 1;
		motorRB = 0;
	
	strategySelect();
	run_strategy(strategy);
	//variable declarations go here.

	// uncomment the line below anf put 1s in the appropriate places if using floating sensors (ET and sonar)
	//set_each_analog_state(0,0,0,0,0,0,0,0);// This line sets analog ports to be pullup (0) or floating (1)
	
	// uncomment the line below to have the rest of the program wait for the starting light to turn on
	//wait_for_light(port_number);//replace "port_number" with the analog port number into which the light sensor is connected
	
	// uncomment the line below to have a function run for a specified amount of seconds
	//run_for(num_secs, function_name);//replace num_secs with the amount of time to run and function_name with your function's name
}

/*Function definitions go below.*/
