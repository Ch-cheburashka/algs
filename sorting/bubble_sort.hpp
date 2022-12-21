//
// Created by 79056 on 20.12.2022.
//

#ifndef ALGS_BUBBLE_SORT_HPP
#define ALGS_BUBBLE_SORT_HPP

#include <iostream>
#include <vector>

template <typename T>
std::vector<T> bubble_sort (std::vector<T>& vector) {
    for (size_t i = 0; i<vector.size(); ++i) {
        for (size_t j = i+1; j<vector.size(); ++j) {
            if (vector[j]<vector[i])  {
                size_t temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
            }
        }
    }
    return vector;
}

#endif //ALGS_BUBBLE_SORT_HPP
