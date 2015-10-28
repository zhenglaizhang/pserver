//
// Created by darinzh on 10/28/2015.
//

#ifndef CXX_SEARCH_HPP
#define CXX_SEARCH_HPP

#include <vector>

template<typename T>
int search_lineral(const std::vector<T> &V, const T &val) {
    for (int i = 0; i < V.size(); ++i) {
        if (V[i] == val)
            return i;
    }

    return -1;
}

template<typename T>
int BinarySearch(const std::vector<T> &V, int l, int r, const T &val) {
    if (l > r) { return -1; }

    int m = l + (r - l) / 2;
    if (V[m] == val)
        return m;
    else if (V[m] > val)
        return BinarySearch(V, l, m - 1, val);
    else
        return BinarySearch(V, m + 1, r, val);
}

template<typename T>
int BinarySearch(const std::vector<T> &V, const T &val) {
    return BinarySearch(V, 0, V.size() - 1, val);
}

template<typename T>
int BinarySearch(const std::vector<T> &V, const T &val) {
    int l = 0, r = V.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (V[m] == val)
            return m;
        else if (V[m] > val)
            r = m - 1;
        else
            l = m + 1;
    }

    return -1;
}


#endif //CXX_SEARCH_HPP
