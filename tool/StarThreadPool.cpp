//
// Created by Sung on 2019/09/02.
//

#include "StarThreadPool.h"

StarThreadPool::StarThreadPool(unsigned int TotalWorkers):IsItRunning(true),
NumOfWorkers(TotalWorkers) {
    Workers.reserve(TotalWorkers);
    for(int i = 0; i < TotalWorkers; i++)
        Workers.emplace_back([this](){
            this->Compute();
        });
}

void StarThreadPool::Compute() {
    
    while(true) {
        std::unique_lock<std::mutex> Lock(PoolMutex);
        TaskCondition.wait(Lock, [this]() {
            return (!this->Tasks.empty()) || !IsItRunning;
        });
        
        if (this->Tasks.empty() && !IsItRunning) {
            return;
        }
        
        auto Task = std::move(Tasks.front());
        Tasks.pop();
        Lock.unlock();
        
        Task();
    }
}

StarThreadPool::~StarThreadPool() {
    IsItRunning = false;
    TaskCondition.notify_all();
    for(auto& w: Workers)
        w.join();
}

