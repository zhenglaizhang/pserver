//
// Created by darinzh on 10/27/2015.
//


#include <thread>
#include <chrono>
#include <vector>
#include <iostream>
#include "thread_pool.h"

using namespace std;
using namespace my;

void basic_check() {
    thread_pool pool(std::current_hardware_currency());
    vector<future<int>> results;

    for (int i = 0; i < 8; ++i) {
        results.emplace_back(
                pool.enqueue([i] {
                    std::cout << "hello " << i << endl;
                    std::this_thread::sleep_for(chrono::seconds(1));
                    cout << "world " << i << std::endl;
                    return (i * i);
                })
        );
    }

    for (auto &&res : results) {
        cout << res.get() << ' ';
    }
    cout << endl;
}