//
// Created by 79056 on 20.12.2022.
//

#include <iostream>
#include <sorting_algorithms.hpp>


int main () {

    std::vector<int> vector = {5,6,3,1,8,7,2};

    sorting_algorithm<int> algorithm;

    algorithm.set_sorting_alg(std::make_unique<selection_sort<int>>());

    algorithm.sort(vector);

    for (auto &vec : vector) {
        std::cout << vec << " ";
    }

    return 0;
}