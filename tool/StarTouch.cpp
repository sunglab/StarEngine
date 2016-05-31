#include "StarTouch.h"




StarTouch::StarTouch(StarTouchDelegate* _delegate,Vec2 _starRect,bool TUIO)
{
    delegate = _delegate; starRect= _starRect; init(TUIO);
}

void StarTouch::init(bool TUIO)
{
#ifdef MAC
    if(TUIO)
    StarTUIO* app = new StarTUIO(3333,this);
    //    app->run();
    //    delete app;
#endif
    
    for(int i = 0;i<MAX_FINGERS;i++)
    {
        nowPos[i].zero();
        prePos[i].zero();
        end = true;
    }
    fingers = 0;
}

#ifdef MAC
void StarTUIO::addTuioObject(TuioObject *tobj) {
    if (verbose)
        std::cout << "add obj " << tobj->getSymbolID() << " (" << tobj->getSessionID() << "/"<<  tobj->getTuioSourceID() << ") "<< tobj->getX() << " " << tobj->getY() << " " << tobj->getAngle() << std::endl;
}

void StarTUIO::updateTuioObject(TuioObject *tobj) {
    
    if (verbose)
        std::cout << "set obj " << tobj->getSymbolID() << " (" << tobj->getSessionID() << "/"<<  tobj->getTuioSourceID() << ") "<< tobj->getX() << " " << tobj->getY() << " " << tobj->getAngle()
        << " " << tobj->getMotionSpeed() << " " << tobj->getRotationSpeed() << " " << tobj->getMotionAccel() << " " << tobj->getRotationAccel() << std::endl;
}

void StarTUIO::removeTuioObject(TuioObject *tobj) {
    
    if (verbose)
        std::cout << "del obj " << tobj->getSymbolID() << " (" << tobj->getSessionID() << "/"<<  tobj->getTuioSourceID() << ")" << std::endl;
}

void StarTUIO::addTuioCursor(TuioCursor *tcur) {
    
    if (verbose)
        std::cout << "add cur " << tcur->getCursorID() << " (" <<  tcur->getSessionID() << "/"<<  tcur->getTuioSourceID() << ") " << tcur->getX() << " " << tcur->getY() << std::endl;
    
//    if(tcur->getCursorID()==0)
//    {
////        std::list<TuioCursor*> cursorList = tuioClient->getTuioCursors();
////        tuioClient->lockCursorList();
////        int i = 0;
////        for (std::list<TuioCursor*>::iterator iter = cursorList.begin(); iter!=cursorList.end(); iter++,i++) {
////            TuioCursor *tuioCursor = (*iter);
//            float xpos  = tcur->getPosition().getX();
//            float ypos  = tcur->getPosition().getY();
//            float starWidth = startouch->starRect.x;
//            float starHeight = startouch->starRect.y;
////            int index = tuioCursor->getCursorID();
////            //        printf("xpos:%f ypos:%f index:%d\n", xpos, ypos,index);
//            startouch->prePos[0] = startouch->nowPos[0];
//            startouch->nowPos[0] = Vec2(starWidth*xpos,starHeight-starHeight*ypos);
//        
//        startouch->callbackBegin();
//    }
    
    if(tcur->getCursorID()<10)
    {
    float xpos  = tcur->getPosition().getX();
    float ypos  = tcur->getPosition().getY();
    float starWidth = startouch->starRect.x;
    float starHeight = startouch->starRect.y;
    //            int index = tuioCursor->getCursorID();
    //            //        printf("xpos:%f ypos:%f index:%d\n", xpos, ypos,index);
    startouch->prePos[tcur->getCursorID()] = startouch->nowPos[tcur->getCursorID()];
    startouch->nowPos[tcur->getCursorID()] = Vec2(starWidth*xpos,starHeight-starHeight*ypos);
    
    }
    
//    std::list<TuioCursor*> cursorList = tuioClient->getTuioCursors();
//    tuioClient->lockCursorList();
//    int i = 0;
//    for (std::list<TuioCursor*>::iterator iter = cursorList.begin(); iter!=cursorList.end(); iter++,i++) {
//        TuioCursor *tuioCursor = (*iter);
//        float xpos  = tuioCursor->getPosition().getX();
//        float ypos  = tuioCursor->getPosition().getY();
//        float starWidth = startouch->starRect.x;
//        float starHeight = startouch->starRect.y;
//        int index = tuioCursor->getCursorID();
//        
//        startouch->nowPos[index] = Vec2(starWidth*xpos,starHeight-starHeight*ypos);
//    }
    
    startouch->callbackBegin();
}

void StarTUIO::updateTuioCursor(TuioCursor *tcur) {
    
    if (verbose)
        std::cout << "set cur " << tcur->getCursorID() << " (" <<  tcur->getSessionID() << "/"<<  tcur->getTuioSourceID() << ") " << tcur->getX() << " " << tcur->getY()
        << " " << tcur->getMotionSpeed() << " " << tcur->getMotionAccel() << " " << std::endl;
    std::list<TuioCursor*> cursorList = tuioClient->getTuioCursors();
    tuioClient->lockCursorList();
    int i = 0;
    for (std::list<TuioCursor*>::iterator iter = cursorList.begin(); iter!=cursorList.end(); iter++,i++) {
        TuioCursor *tuioCursor = (*iter);
        float xpos  = tuioCursor->getPosition().getX();
        float ypos  = tuioCursor->getPosition().getY();
        float starWidth = startouch->starRect.x;
        float starHeight = startouch->starRect.y;
        int index = tuioCursor->getCursorID();
//        printf("xpos:%f ypos:%f index:%d\n", xpos, ypos,index);
        startouch->prePos[index] = startouch->nowPos[index];
        startouch->nowPos[index] = Vec2(starWidth*xpos,starHeight-starHeight*ypos);
    }
    
    //    printf("i = %d", i);
    startouch->fingers = i;
    startouch->end = false;
    tuioClient->unlockCursorList();
    startouch->callbackMove();
}

void StarTUIO::removeTuioCursor(TuioCursor *tcur) {
    
     startouch->callbackEnd();// to notice how many fingers
    
    if (verbose)
        std::cout << "del cur " << tcur->getCursorID() << " (" <<  tcur->getSessionID() << "/"<<  tcur->getTuioSourceID() << ")" << std::endl;
    if(tcur->getCursorID()==0)
    {   //printf("why false?\n");
         startouch->end = true;
        startouch->fingers = 0;
    }
    
}

void StarTUIO::addTuioBlob(TuioBlob *tblb) {
    
    if (verbose)
        std::cout << "add blb " << tblb->getBlobID() << " (" << tblb->getSessionID()  << "/"<<  tblb->getTuioSourceID()<< ") "<< tblb->getX() << " " << tblb->getY() << " " << tblb->getAngle() << " " << tblb->getWidth() << " " << tblb->getHeight() << " " << tblb->getArea() << std::endl;
}

void StarTUIO::updateTuioBlob(TuioBlob *tblb) {
    
    if (verbose)
        std::cout << "set blb " << tblb->getBlobID() << " (" << tblb->getSessionID() << "/"<<  tblb->getTuioSourceID() << ") "<< tblb->getX() << " " << tblb->getY() << " " << tblb->getAngle() << " "<< tblb->getWidth() << " " << tblb->getHeight() << " " << tblb->getArea()
        << " " << tblb->getMotionSpeed() << " " << tblb->getRotationSpeed() << " " << tblb->getMotionAccel() << " " << tblb->getRotationAccel() << std::endl;
}

void StarTUIO::removeTuioBlob(TuioBlob *tblb) {
    
    if (verbose)
        std::cout << "del blb " << tblb->getBlobID() << " (" << tblb->getSessionID() << "/"<<  tblb->getTuioSourceID() << ")" << std::endl;
}


void StarTUIO::refresh(TuioTime frameTime) {
}

void StarTUIO::run()
{
        running=true;
        while (running)
        {
            std::list<TuioCursor*> cursorList = tuioClient->getTuioCursors();
            tuioClient->lockCursorList();
            for (std::list<TuioCursor*>::iterator iter = cursorList.begin(); iter!=cursorList.end(); iter++) {
                TuioCursor *tuioCursor = (*iter);
                float xpos  = tuioCursor->getPosition().getX();
                float ypos  = tuioCursor->getPosition().getY();
                int index = tuioCursor->getCursorID();
                printf("xpos:%f ypos:%f index:%d\n", xpos, ypos,index);
                startouch->nowPos[index] = Vec2(xpos,ypos);
                
            }
            tuioClient->unlockCursorList();
        }
}
#endif