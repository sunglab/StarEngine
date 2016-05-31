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

class StarScene
{
    unsigned int  scene_id;
    std::vector<StarView*> ui_list;
    
    StarScene()
    {
        scene_id = 0;
    }
    
    void addView(StarView* starUI)
    {
        if(starUI)
        ui_list.push_back(starUI);
    }
    
    void setSceneID(unsigned int id)
    {
        // special effect first
        // then change?
        scene_id = id;
    }
    
    void render()
    {
        ui_list[scene_id]->render();
    }
    
    
};
#endif /* StarScene_hpp */
