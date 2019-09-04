//
// Created by Sung on 2018/08/11.
//

#ifndef THREAD_STARTHREADPOOL_H
#define THREAD_STARTHREADPOOL_H

#include <mutex>
#include <thread>
#include <condition_variable>
#include <queue>
#include <vector>
#include <future>
#include <functional>
#include <type_traits>
#include "star.h"
#include "../StarMain.h"

class StarThreadPool {
    
    unsigned int NumOfWorkers;
    std::queue<std::function<void()>> Tasks;
    std::vector<std::thread> Workers;
    std::mutex PoolMutex;
    bool IsItRunning = false;
    std::condition_variable TaskCondition;
    
public:
    
    StarThreadPool(unsigned int TotalWorkers);
    
    void Compute();

    template <class FUN, class... ARGS>
//    std::future<typename std::result_of<FUN(ARGS...)>::type> DoMoreWork(FUN&& fun, ARGS&&... args) {
    std::future<typename std::invoke_result<FUN, ARGS...>::type> DoMoreWork(FUN&& fun, ARGS&&... args) {
        if(!IsItRunning)
            throw std::runtime_error("Pool Stopped");
        
        //Deprecated in 17
//        using TYPE = typename std::result_of<FUN(ARGS...)>::type;
        using TYPE = typename std::invoke_result<FUN, ARGS...>::type;
        //Fowarding with && Not to be Copied
        std::packaged_task<TYPE()> TASK(std::bind(std::forward<FUN>(fun),
                                                  std::forward<ARGS>(args)... ));
        
        auto TaskResult = TASK.get_future();
        {
            std::lock_guard<std::mutex> Lock(PoolMutex);
            Tasks.push([&TASK](){
                TASK();
            });
        }
        TaskCondition.notify_one();
        return TaskResult;
    }
    ~StarThreadPool();
};

#endif //THREAD_STARTHREADPOOL_H
