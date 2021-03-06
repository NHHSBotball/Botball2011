//
// "Behavior.ic"
//
// Programmer:    Ross Mead
// Last modified: 25Jan2008
//

// preprocessor directives
#include "ross.Boolean.h"

#ifndef  ROSS_BOOLEAN
#define  ROSS_BOOLEAN
#include "ross.Declarations.h"

// behavior debug definitions
//#define DEBUG_BEHAVIOR 1



// behavior type definitions
#define BehaviorType   int
#define BEH_NO_NAME   -1



// behavior status definitions
#define BEH_INACTIVE   0
#define BEH_DONE       1
#define BEH_ACTIVE     2



// defines a robot behavior
struct Behavior
{
    BehaviorType type;
    int          status;
};  // Behavior



// initializes the parameterized behavior,
// returning TRUE if successful, FALSE otherwise
BOOL initBehavior(struct Behavior* b)
{
    if (b == NULL) return FALSE;
    return setBehavior(b, BEH_NO_NAME, BEH_INACTIVE);
}   // initBehavior(struct Behavior*)



// sets the parameterized behavior to the parameterized values,
// returning TRUE if successful, FALSE otherwise
BOOL setBehavior(struct Behavior* b, BehaviorType type, int s)
{
    return setBehaviorType(b, type) && setBehaviorStatus(b, s);
}   // setBehavior(struct Behavior*, BehaviorType, int)



// sets the type of the parameterized behavior
// to the parameterized name, returning
// TRUE if successful, FALSE otherwise
BOOL setBehaviorType(struct Behavior* b, BehaviorType type)
{
    if (b == NULL) return FALSE;
    b->type = type;
    return TRUE;
}   // setBehaviorType(struct Behavior*, BehaviorType)



// sets the status of the parameterized behavior
// to the parameterized status, returning
// TRUE if successful, FALSE otherwise
BOOL setBehaviorStatus(struct Behavior* b, int s)
{
    if ((b == NULL) ||
        ((s != BEH_INACTIVE) && (s != BEH_DONE) && (s != BEH_ACTIVE)))
      return FALSE;
    b->status = s;
    return TRUE;
}   // setBehaviorStatus(struct Behavior*, int)



// copies the contents of the parameterized source
// behavior into the parameterized destination behavior
// returning TRUE if successful, FALSE otherwise
BOOL copyBehavior(struct Behavior* src, struct Behavior* dest)
{
    if (src == NULL) return FALSE;
    return setBehavior(dest, src->type, src->status);
}   // copyBehavior(struct Behavior*, struct Behavior*)



// returns TRUE if the status of the parameterized
// behavior is ACTIVE, FALSE otherwise
BOOL isBehaviorActive(struct Behavior* b)
{
    return isBehaviorStatus(b, BEH_ACTIVE);
}   // isBehaviorActive(struct Behavior*)



// returns TRUE if the status of the parameterized
// behavior is DONE, FALSE otherwise
BOOL isBehaviorDone(struct Behavior* b)
{
    return isBehaviorStatus(b, BEH_DONE);
}   // isBehaviorDone(struct Behavior*)



// returns TRUE if the status of the parameterized
// behavior is INACTIVE, FALSE otherwise
BOOL isBehaviorInactive(struct Behavior* b)
{
    return isBehaviorStatus(b, BEH_INACTIVE);
}   // isBehaviorInactive(struct Behavior*)



// returns TRUE if the status of the parameterized
// behavior is equal to the parameterized status, FALSE otherwise
BOOL isBehaviorStatus(struct Behavior* b, int s)
{
    if (b == NULL) return FALSE;
    return b->status == s;
}   // isBehaviorStatus(struct Behavior*, int)



// returns TRUE if the name of the parameterized
// behavior is equal to the parameterized name, FALSE otherwise
BOOL isBehaviorType(struct Behavior* b, BehaviorType type)
{
    if (b == NULL) return FALSE;
    return b->type == type;
}   // isBehaviorName(struct Behavior*, BehaviorType)



// sets the parameterized destination behavior to the
// parameterized behavior with the highest activation level,
// returning TRUE if successful, FALSE otherwise
BOOL subsumeBehaviors(struct Behavior* bHigh,
                      struct Behavior* bLow,
                      struct Behavior* b)
{
    if ((b    == NULL) || ((bHigh == NULL) && (bLow == NULL))) return FALSE;
    if (bHigh == NULL)                return copyBehavior(bLow,  b);
    if (bLow  == NULL)                return copyBehavior(bHigh, b);
    if (bLow->status > bHigh->status) return copyBehavior(bLow,  b);
    return                                   copyBehavior(bHigh, b);
}   // subsumeBehaviors(struct Behavior*, struct Behavior*, struct Behavior*)



// compares the two parameterized behaviors for equality,
// returning TRUE if they are the same, FALSE otherwise
BOOL compareBehaviors(struct Behavior* b1, struct Behavior* b2)
{
    if ((b1 == NULL) || (b2 == NULL)) return FALSE;
    return (b1->type == b2->type) && (b1->status == b2->status);
}   // equalBehaviors(struct Behavior*, struct Behavior*)



// prints the parameterized behavior (with an optional label) to the screen
BOOL printBehavior(struct Behavior* b, char label[])
{
    if (b == NULL) return FALSE;
    printf("%s[%d]: ", label, b->type);
    if      (isBehaviorActive(    b)) printf("ACTIVE\n");
    else if (isBehaviorDone(      b)) printf("DONE\n");
    else if (isBehaviorInactive(  b)) printf("INACTIVE\n");
    else {
        printf("UNKNOWN\n");
        return FALSE;
    }
    return TRUE;
}   // printBehavior(struct Behavior*, char [])



#ifdef  DEBUG_BEHAVIOR
#define BEH_TEST_1 1
#define BEH_TEST_2 2
int main()
{
    struct Behavior b1, b2;
    
    printf("\ninit\n");
    initBehavior(&b1);
    setBehavior(&b2, BEH_TEST_1, BEH_ACTIVE);
    printBehavior(&b1, "b1");
    printBehavior(&b2, "b2");
    
    printf("\ncopy\n");
    copyBehavior(&b2, &b1);
    printBehavior(&b1, "b1");
    
    printf("\nisBehaviorActive? %d\n", isBehaviorActive(&b1));
    
    printf("\nsubsume\n");
    setBehavior(&b1, BEH_TEST_1, BEH_INACTIVE);
    setBehavior(&b2, BEH_TEST_2, BEH_DONE);
    subsumeBehaviors(&b1, &b2, &b1);
    printBehavior(&b1, "b1");
    
    return 0;
}   // main()
#endif

#endif
