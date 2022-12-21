//
// Created by 79056 on 21.12.2022.
//

#ifndef ALGS_INSERT_SORT_HPP
#define ALGS_INSERT_SORT_HPP

#include <vector>
#include <iostream>

template <typename T>
std::vector<T> insertion_sort(std::vector<T>& vector) {
    for (long int i = 1; i < vector.size(); i++) {
        T temp = vector[i];
        long int j = i - 1;
        while (temp < vector[j] && j >= 0) {
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = temp;
    }
    return vector;
}


#endif //ALGS_INSERT_SORT_HPP
