
//
//  StarTouch.cpp
//  StarEngine
//
//  Created by sungwoo choi on 8/25/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#include "StarTouch.h"

StarTouch::StarTouch(StarTouchDelegate* _delegate, Vec2 rect, bool TUIO) {

  delegate = _delegate;
  init(TUIO);
}

void StarTouch::init(bool TUIO) {

  for (int i = 0; i < MAX_FINGERS; i++) {
    nowPos[i].zero();
    prePos[i].zero();
    end = true;
  }
  fingers = 0;
}