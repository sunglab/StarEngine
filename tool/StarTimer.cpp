
//
//  StarTimer.cpp
//
//  Created by sungwoo choi on 8/25/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#include "StarTimer.h"
#include <chrono>

uint64_t StarTimer::getMS()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch())
            .count();
}

void StarTimer::getFPS() 
{ 
	static uint64_t framePerSecond = 0; 
	static uint64_t lastTime = 0;
	static uint64_t prev = 0;
	uint64_t current = getMS();
	++framePerSecond;

	if (current - lastTime > 1000) { // when longer than 1 second
		lastTime = current; // init 
		delegate->CallbackFPS((int)framePerSecond);
        frame++;
		framePerSecond = 0; 
	}
    delegate->CallbackTICK(static_cast<double>(current-prev));
	prev = current;
}

uint64_t StarTimer::getFrame()
{
    return frame;
}
