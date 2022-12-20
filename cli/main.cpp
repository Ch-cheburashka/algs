//
// Created by 79056 on 20.12.2022.
//

#include <iostream>
#include <vector>
#include <linear_search.hpp>

int main () {

    std::vector<int> vector;

    for (int i = 0; i<100; ++i)
        vector.push_back(i);

    std::cout << linear_search(vector,99); // output: 99


    return 0;
}