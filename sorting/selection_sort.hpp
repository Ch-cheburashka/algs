//
// Created by 79056 on 20.12.2022.
//

#ifndef ALGS_SELECTION_SORT_HPP
#define ALGS_SELECTION_SORT_HPP

#include <iostream>
#include <vector>
#include <iterator>

template <typename T>
std::vector<T> selection_sort (std::vector<T>& vector) {
    for (size_t i = 0; i<vector.size(); ++i) {
        size_t min = i;
        for (size_t j = i+1; j<vector.size(); ++j) {
            if (vector[j] < vector[min])
                min = j;
        }
        if (min != i) {
            uint64_t tmp = vector[min];
            vector[min] = vector[i];
            vector[i] = tmp;
        }
    }
    return vector;
}


#endif //ALGS_SELECTION_SORT_HPP
