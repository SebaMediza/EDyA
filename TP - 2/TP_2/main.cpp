#include <iostream>
#include "edya2.h"

using namespace std;

int main(){
    srand(time(0));
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-EJERCICIO_1-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
    cout<<"Manejo de Strings: "<<endl<<endl;
    cadenas();
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-EJERCICIO_3-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
    string cadena="Para cada uno de los siguientes caps escalares, indique cual es el dominio de deinicion, y encuentre el plano tangente a la grafica f en el punto.",to,from;
    cout<<cadena<<endl;
    cout<<"Desde donde arranco a copiar?: ";
    cin>>from;
    cout<<"Hasta donde copio?: ";
    cin>>to;
    replaceAll(cadena,from,to);
    cout<<endl;
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-EJERCICIO_5-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
    cout<<"Manejo de Vectores: "<<endl<<endl;
        //*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-INCISO_1-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
    int cant_valores;
    int prim_valor,seg_valor;
    vector<unsigned int> myVtc(cant_valores);
    cout<<"Ingrese el primer varlor de los numeros aleatorios(MAYOR A CERO): ";
    cin>>prim_valor;
    cout<<"Ingrese el segundo varlor de los numeros aleatorios: ";
    cin>>seg_valor;
    cout<<"Ingrese la cantidad de valores a generar: ";
    cin>>cant_valores;
    myVtc=create(cant_valores,prim_valor,seg_valor);
        //*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-INCISO_2-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
    char formato;
    format test;
    cout<<"Como desea imprimer el vector: 0=Linear; 1=Lista: ";
    cin>>formato;
    test=(format)((formato-48)%2);
    print(myVtc,test);
    cout<<endl<<endl;
        //*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-INCISO_3-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
    cout<<"Ordenamiento de los elementos: "<<endl;
    sort(myVtc);
    cout<<endl;
        //*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-INCISO_4-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
    /*vector<unsigned int> prime_vec(cant_valores),sec_vec(cant_valores),resultado(2*cant_valores);
    unsigned int posicion=0;
    cout<<"Ingrese una posicion para concatenar el vector secundario: ";
    cin>>posicion;

    for(int j=0;j<cant_valores;j++){
        sec_vec.at(j)=prim_valor+rand()%seg_valor;
    }
    cout<<"Segundo vector: ";
    for(int i=0;i<cant_valores;i++){
        cout<<sec_vec.at(i)<<"; ";
    }
    resultado=insert(myVtc,sec_vec,posicion);
    for(int i=0;i<(2*cant_valores);i++){
        cout<<resultado.at(i)<<"; ";
    }*/
        //*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-INCISO_5-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
    cout<<"Recuento de elementos: "<<endl;
    print_frequency(myVtc);
    cout<<endl;
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-EJERCICIO_7-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
    cout<<"Manejo de Queue:"<<endl;
    queue<int> myQ,myQ_copy;
    for(int i=0;i<cant_valores;i++){
        myQ.push(i);
        myQ_copy.push(i);
    }
    for(int i=0;i<cant_valores;i++){
    }
    print(myQ_copy);
    cout<<endl;
return 0;
}
