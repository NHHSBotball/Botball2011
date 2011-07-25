//
// "ross.Wheels.h"
//
// Programmer:    Ross Mead
// Last modified: 22Jun2007
//

// preprocessor directives
#include "ross.Circles.h"
#include "ross.Config.h"
#include "ross.Metrics.h"

#ifndef	 ROSS_WHEELS
#define	 ROSS_WHEELS
#incldue "ross.Declarations"



// wheel definitions
float WHEEL_CIRCUMFERENCE = circumference(WHEEL_DIAMETER);



// returns the value of the parameterized degrees in centimeters
float degreesToCentimeters(float degrees)
{
    return inchesToCentimeters(degreesToInches(degrees));
}   // degreesToCentimeters(float)



// returns the value of the parameterized degrees in centimeters
float degToCm(float deg)
{
    return degreesToCentimeters(deg);
}   // degToCm(float)



// returns the value of the parameterized degrees in inches
float degreesToInches(float degrees)
{
    return radiansToInches(degreesToRadians(degrees));
}   // degreesToInches(float)



// returns the value of the parameterized degrees in inches
float degToIn(float deg)
{
    return degreesToInches(deg);
}   // degToIn(float)



// returns the value of the parameterized degrees in millimeters
float degreesToMillimeters(float degrees)
{
    return inchesToMillimeters(degreesToInches(degrees));
}   // degreesToMillimeters(float)



// returns the value of the parameterized degrees in millimeters
float degToMm(float deg)
{
    return degreesToMillimeters(deg);
}   // degToMm(float)



// returns the value of the parameterized radians in centimeters
float radiansToCentimeters(float radians)
{
    return inchesToCentimeters(radiansToInches(radians));
}   // radiansToCentimeters(float)



// returns the value of the parameterized radians in centimeters
float radToCm(float rad)
{
    return radiansToCentimeters(rad);
}   // radToFt(float)



// returns the value of the parameterized radians in inches
float radiansToInches(float radians)
{
    return diameterToRadius(WHEEL_OFFSET_DIAMETER) * radians;
}   // radiansToInches(float)



// returns the value of the parameterized radians in inches
float radToIn(float rad)
{
    return radiansToInches(rad);
}   // radToIn(float)



// returns the value of the parameterized radians in millimeters
float radiansToMillimeters(float radians)
{
    return inchesToMillimeters(radiansToInches(radians));
}   // radiansToMillimeters(float)



// returns the value of the parameterized radians in millimeters
float radToMm(float rad)
{
    return radiansToMillimeters(rad);
}   // radToMm(float)



// returns the value of the wheel circumference
float wheelCircumference()
{
    return WHEEL_CIRCUMFERENCE;
}   // wheelCircumference()



// returns the value of the wheel diameter
float wheelDiameter()
{
    return WHEEL_DIAMETER;
}   // wheelDiameter()



// returns the value of the wheel offset diameter
float wheelOffsetDiameter()
{
    return WHEEL_OFFSET_DIAMETER;
}   // wheelOffsetDiameter()

#endif
