//Library -- Camera
//CenterCamera

#define LIB_CAMERA

/*	
/	Description	:
/		-This File contains all funcions relating to the funcitonality of the 
/		 Camera on the Create-based robot called Scorer

/	Written and Maintained By:
/		-Joseph McGee	02/2011-Present
/		-Jae Kim		02/2011-Present
*/


//you must include Movement in the file from which this function is called
void CenterCamera();
void CenterCamera_McGee();
void CenterCamera2();

void CenterCameraMcGee() //CAMERA MUST BE AT CENTER OF CREATE, POINTING Right RESPECT TO CREATE
{
	int speed = 200;
	track_update();
	printf("Start\n");
	int i;
	for (i = 0; (i < 3) && (track_x(0,0) > 81 || track_x(0,0) < 78); i++)
	{
		if (Side == Right)
		{
			printf("Right Side\n");
			if (track_x (0,0) > 81)
			{
				printf("Adjusting Forward\n");
				drive(-adjust_speed);
				while (track_x (0,0) > 81)	track_update();
				stop();
				adjust_speed = adjust_speed/2;
			}
			if (track_x (0,0) < 78)
			{
				printf("Adjusting Backwards\n");
				drive(adjust_speed);
				while (track_x (0,0) < 78)	track_update();
				stop();
				adjust_speed = adjust_speed/2;
			}
		}
		if (Side == Left)
		{
			if (track_x (0,0) < 78)
			{
				printf("Adjusting Forward\n");
				drive(-adjust_speed);
				while (track_x (0,0) < 78)	track_update();
				stop();
				adjust_speed = adjust_speed/2;
			}
			if (track_x (0,0) > 81)
			{
				printf("Adjusting Backwards\n");
				drive(adjust_speed);
				while (track_x (0,0) > 81)	track_update();
				stop();
				adjust_speed = adjust_speed/2;
			}
		}
	}
	printf("CenterCamera Done");
	track_update();
	printf("\t%d", track_x(0,0));	msleep(500);
	drivemm(-CameraOffCenter,1);
	printf("\nAdjust Create Done");
	turnLeft();
}

void CenterCamera() //CAMERA MUST BE AT CENTER OF CREATE, POINTING Right RESPECT TO CREATE
{
	int adjust_speed = 100;
	track_update();
	int i;
	for (i = 0; (i < 3) && (track_x(0,0) > 81 || track_x(0,0) < 77); i++)
	{
		printf("Start CenterCamera\n");
		if(Side==Right)
		{
			track_update();
			if (track_x (0,0) > 81)
			{
				create_drive_straight(-adjust_speed);
				while (track_x (0,0) > 81)	track_update();
				printf("AAA\n");
			}
			
			if (track_x (0,0) < 79)
			{
				create_drive_straight(adjust_speed);
				while (track_x (0,0) < 79)	track_update();
				printf("BBB\n");
			}
		}
		if (Side==Left)
		{
			track_update();
			if (track_x (0,0) > 81)
			{
				create_drive_straight(adjust_speed);
				printf("TEST\n"); // comment out mofo
				while (track_x (0,0) > 81)	track_update();
			}
			if (track_x (0,0) < 79)
			{
				create_drive_straight(-adjust_speed);
				printf("TEST2\n"); // kill latah.
				while (track_x (0,0) < 79)	track_update();
			}
		}
	}
	drivemm(-CameraOffCenter,1);
	track_update();
	printf("%d\n", track_x(0,0));
	create_stop();
//	drivemm(-inchestomm(1), 1);
	turnLeft();
}

void CenterCamera2() //CAMERA MUST BE AT CENTER OF CREATE, POINTING Right RESPECT TO CREATE
{
	int i = 0;
	while ((track_x(0,0) > 81 || track_x(0,0) < 78) && (i < 3))
	{
		int adjust_speed = 100;
		printf("Adjusting");
		if (track_x(0,0) > 81)	//if blocks are right
		{
			create_drive_direct(-adjust_speed, adjust_speed);
			printf(" to CW");
			while (track_x(0,0) > 81)	track_update();
			create_stop();
			adjust_speed = adjust_speed/2;
		}
		if (track_x(0,0) < 78)	//if blocks are left
		{
			create_drive_direct(adjust_speed, -adjust_speed);
			printf(" to CCW");
			while (track_x(0,0) < 78)	track_update();
			create_stop();
			adjust_speed = adjust_speed/2;
		}
	}
}







/*
void CenterCamera(int color, int size,int camera, int speed);//camera is facing front
void CenterCameraR2011(int color, int speed);//For Botball competition 2011
/*	color	:	the channel# of the color stored in the CBC
/	size	:	the relative size of the blob of 'color' 
/					-(range is from 0 the largest to (track_count(ch)-1) the smallest)
/	camera	:	the oreintation of camera
-Front 	is 0
-Right 	is 1
-Back	is 2
-Left	is 3
/	speed	:	for Create
/					-drive speed in mm/s for F and B
/					-turn speed in (mm/CreateDiameter) rads/s for L and R
/				for CBC
/					-drive speed in ticks/s for F and B
/					-turn speed in (ticks/WheelSpan) rads/s for L and R
/





//Center Camera Front and Back by spinning CW or CCW 
//Center Camera Left or Right by driving back or forward
void CenterCamera(int color,int size,int camera,int speed);
void CenterCameraR2011(int color, int speed);


void CenterCamera(int color,int size,int camera,int speed)
{
speed = abs(speed);
track_update();
#ifdef CameraF
if (camera = Front)
{
if (track_x(color,size) > 81)			//if blocks are bd
{
for(spinCW(speed); track_x(color,size) > 81; track_update()){}
stop();
}
if (track_x(color,size) < 78)			//if blocks are fd
{
for(spinCCW(speed); track_x(color,size) < 78; track_update()){}
stop();
}
}
#endif
#ifdef CameraB
if (camera = Back)
{
if (track_x(color,size) > 81)			//if blocks are bd
{
for(spinCW(speed); track_x(color,size) > 81; track_update()){}
stop();
}
if (track_x(color,size) < 78)			//if blocks are fd
{
for(spinCCW(speed); track_x(color,size) < 78; track_update()){}
stop();
}
}
#endif
#ifdef CameraL
if (camera = Left)
{
if (track_x(color,size) > 81)			//if blocks are bd
{
for(drive(speed); track_x(color,size) > 81; track_update()){}
stop();
}
if (track_x(color,size) < 78)			//if blocks are fd
{
for(drive(-speed); track_x(color,size) < 78; track_update()){}
stop();
}
}
#endif
#ifdef CameraR
if (camera = Right)
{
if (track_x(color,size) > 81)			//if blocks are bd
{
for(drive(-speed); track_x(color,size) > 81; track_update()){}
stop();
}
if (track_x(color,size) < 78)			//if blocks are fd
{
for(drive(speed); track_x(color,size) < 78; track_update()){}
stop();
}
}
#endif
}


//Special Functions
void CenterCameraR2011(int color, int speed) 	//CAMERA MUST BE AT CENTER OF CREATE, POINTING Right RESPECT TO CREATE 							
{
track_update();
while (track_x(color,0) > 81 || track_x(color,0) < 78)
{
CenterCamera(color,0,Right,speed);
}
stop();
beep();
drivemm(-CameraOffCenter/3, 3);	//correct for the # of mm offcenter the camera is mounted
if (Side == Right)
turnCCW();
else if (Side == Left)
turnCW();
else
printf("Error Side is neither 0 nor 1\n");
ForwardTouch(-200);
}
*/
