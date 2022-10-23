#include <iostream>

using namespace std;

int test_pointer();


int main(){
    int test;
    test=test_pointer();
    cout << test;
    return 0;
}


int test_pointer(){

    char caracter;

    char *pointer;

    *pointer=caracter;

    int *arreglo[9];

    int *puntero,*puntero_1, cadena[9]={0};

    *puntero=cadena[0];

    *puntero_1=*puntero;

    int matriz[4][3], *puntero_2;

    puntero_2=&matriz[0][0];

    return 0;

}
