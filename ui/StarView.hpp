//
//  StarView.hpp
//  MusicArtButton
//
//  Created by Sungwoo Choi on 5/25/16.
//  Copyright © 2016 SungLab. All rights reserved.
//

#ifndef StarView_hpp
#define StarView_hpp

#include <stdio.h>

class StarTexture;
class StarFBO;
class StarShader;
class StarView
{
    
public:
    virtual void render() = 0;
    virtual void init() = 0;
    virtual void done() = 0;
    
};
#endif /* StarView_hpp */
