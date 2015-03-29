#include "../star.h"
#include "../math/StarMath.h"

#ifdef MAC
#include "TuioListener.h"
#include "TuioClient.h"
#include "UdpReceiver.h"
#include "TcpReceiver.h"
#include <list>
#endif


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
    StarTouch(StarTouchDelegate* _delegate,Vec2 _starRect){delegate = _delegate; starRect= _starRect; init();}
	Vec2 nowPos[MAX_FINGERS];
	Vec2 prePos[MAX_FINGERS];
    Vec2 starRect;
	unsigned int fingers;
	bool end;
    
    void init();
    void callbackBegin(){delegate->CallbackTouchBegin();}
    void callbackMove(){delegate->CallbackTouchMove();}
    void callbackEnd(){delegate->CallbackTouchEnd();}
    void callbackCancel(){delegate->CallbackTouchCancel();}
};

#ifdef MAC
using namespace TUIO;
class starTUIO : public TuioListener {
    
public:
    starTUIO(int port,StarTouch* _startouch): verbose (false),running(false)
    {
        osc_receiver = new UdpReceiver(3333);
        tuioClient = new TuioClient(osc_receiver);
        tuioClient->addTuioListener(this);
        tuioClient->connect();
        this->startouch = _startouch;
    }
    ~starTUIO() {
        tuioClient->disconnect();
        delete tuioClient;
        delete osc_receiver;
    }
    
    void addTuioObject(TuioObject *tobj);
    void updateTuioObject(TuioObject *tobj);
    void removeTuioObject(TuioObject *tobj);
    
    void addTuioCursor(TuioCursor *tcur);
    void updateTuioCursor(TuioCursor *tcur);
    void removeTuioCursor(TuioCursor *tcur);
    
    void addTuioBlob(TuioBlob *tblb);
    void updateTuioBlob(TuioBlob *tblb);
    void removeTuioBlob(TuioBlob *tblb);
    
    void refresh(TuioTime frameTime);
    
    void run();
    
private:
    bool verbose;
    bool running;
    TuioClient *tuioClient;
    OscReceiver *osc_receiver;
    StarTouch *startouch;
};
#endif