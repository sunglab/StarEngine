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
#include "./StarView.h"
#include "./../StarMain.h"

#include <unordered_map>
#include <typeinfo>
#include <typeindex>

class StarView;
class StarScene :public StarTouchDelegate
{
    std::vector<StarView*> views;
    std::unordered_map<std::type_index,StarView*> list;
    
public:
    
    virtual void addView(StarView* starUI)
    {
        if(starUI)
        {
            views.push_back(starUI);
            list[std::type_index(typeid(*starUI))] = starUI;
        }
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
    
    
    StarView* getView(std::type_index idx)
    {
        return list[idx];
    }
    
    StarScene* Make_Scene()
    {
        return this;
    }
    
    virtual void CallbackTouchBegin()override
    {
        for(StarView* view:views)
            view->CallbackTouchBegin();
    }
    
    virtual void CallbackTouchMove()override
    {
        for(StarView* view:views)
            view->CallbackTouchMove();
    }
    
    virtual void CallbackTouchEnd() override
    {
        for(StarView* view:views)
            view->CallbackTouchEnd();
    }
    
    virtual void CallbackTouchCancel()override
    {
        for(StarView* view:views)
            view->CallbackTouchCancel();
    }
};
#endif /* StarScene_hpp */
