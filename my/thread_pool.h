//
// Created by darinzh on 10/27/2015.
//

#ifndef CXX_THREAD_POOL_H
#define CXX_THREAD_POOL_H

#include "conf.h"
#include <vector>
#include <queue>
#include <memory.h>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

MY_NAMESPACE_BEGIN


// TODO: https://github.com/progschj/ThreadPool/blob/master/example.cpp
    class thread_pool {
    public:
        thread_pool(size_t);

        template<typename F, typename... Args>
        auto enqueue(F &&f, Args &&... args) -> std::future<typename std::result_of<F(Args...)>::type>;

        ~thread_pool();

    private:
        // keep track of joinable threads
        std::vector<std::thread> workers;

        // task queue
        std::queue<std::function<void()>> tasks;

        // synchronization
        std::mutex queue_mutex;
        std::condition_variable cv;
        bool stop;
    };


MY_NAMESPACE_END

#endif //CXX_THREAD_POOL_H
