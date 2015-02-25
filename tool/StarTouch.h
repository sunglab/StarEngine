#include "../star.h"
#include "../math/StarMath.h"

//#include "../StarMain.h"  // TEST for IOS (bigbang)
#define MAX_FINGERS 10

class StarTouchDelegate
{public:
    virtual void CallbackTouchEnd(){};
    virtual void CallbackTouchBegin(){};
    virtual void CallbackTouchMove(){};
    virtual void CallbackTouchCancel(){};
};
class StarTouch
{
public:
    StarTouchDelegate* delegate;
    StarTouch(StarTouchDelegate* _delegate){delegate = _delegate;}
	Vec2 nowPos[MAX_FINGERS];	
	Vec2 prePos[MAX_FINGERS];
	unsigned int fingers;
	bool end;
    
    
    void callbackBegin(){delegate->CallbackTouchBegin();}
    void callbackMove(){delegate->CallbackTouchMove();}
    void callbackEnd(){delegate->CallbackTouchEnd();}
    void callbackCancel(){delegate->CallbackTouchCancel();}
};
