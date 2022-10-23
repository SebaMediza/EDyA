#include <iostream>
#include <vector>
#include <map>
#include "sort.h"
#include "element.h"
#include "test_stl_sort.h"

void simple() {
    int n = 7;
    int a[]{38, 27, 43, 3, 9, 82, 10};
    merge_sort(a, n);
    showArray(a, n, ' ');
}

void simple2() {
    int n = 9;
    int a[]{3, 7, 8, 5, 2, 1, 9, 5, 4};
    insertion_sort(a, n);
    showArray(a, n, ' ');
}

void all_test() {
    // Genero el conjunto de datos de prueba
    std::vector<std::vector<int>> data{
            {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},   // ordenados
            {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9,  8,  7,  6,  5,  4,  3,  2,  1},    // ordenados inv
            {12, 9,  10, 18, 11, 17, 3,  6,  19, 16, 13, 7,  15, 2,  1,  14, 20, 8,  5,  4},    // mezclados
            {12, 9,  1,  8,  11, 17, 3,  6,  1,  1,  13, 4,  15, 2,  1,  14, 20, 2,  5,  4}     // mezclados y repetidos
    };
    // Map string --> punteros a funciones que reciben como parámetro de entrada un puntero a un tipo T y un entero
    typedef void (*ptr_function)(Item<int> *, int);
    std::map<std::string, ptr_function> m{
            {"Selection Sort", &selection_sort},
            {"Bubble Sort",    &bubble_sort},
            {"Insertion Sort", &insertion_sort},
            {"Merge Sort",     &merge_sort},
            {"Quicksort",      &quicksort},
            {"Shell Sort",     &shell_sort}
    };

    for (auto it = m.begin(); it != m.end(); ++it) {
        std::cout << "\n\n---------------------------------------------------------> " << it->first;
        // Itero sobre cada uno de los algoritmos de ordenamientos
        for (std::vector<int> numbers: data) {
            // Itero sobre cada uno de los conjuntos de números a ordenar y armo un vector con Items, los ítems
            // tiene el valor numérico (clave para el ordenamiento) y un campo extra para determinar la posición
            // original del ítem antes de ordenar
            std::vector<Item<int>> items;
            for (unsigned int i = 0; i < numbers.size(); ++i)
                items.push_back(Item<int>(numbers[i], i));
            Item<int>::reset(); // Se resetea el conteo de comparaciones en Item
            auto sort_function = it->second; // obtengo el puntero a la función
            Item<int> *datos = items.data();    //  obtengo los datos a ordenar
            showArray(datos, numbers.size(), ' ');
            sort_function(datos, numbers.size());   // ordenamos
            showArray(datos, numbers.size(), ' ');
            std::cout << "\n" << Item<int>::comp; // Mostramos la cantidad de comparaciones
        }
    }
}

int main(int argc, char *argv[]) {
    simple();
    simple2();
//    all_test();
    test_sort();
    test_stable_sort();
    test_sort_vector();
    return 0;
}
