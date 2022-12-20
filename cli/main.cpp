//
// Created by 79056 on 20.12.2022.
//

#include <iostream>
#include <vector>
#include <linear_search.hpp>
#include <binary_search.hpp>

int main () {

    std::vector<size_t> vector;

    for (int i = 0; i<2000000; ++i)
        vector.push_back(i+1);

    size_t i = linear_search(vector,1999999);

    std::cout << i; // output: 99


    return 0;
}