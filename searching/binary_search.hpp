//
// Created by 79056 on 20.12.2022.
//

#ifndef ALGS_BINARY_SEARCH_HPP
#define ALGS_BINARY_SEARCH_HPP

#include <vector>
#include <iostream>

template <typename T>
T binary_search(std::vector<T> arr, size_t item) {
    size_t start = 0;
    size_t end = arr.size() - 1;

    while (start <= end) {
        size_t middle = start + (end - start) / 2;

        if (item == arr[middle]) {
            return middle;
        }

        if (item < arr[middle])
            end = middle - 1;
        else
            start = middle + 1;

    }
    return -1;
}

#endif //ALGS_BINARY_SEARCH_HPP
