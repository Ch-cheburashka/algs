//
// Created by 79056 on 20.12.2022.
//

#include <iostream>
#include <sorting_algorithms.hpp>
#include <searching_algorithms.hpp>

int main () {

    std::vector<int> vector = {7,1,3,2,8,6};
    sorting_algorithm<int> algorithm;
    algorithm.set_sorting_alg(std::make_unique<merge_sort<int>>());
    searching_algorithm<int> search_alg;
    search_alg.set_algorithm(std::make_unique<binary_search<int>>());
    for (auto &vec : vector) {
        std::cout << vec << " ";
    }
    std::cout << "\n";
    algorithm.sort(vector);
    for (auto &vec : vector) {
        std::cout << vec << " ";
    }
    std::cout << "\n" << search_alg.search(vector,2) << "\n";
    return 0;
}