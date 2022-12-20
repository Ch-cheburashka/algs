//
// Created by 79056 on 20.12.2022.
//

#ifndef ALGS_LINEAR_SEARCH_HPP
#define ALGS_LINEAR_SEARCH_HPP

#include <vector>
#include <iostream>

size_t linear_search (std::vector<size_t> vector, size_t item) {
    for (int i = 0; i < vector.size() ; ++i) {
        if (vector[i] == item)
            return i;
    }
    return -1;
}


#endif //ALGS_LINEAR_SEARCH_HPP
