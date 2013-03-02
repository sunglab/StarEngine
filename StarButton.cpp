//
//  StarButton.cpp
//  StarEngine
//
//  Created by SungLab on 2/28/13.
//  Copyright (c) 2013 SungLab. All rights reserved.
//

#include "StarButton.h"



StarButton::StarButton()
{
    
}

bool StarButton::IsTouched(Vec2 touch)
{
    x = touch.x;
    y = touch.y;
    
    return 0;
}