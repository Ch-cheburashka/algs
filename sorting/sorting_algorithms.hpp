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
        if (vector.empty()) { return; }
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
        if (vector.empty()) { return; }
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
        if (vector.empty()) { return; }
        for (auto i = vector.begin(); i != vector.end(); ++i) {
            auto min = std::min_element(i,vector.end());
            std::swap(*i,*min);
        }
    }
};


template <typename T>
class quick_sort : public i_sorting_algorithms<T> {
    size_t partition (std::vector<T>& vector, int l, int r) {
        T pivot = vector[r];
        size_t low = l;
        for (size_t i = l; i < r; ++i) {
            if (vector[i] <= pivot) {
                std::swap(vector[i], vector[low]);
                ++low;
            }
        }
        std::swap(vector[low], vector[r]);
        return low;
    }

    void _quick_sort (std::vector<T>& vector, int l, int r) {
        if (l < r) {
            size_t q = partition(vector, l, r);
            _quick_sort(vector, l, q - 1);
            _quick_sort(vector, q + 1, r);
        }
    }

    void sort(std::vector<T>& vector) {
        if (vector.empty()) { return; }
        _quick_sort(vector,0,vector.size()-1);
    }
};


template <typename T>
class merge_sort : public i_sorting_algorithms<T> {
    void merge(std::vector<T>& vector, size_t l, size_t r, size_t mid) {
        size_t i_1 = l, i_b = l, i_2 = mid+1;
        std::vector<T> buffer(vector.size());
        while (i_1 <= mid && i_2 <= r) {
            if (vector[i_1] < vector[i_2]) {
                buffer[i_b] = vector[i_1];
                i_b++;
                i_1++;
            }
            else  {
                buffer[i_b] = vector[i_2];
                i_b++;
                i_2++;
            }
        }
        while (i_1 <= mid) {
            buffer[i_b] = vector[i_1];
            i_b++;
            i_1++;
        }
        while (i_2 <= r) {
            buffer[i_b] = vector[i_2];
            i_b++;
            i_2++;
        }
        for (i_1 = l; i_1 < i_b; i_1++)  {
            vector[i_1] = buffer[i_1];
        }
    }

    void _merge_sort (std::vector<T>& vector, size_t l, size_t r) {
        size_t mid;
        if (l < r){
            mid=(l+r)/2;
            _merge_sort(vector,l,mid);
            _merge_sort(vector,mid+1,r);
            merge(vector,l,r,mid);
        }
    }

    void sort(std::vector<T>& vector) {
        _merge_sort(vector,0,vector.size()-1);
    }
};

#endif //ALGS_SORTING_ALGORITHMS_HPP
