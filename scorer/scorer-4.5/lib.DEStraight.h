void DEStraightLeft();
void DEStraightRight();
void DEStraight();

void DEStraight()
{
	if (side == RIGHT)
	{
		DEStraightRight();
	}
	if (side == LEFT)
	{
		DEStraightLeft();
	}
}


void DEStraightRight() {
	create_connect();   
	enable_servos();
	armPosBlockGrab();
	clawSB();
	side == RIGHT;
	set_each_analog_state(0,1,0,0,0,0,0,0);
	clearAngle();
	sleep(1);
	beep();
	driveAtMm(-500); //forward from SB
	run_for(1.15, clawGrab); //while moving claw to Grab position
	create_stop();
	turn(90);//turn towards blocks
	clawOpen();
	driveAtMmFor(-500,.6); //move fast towards first stack for .6 sec 
	/*create_drive_straight(-250); // closer to blocks
	sleep(.3);
	create_stop();
	create_drive_straight(-50);
	sleep(.25);
	create_stop(); */
	detectBlock(); //then use ET sensor
	grabBlocks();
	sleep(1);
	beep();
	driveAtMmFor(100,1); //back off from first stack to make room for turn
	turnFast(90);
	armPosBlockStack1(); //raise
	driveAtMmFor(-500,1.2);//1.0434806); 
	//run_for(1.2, armPosBlockStack1);  //simultaneous move toward PVC while raising arm
	driveAtMmFor(-50, 1.5); //manual detectPVC
	clearAngle();
	sleep(.2);
	driveAtMmFor(100, 1); //clearWall
	turn(90);            //turn toward outside
	driveAtMmFor(-500,.8); 
	blockStack1();        //drop off blocks
	create_drive_straight(250); // back away from towers
	sleep(.7);
	create_stop();
	turn(90);//turn towards seconds tower block side of field
	// joseph's form old DE
	create_drive_straight(-500);
	sleep(3.1); //to the biofuel tower(ish) pvc
	create_stop();
	detectPVC();//drive upto, then ram into PVC to straighten create, set total angel to 0
	clearAngle();
	drive(250);  sleep(1.15);//run_for(1.5, armPosBlockStack1);//drive bd to align create to blocks2, while simultaneously lifting arm above blocks
	turn(90);//turn towards blocks2
	armPosBlockGrab(); //arm in grab pos
	clawGrab();
	driveAtMmFor(-500,.4);//drive towards blocks
	detectBlockSlow();//detect and slowly approch blocks.
	stop();//stop create for good measure
	grabBlocks();//grab blocks procedure
	sleep(1.5);//give claw time to close
	driveAtMmFor(50,1); //clear to give space to turn
	clawSB();
	turnFast(90);//turn towards sb side of feild
	driveAtMmFor(-500,2.8);//drive to inner sb approx.
	detectPVC();//drive into pvc to set angle to 0
	clearAngle();
	driveAtMmFor(100,1); //clear PVC to allow turn to SB
	turn(90);//turn towards outer starting box
	blockStack2();//stack second blocks
	}
	
	void DEStraightLeft() {
	create_connect();   
	enable_servos();
	armPosBlockGrab();
	clawSB();
	side == LEFT;
	set_each_analog_state(0,1,0,0,0,0,0,0);
	clearAngle();
	sleep(1);
	beep();
	driveAtMm(-500); //forward from SB
	run_for(1.15, clawGrab); //while moving claw to Grab position
	create_stop();
	turn(-90);//turn towards blocks
	clawOpen();
	create_drive_straight(-500); //move fast towards first stack for .6 sec
	sleep(.6);
	create_stop(); 
	/*create_drive_straight(-250); // closer to blocks
	sleep(.3);
	create_stop();
	create_drive_straight(-50);
	sleep(.25);
	create_stop(); */
	detectBlock(); //then use ET sensor
	grabBlocks();
	sleep(1);
	beep();
	driveAtMmFor(100,1); //back off from first stack to make room for turn
	turnFast(-90);
	armPosBlockStack1(); //raise
	driveAtMmFor(-500,1.2);//1.0434806); 
	//run_for(1.2, armPosBlockStack1();  //simultaneous move toward PVC while raising arm
	driveAtMmFor(-50, 1.5); //manual detectPVC
	set_create_total_angle(0); X=0;
	sleep(.2);
	driveAtMmFor(100, 1); //clearWall
	turn(-90);            //turn toward outside
	driveAtMmFor(-500,.8); 
	blockStack1();        //drop off blocks
	create_drive_straight(250); // back away from towers
	sleep(.7);
	create_stop();
	turn(-90);//turn towards seconds tower block side of field
	// joseph's form old DE
	create_drive_straight(-500);
	sleep(3.1); //to the biofuel tower(ish) pvc
	create_stop();
	detectPVC();//drive upto, then ram into PVC to straighten create, set total angel to 0
	set_create_total_angle(0); X=0;
	drive(250);  sleep(1.15);//run_for(1.5, armPosBlockStack1);//drive bd to align create to blocks2, while simultaneously lifting arm above blocks
	turn(-90);//turn towards blocks2
	armPosBlockGrab(); //arm in grab pos
	clawGrab();
	driveAtMmFor(-500,.4);//drive towards blocks
	detectBlockSlow();//detect and slowly approch blocks.
	stop();//stop create for good measure
	grabBlocks();//grab blocks procedure
	sleep(1.5);//give claw time to close
	driveAtMmFor(50,1); //clear to give space to turn
	clawSB();
	turnFast(-90);//turn towards sb side of feild
	driveAtMmFor(-500,2.8);//drive to inner sb approx.
	detectPVC();//drive into pvc to set angle to 0
	set_create_total_angle(0); X=0;
	driveAtMmFor(100,1); //clear PVC to allow turn to SB
	turn(-90);//turn towards outer starting box
	blockStack2();//stack second blocks
	}
