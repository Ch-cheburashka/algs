//
// Created by 79056 on 20.12.2022.
//

#include <iostream>
#include <sorting_algorithms.hpp>


int main () {

    std::vector<int> vector = {1,3,2,5,3,6,1};

    sorting_algorithm<int> algorithm;

    algorithm.set_sorting_alg(std::make_unique<comb_sort<int>>());

    algorithm.sort(vector);

    for (auto &vec : vector) {
        std::cout << vec << " ";
    }

    return 0;
}