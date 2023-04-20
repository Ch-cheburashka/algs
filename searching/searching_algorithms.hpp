
#ifndef ALGS_SEARCHING_ALGORITHMS_HPP
#define ALGS_SEARCHING_ALGORITHMS_HPP

#include <vector>
#include <iostream>

template <typename T>
class i_searching_algorithms {
public:
    ~i_searching_algorithms() = default;
    virtual size_t search(const std::vector<T>& vector, const T& element) = 0;
};

template <typename T>
class searching_algorithm {
public:
    void set_algorithm (std::unique_ptr<i_searching_algorithms<T>> alg) {
        algorithm.swap(alg);
    }
    size_t search(const std::vector<T>& vector, const T& element) {
        return algorithm->search(vector,element);
    }
private:
    std::unique_ptr<i_searching_algorithms<T>> algorithm;
};

template <typename T>
class linear_search : public i_searching_algorithms<T> {
    size_t search (const std::vector<T>& vector, const T& element) {
        for (size_t i = 0; i < vector.size() ; ++i) {
            if (vector[i] == element)
                return i;
        }
        return -1;
    }
};

template <typename T>
class binary_search : public i_searching_algorithms<T> {
    size_t search(const std::vector<T>& vector, const T& element) {
        size_t start = 0;
        size_t end = vector.size() - 1;
        while (start <= end) {
            size_t middle = start + (end - start) / 2;
            if (element == vector[middle]) {
                return middle;
            }
            if (element < vector[middle])
                end = middle - 1;
            else
                start = middle + 1;

        }
        return -1;
    }
};

#endif //ALGS_SEARCHING_ALGORITHMS_HPP
