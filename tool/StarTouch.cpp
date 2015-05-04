#include "StarTouch.h"


void StarTouch::init()
{
#ifdef MAC
    starTUIO*app = new starTUIO(3333,this);
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
void starTUIO::addTuioObject(TuioObject *tobj) {
    if (verbose)
        std::cout << "add obj " << tobj->getSymbolID() << " (" << tobj->getSessionID() << "/"<<  tobj->getTuioSourceID() << ") "<< tobj->getX() << " " << tobj->getY() << " " << tobj->getAngle() << std::endl;
}

void starTUIO::updateTuioObject(TuioObject *tobj) {
    
    if (verbose)
        std::cout << "set obj " << tobj->getSymbolID() << " (" << tobj->getSessionID() << "/"<<  tobj->getTuioSourceID() << ") "<< tobj->getX() << " " << tobj->getY() << " " << tobj->getAngle()
        << " " << tobj->getMotionSpeed() << " " << tobj->getRotationSpeed() << " " << tobj->getMotionAccel() << " " << tobj->getRotationAccel() << std::endl;
}

void starTUIO::removeTuioObject(TuioObject *tobj) {
    
    if (verbose)
        std::cout << "del obj " << tobj->getSymbolID() << " (" << tobj->getSessionID() << "/"<<  tobj->getTuioSourceID() << ")" << std::endl;
}

void starTUIO::addTuioCursor(TuioCursor *tcur) {
    
    if (verbose)
        std::cout << "add cur " << tcur->getCursorID() << " (" <<  tcur->getSessionID() << "/"<<  tcur->getTuioSourceID() << ") " << tcur->getX() << " " << tcur->getY() << std::endl;
    if(tcur->getCursorID()==0)
        startouch->callbackBegin();
    
}

void starTUIO::updateTuioCursor(TuioCursor *tcur) {
    
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
        printf("xpos:%f ypos:%f index:%d\n", xpos, ypos,index);
        startouch->prePos[index] = startouch->nowPos[index];
        startouch->nowPos[index] = Vec2(starWidth*xpos,starHeight-starHeight*ypos);
    }
//    printf("i = %d", i);
    startouch->fingers = i;
    tuioClient->unlockCursorList();
     startouch->callbackMove();
}

void starTUIO::removeTuioCursor(TuioCursor *tcur) {
    
    if (verbose)
        std::cout << "del cur " << tcur->getCursorID() << " (" <<  tcur->getSessionID() << "/"<<  tcur->getTuioSourceID() << ")" << std::endl;
    if(tcur->getCursorID()==0)
         startouch->fingers = 0;
        startouch->callbackEnd();
}

void starTUIO::addTuioBlob(TuioBlob *tblb) {
    
    if (verbose)
        std::cout << "add blb " << tblb->getBlobID() << " (" << tblb->getSessionID()  << "/"<<  tblb->getTuioSourceID()<< ") "<< tblb->getX() << " " << tblb->getY() << " " << tblb->getAngle() << " " << tblb->getWidth() << " " << tblb->getHeight() << " " << tblb->getArea() << std::endl;
}

void starTUIO::updateTuioBlob(TuioBlob *tblb) {
    
    if (verbose)
        std::cout << "set blb " << tblb->getBlobID() << " (" << tblb->getSessionID() << "/"<<  tblb->getTuioSourceID() << ") "<< tblb->getX() << " " << tblb->getY() << " " << tblb->getAngle() << " "<< tblb->getWidth() << " " << tblb->getHeight() << " " << tblb->getArea()
        << " " << tblb->getMotionSpeed() << " " << tblb->getRotationSpeed() << " " << tblb->getMotionAccel() << " " << tblb->getRotationAccel() << std::endl;
}

void starTUIO::removeTuioBlob(TuioBlob *tblb) {
    
    if (verbose)
        std::cout << "del blb " << tblb->getBlobID() << " (" << tblb->getSessionID() << "/"<<  tblb->getTuioSourceID() << ")" << std::endl;
}


void starTUIO::refresh(TuioTime frameTime) {
}

void starTUIO::run()
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