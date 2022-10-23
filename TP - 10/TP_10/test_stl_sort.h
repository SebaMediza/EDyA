//
// Created by daniel on 1/6/20.
//
// Ejemplo de uso de los algoritmos de ordenamientos provistos por STL

#ifndef SORTSEARCH_TEST_STL_SORT_H
#define SORTSEARCH_TEST_STL_SORT_H

#include <algorithm>
#include <iostream>
#include <vector>


/*
 * std::sort() in C++
 * Time Complexity
 * Best Case – O(N log N)
 * Average Case- O(N log N)
 * Worse Case- O(N log N)
 * where, N = number of elements to be sorted.
 */
void test_sort() {
    std::cout << "\ntest_sort\n";
    int array[] = { 5, 2, 9, 5, 3, 1, 8};
    size_t size = sizeof(array) / sizeof(array[0]);
    std::sort(array, array + size);
    for (size_t i = 0; i < size; ++i)
        std::cout << array[i] << ' ';
    std::cout << std::endl;
}
/*
 * std::stable_sort() in C++
 * Time Complexity
 * Best Case – O(N)
 * Average Case- O(N)
 * Worse Case- O(N)
 * where, N = number of elements to be sorted.
 */
void test_stable_sort() {
    std::cout << "\ntest_stable_sort\n";
    int array[] = { 5, 2, 9, 5, 3, 1, 8};
    size_t size = sizeof(array) / sizeof(array[0]);
    std::stable_sort(array, array + size);
    for (size_t i = 0; i < size; ++i)
        std::cout << array[i] << ' ';
    std::cout << std::endl;
}


void test_sort_vector() {
    std::cout << "\ntest_sort_vector\n";
    std::vector<int> v = { 5, 2, 9, 5, 3, 1, 8};
    std::sort(v.begin(), v.end());
    for(auto e : v)
        std::cout << e << ' ';
    std::cout << std::endl;
}

#endif //SORTSEARCH_TEST_STL_SORT_H
