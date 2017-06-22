//
//  StarDirector.hpp
//  GameWithLua
//
//  Created by Sungwoo Choi on 6/4/17.
//  Copyright © 2017 SungLab. All rights reserved.
//

#ifndef StarDirector_hpp
#define StarDirector_hpp

#include "../StarMain.h"
//#include "StarInfo.h"

class StarDirector{

public:
    template <class SceneType>
    void newScene(SCENE scene)//, const std::shared_ptr<starengine> engine)
    {
        SceneType type;
        mSceneMap[scene] = (type.Make_Scene());
    };
    
    std::weak_ptr<SCENE> getScene(SCENE sceneID)
    {
//        (mSceneMap[sceneID])->reset(); // each scene is automatically reset here
        return mSceneMap[sceneID];
    }

private:
    std::map<SCENE, std::shared_ptr<SCENE>> mSceneMap;
};

#endif /* StarDirector_hpp */
