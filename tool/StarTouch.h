#include "../star.h"
#include "../math/StarMath.h"

//#include "../StarMain.h"  // TEST for IOS (bigbang)
#define MAX_FINGERS 10

class StarTouch
{
	public:
	Vec2 nowPos[MAX_FINGERS];	
	Vec2 prePos[MAX_FINGERS];
	unsigned int fingers;
	bool end;	
};
