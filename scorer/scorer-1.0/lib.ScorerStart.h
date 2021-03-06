// ScorerStart - initializes robot and all peripherals, then lifts first tower blocks.
// ends at lifting of first tower stack.
// code written by Ben Shukman.

/* Libraries used in Botball are automatically included, but list any additional includes below */

/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/
int scorerStrategy;

/*Function prototypes below*/
void ScorerStart();
void initialize();
void initialPosition();
void whichSide();
void strategySelect();


// Main:

void ScorerStart() {
	initialize();
	printf("initialization complete");
	cbc_display_clear();
	if(scorerStrategy == 1) {
		printf("SCORER\n");
		if(Side == Right) {
			printf("RIGHT SIDE");
		} else if (Side == Left) {
			printf("LEFT SIDE");
		}
	}
	if(scorerStrategy == 2) {
		printf("SAFETY\n");
		if(Side == Right) {
			printf("RIGHT SIDE");
		} else if (Side == Left) {
			printf("LEFT SIDE");
		}
	}
	initialPosition(); // leaves sb + moves into position for CenterCamera.
	CenterCamera();
	Lift();
	if(scorerStrategy == 1) {
		Scorer();
	}
	if(scorerStrategy == 2) {
		Safety();
	}
}


// Functions:

void initialize() {
	printf("initializing. please wait.\n");
	enable_servos();
	sleep(.25);
	mav(3,100);
	sleep(1.0);
	off(3);
	enableServoDown();
	sleep(.5);
	Release();
	set_servo_position(1, 1200); // mini servo up.
	printf("servos initalized.\n");
	
	create_connect();
	create_full();
	set_create_total_angle(0);
	set_each_analog_state(0,0,0,1,0,0,0,0);
	printf("create initialized.\n");
	
	whichSide();
	strategySelect();
	//wait_for_light(7);  // light port is #7. DELETE COMMENT OUT
	//shut_down_in(117); // DELETE COMMENT OUT
	set_servo_position(1,120); // mini servo down.
	
	
}

void initialPosition() {
	drivemm(-300, 1); // test value.  leaves starting box, middle of boxes.
	TurnRight();
	drivemm(-300, 1); // test values. moves forward tiny bit, transitions in CenterCamera();
}

void whichSide() {
	printf ("select orientation of the robot compared to botguy.\n(make sure camera is facing right way)\n'A' button for left of bot guy.\n'B' button for right of bot guy.\n");
	while (b_button() == 0 && a_button() == 0){
	}
	if (b_button()){
		Side = Right;
		cbc_display_clear();
		printf ("robot is on right of botguy.\n");
		sleep(1);
	}
	if (a_button()){
		Side = Left;
		cbc_display_clear();
		printf ("robot is on left of botguy.\n");
		sleep(1);
	}
}

void strategySelect() {
	printf("please select a strategy.\n\n");
	printf("standard tower stack: press 'A'\nsafe tower stack: press 'B'\n\n");
	while (b_button() == 0 || a_button() == 0) {
		if (a_button() == 1) {
			printf("you have selected standard tower stacking.\n");
			scorerStrategy = 1;
			sleep(1);
			break;
		}
		if (b_button() == 1) {
			printf("you have selected safe tower stacking.\n");
			scorerStrategy = 2;
			sleep(1);
			break;
		}
	}
}
	
