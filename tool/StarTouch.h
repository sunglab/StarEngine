//
//  StarTouch.h
//
//  Created by sungwoo choi on 8/25/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#ifndef STARTOUCH_H
#define STARTOUCH_H

#include "../math/StarMath.h"

#define MAX_FINGERS 10

class StarTouchDelegate {
 public:
  virtual void CallbackTouchEnd() = 0;
  virtual void CallbackTouchBegin() = 0;
  virtual void CallbackTouchMove() = 0;
  virtual void CallbackTouchCancel() = 0;
};

class StarTUIO;
class StarTouch {
 public:
  StarTouchDelegate* delegate;

  Vec2 starRect;
  Vec2 nowPos[MAX_FINGERS];
  Vec2 prePos[MAX_FINGERS];
  unsigned int fingers;
  bool end;

  StarTouch(StarTouchDelegate* _delegate, Vec2 _starRect = 0, bool TUIO = true);

  void init(bool TUIO = true);

  StarTouch* clear() {
    fingers = 0;
    for (int i = 0; i < MAX_FINGERS; i++) {
      nowPos[i].zero();
      prePos[i].zero();
      end = true;
    }
    return this;
  };

  void callbackBegin() { delegate->CallbackTouchBegin(); }
  void callbackMove() { delegate->CallbackTouchMove(); }
  void callbackEnd() { delegate->CallbackTouchEnd(); }
  void callbackCancel() { delegate->CallbackTouchCancel(); }
};

#endif
