/***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/

int main{
	moveforwardslow();
	sleep(0.3);
	ao();
	turnCCW();
	for(int i = 0; i <=8; i++) {
		cameratrack();
	}
	turnCW();
	
	
	
	
	
	
	
	
	
	
}
void moveforwardfast() {
	mav(0, 1000);
	mav(1, 1000);
	}
void moveforwardslow() {
	mav(0, 500);
	mav(1, 500);
	}
void movebackward() { 
	mav(0, -1000);
	mav(1, -1000);
	}
void turnCW(){ 
	mav(0,700); mav(1,-700);
	sleep(0.479999);
	ao();	
	}	
void turnCCW(){ 
	mav(0,-700); mav(1,700);
	sleep(0.479999);
	ao();	
	}		
void clawlift() { 
	enable_servos();
	set_servo_position(1,400);
	}	
void clawdrop() {
	enable_servos();
`	set_servo_position(1,1400);
	}
void detectlinestop() {
  int threshold=512;     // set threshold for light conditions
     if (analog10(1) >= threshold) { // continue until dark
       ao();       // move to line
}

void cameratrack() {
	//check every 1/4th of a second
	
	target_cha_in_chb(<0>, <2>, <*x>, <*y>);
	//cha is channel number for the inner color and chb is the surrounding color channel. 
	//If target is found function returns 1, otherwise 0. x and y are changed
if (x <= 83) 
{
	mav(0,700); mav(1,600);
}
if (x<=88, x>=83) 
{
	mav(0,700); mav(1,700);
}
if (x >=88) 
{
	mav(0,600); mav(1,700);
}
sleep(0.5);
}

void cameratrackpinkleft() {
	
	
}

void cameratrackgreenleft(){
	
}


	
/*Function definitions go below.*/
