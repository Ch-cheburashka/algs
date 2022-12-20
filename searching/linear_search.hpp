//
// Created by 79056 on 20.12.2022.
//

#ifndef ALGS_LINEAR_SEARCH_HPP
#define ALGS_LINEAR_SEARCH_HPP

#include <vector>

int linear_search (std::vector<int> vector, int item) {
    for (int i = 0; i < vector.size() ; ++i) {
        if (vector[i] == item)
            return i;
    }
    return -1;
}


#endif //ALGS_LINEAR_SEARCH_HPP
