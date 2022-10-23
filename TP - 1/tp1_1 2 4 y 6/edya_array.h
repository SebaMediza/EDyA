#ifndef EDYA_ARRAY_H_INCLUDED
#define EDYA_ARRAY_H_INCLUDED
#include <iostream>
#include <stdlib.h>
using namespace std;


struct EArray{
int *array;
int size;
};

EArray createArray(size_t n){

EArray earray;
earray.array=(int*)malloc(n*sizeof(int));
earray.size=(int)n;
cout << "Ingrese el arreglo" << endl;

for(int i=0;i<n;i++){
  cin >> earray.array[i];
}

return earray;

}

void resize(EArray &earray, size_t new_n){

EArray aux;

aux.array=(int*)malloc((earray.size)*sizeof(int));
aux.size=earray.size;

for(int i=0;i<earray.size;i++){
    aux.array[i]=earray.array[i];
}

earray.array=(int*)malloc((new_n)*sizeof(int));
earray.size=(int)new_n;

for(int j=0;j<new_n;j++){
    earray.array[j]=aux.array[j];
}

}

void show(EArray &earray){

 cout << "El arreglo es:";

    for(int i=0;earray.array[i]!=NULL;i++){
        cout << earray.array[i] << " ";
    }
}

#endif // EDYA_ARRAY_H_INCLUDED
