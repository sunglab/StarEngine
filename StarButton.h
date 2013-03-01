//
//  StarButton.h
//  StarEngine
//
//  Created by SungLab on 2/28/13.
//  Copyright (c) 2013 SungLab. All rights reserved.
//

#ifndef __StarEngine__StarButton__
#define __StarEngine__StarButton__


#ifdef ANDROID

#elif  IOS

#endif

class StarButton
{
    private :
    
    float x; float y;
    
    
    
    public :
    StarButton();
    
    bool IsTouched(float _x,float _y);
    
};
#endif /* defined(__StarEngine__StarButton__) */
