//
//  StarScene.hpp
//  MusicArtButton
//
//  Created by Sungwoo Choi on 5/25/16.
//  Copyright © 2016 SungLab. All rights reserved.
//

#ifndef StarScene_hpp
#define StarScene_hpp

#include <stdio.h>
//#include "./starUI.h"
#include "./StarView.hpp"
#include "./../StarMain.h"
//#include "StarButton.h"
#include "StarDefine.h"

class StarView;
class StarScene :public StarTouchDelegate
//:public StarEngine//, public StarButtonDelegate
{
    std::vector<StarView*> views;
    
public:
//    StarScene(); = delete;
    
    virtual void addView(StarView* starUI)
    {
        if(starUI)
        views.push_back(starUI);
    }
    
    void update()
    {
        for(StarView* view:views)
            view->update();
    }
    
    void render()
    {
        for(StarView* view:views)
            view->render();
    }
    
    StarScene* Make_Scene()
    {
        return this;
    }
};
#endif /* StarScene_hpp */
