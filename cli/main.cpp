//
// Created by 79056 on 20.12.2022.
//

#include <iostream>
#include <vector>
#include <insertion_sort.hpp>
#include <ctime>



int main () {
    unsigned int start_time =  clock();

    std::vector<size_t> vector = {1,1000,2,3,999,4,25,56,931,123,56,3,7,999,356,35667,1234,2345,11,55,22,67,24,76,88, 99};

    insertion_sort(vector);

    for (unsigned long i : vector)
        std::cout << i << " ";

    unsigned int end_time =  clock();
    unsigned int search_time = end_time - start_time;

    std::cout << std::endl << search_time;
    return 0;
}