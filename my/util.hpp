//
// Created by darinzh on 10/28/2015.
//

#ifndef CXX_UTIL_HPP
#define CXX_UTIL_HPP

#include <vector>
#include <iostream>


typedef std::vector<int> IntVector;


template<typename T>
void print(const std::vector<T> &c) {
    int sz = c.size();
    std::cout << "( ";
    for (int i = 0; i < sz - 1; ++i) {
        std::cout << c[i] << ", ";
    }

    std::cout << c.back() << " )" << std::endl;
}


#endif //CXX_UTIL_HPP
