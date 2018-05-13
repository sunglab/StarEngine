//
//  StarTouch.h
//
//  Created by sungwoo choi on 8/25/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#ifndef STARTOUCH_H
#define STARTOUCH_H

#include "../star.h"
#include "../math/StarMath.h"

#ifdef MAC
#include "TuioListener.h"
#include "TuioClient.h"
#include "UdpReceiver.h"
#include "TcpReceiver.h"
#include <list>

#endif


#define MAX_FINGERS 30

class StarTouchDelegate
{
    public:
    virtual void CallbackTouchEnd()=0;
    virtual void CallbackTouchBegin()=0;
    virtual void CallbackTouchMove()=0;
    virtual void CallbackTouchCancel()=0;
};

//class StarTUIO;
class StarTouch
{
    public:
    
    StarTouchDelegate* delegate;
    
    Vec2 starRect;
	Vec2 nowPos[MAX_FINGERS];
	Vec2 prePos[MAX_FINGERS];
	unsigned int fingers;
	bool end;
    
    StarTouch(StarTouchDelegate* _delegate,Vec2 _starRect= 0,bool TUIO=true);
    void init(bool TUIO=true);

	StarTouch* clear()
	{

		fingers = 0;

		for (int i = 0; i < MAX_FINGERS; i++)
		{
			nowPos[i].zero();
			prePos[i].zero();
			end = true;
		}

		return this;
	};

    void callbackBegin(){delegate->CallbackTouchBegin();}
    void callbackMove(){delegate->CallbackTouchMove();}
    void callbackEnd(){delegate->CallbackTouchEnd();}
    void callbackCancel(){delegate->CallbackTouchCancel();}
};

#ifdef MAC
using namespace TUIO;
class StarTUIO : public TuioListener {
    
public:
    StarTUIO(int port,StarTouch* _startouch): verbose (false),running(false)
    {
        osc_receiver = new UdpReceiver(3333);
        tuioClient = new TuioClient(osc_receiver);
        tuioClient->addTuioListener(this);
        tuioClient->connect();
        this->startouch = _startouch;
    }
    ~StarTUIO() {
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
#endif
