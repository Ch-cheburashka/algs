#ifndef ALGS_SORTING_ALGORITHMS_HPP
#define ALGS_SORTING_ALGORITHMS_HPP
#include <vector>
#include <memory>
#include <algorithm>

template <typename T>
class i_sorting_algorithms {
public:
    ~i_sorting_algorithms() = default;
    virtual void sort(std::vector<T>& vector) = 0;
};

template <typename T>
class sorting_algorithm {
public:
    void set_sorting_alg(std::unique_ptr<i_sorting_algorithms<T>> alg) {
        algorithm.swap(alg);
    }
    void sort(std::vector<T>& vector) {
        return algorithm->sort(vector);
    }
private:
    std::unique_ptr<i_sorting_algorithms<T>> algorithm;
};

template <typename T>
class bubble_sort : public i_sorting_algorithms<T> {
    void sort(std::vector<T>& vector) {
        if (vector.empty())
            return;
        for (size_t i = 0; i < vector.size(); ++i) {
            for (size_t j = 0; j < vector.size() - i - 1; ++j) {
                if (vector[j + 1] < vector[j])
                    std::swap(vector[j], vector[j + 1]);
            }
        }
    }
};

template <typename T>
class shake_sort : public i_sorting_algorithms<T> {
    void sort(std::vector<T>& vector) {
        if (vector.empty()) { return; }
        size_t right = vector.size() - 1, left = 0;
        while (left <= right) {
            for (size_t i = right; i > left; --i) {
                if (vector[i - 1] > vector[i])
                    std::swap(vector[i - 1], vector[i]);
            }
            ++left;
            for (size_t i = left; i < right; ++i) {
                if (vector[i] > vector[i + 1])
                    std::swap(vector[i], vector[i + 1]);
            }
            --right;
        }
    }
};

template <typename T>
class comb_sort : public i_sorting_algorithms<T> {
    void sort (std::vector<T>& vector) {
        if (vector.empty()) { return; }
        const double factor = 1.247;
        double step = vector.size() - 1;
        while (step >= 1) {
            for (int i = 0; i + step < vector.size(); ++i) {
                if (vector[i] > vector[i + step]) {
                    std::swap(vector[i], vector[i + step]);
                }
            }
            step /= factor;
        }
    }
};

template <typename T>
class insertion_sort : public i_sorting_algorithms<T> {
    void sort (std::vector<T>& vector) {
        if (vector.empty())
            return;
        for (size_t i = 1; i < vector.size(); ++i) {
            T temp = vector[i];
            size_t j = i;
            for (;j > 0 && vector[j - 1] > temp;--j)
                vector[j] = vector[j - 1];
            vector[j] = temp;
        }
    }
};

template <typename T>
class selection_sort : public i_sorting_algorithms<T> {
    void sort(std::vector<T>& vector) {
        for (auto i = vector.begin(); i != vector.end(); ++i) {
            auto min = std::min_element(i,vector.end());
            std::swap(*i,*min);
        }
    }
};

#endif //ALGS_SORTING_ALGORITHMS_HPP
