//
//  StarButton.h
//  StarEngine
//
//  Created by SungLab on 2/28/13.
//  Copyright (c) 2013 SungLab. All rights reserved.
//

#ifndef __StarEngine__StarButton__
#define __StarEngine__StarButton__

#include "StarMain.h"

#ifdef ANDROID

#elif  IOS

#endif

class StarButton
{
    private :
    
    float x; float y;
    
    
    
    public :
    StarButton();
    
    bool IsTouched(Vec2 touch);
    
};
#endif /* defined(__StarEngine__StarButton__) */
