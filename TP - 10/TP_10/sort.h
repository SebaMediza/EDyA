//
// Created by daniel on 20/5/20.
//

#ifndef SORTSEARCH_SORT_H
#define SORTSEARCH_SORT_H

#include <iostream>

template<class T>
void showArray(T *a, int n, char sep = '\n', bool newLine = true) {
    if (newLine)
        std::cout << "\n";
    for (auto i = 0; i < n; ++i) {
        std::cout << sep << a[i];
    }
}

template<class T>
void insertion_sort(T *a, int n) {
    for (unsigned int i = 1; i < n; ++i) {
        T tmp = a[i];
        unsigned int j = i;
        while (j > 0 && tmp < a[j - 1]) {
            a[j] = a[j - 1];
            --j;
        }
        a[j] = tmp;
    }
}

template<class T>
void selection_sort(T *a, int n) {
    unsigned int i, j, m;
    T t;
    for (i = 0; i < n; i++) {
        for (j = i, m = i; j < n; j++)
            if (a[j] < a[m])
                m = j;
        t = a[i];
        a[i] = a[m];
        a[m] = t;
    }
}

template<class T>
void bubble_sort(T *a, int n) {
    bool s = true;
    T t;
    int tn = n;
    while (s) {
        s = false;
        for (unsigned int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                t = a[i];
                a[i] = a[i - 1];
                a[i - 1] = t;
                s = true;
            }
        }
        n--;
    }
}

template<class T>
void shell_sort(T *a, int n) {
    unsigned int h, i, j;
    T t;
    for (h = n; h /= 2;) {
        for (i = h; i < n; i++) {
            t = a[i];
            for (j = i; j >= h && t < a[j - h]; j -= h) {
                a[j] = a[j - h];
            }
            a[j] = t;
        }
    }
}

template<class T>
void merge(T *a, int n, int m) {
    unsigned int i, j, k;
    T *x = new T[n];
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] = (j == n) ? a[i++]
                        : i == m ? a[j++]
                                 : a[j] < a[i] ? a[j++]
                                               : a[i++];
    }
    for (i = 0; i < n; i++) {
        a[i] = x[i];
    }
    delete[] x;
}

template<class T>
void merge_sort(T *a, int n) {
    if (n < 2)
        return;
    unsigned int m = n / 2;
    merge_sort(a, m);
    merge_sort(a + m, n - m);
    merge(a, n, m);
}

template<class T>
void quicksort(T *a, int n) {
    if (n <= 1) return;
    T pivot = a[n / 2];
    int i, j;
    for (i = 0, j = n - 1;; i++, j--) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i >= j) break;
        T temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    quicksort(a, i);
    quicksort(a + i, n - i);
}

#endif //SORTSEARCH_SORT_H
