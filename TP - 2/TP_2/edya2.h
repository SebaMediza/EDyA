#ifndef EDYA2_H_INCLUDED
#define EDYA2_H_INCLUDED

#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <ctime>
#include <queue>

enum format{FMT_LINE,FMT_LIST};

using namespace std;
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-EJERCICIO_1-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
void cadenas(){

string str="TestString";

    cout<<"Operador at():"<<endl;
    for(unsigned int i=0;i<str.length();i++){
        cout<<str.at(i)<<" ";
    }
    cout<<endl<<endl;

    cout<<"Operadores de Indexacion:"<<endl;
    int longitud=0;
    longitud=str.length();
    for(int i=0;i<longitud;i++){
        cout<<str[i]<<" ";
    }
    cout<<endl<<endl;

    cout<<"Iteradores:"<<endl;
    for ( string::iterator it=str.begin(); it!=str.end(); ++it){
       cout<<*it<<" ";
    }

    cout<<endl<<endl;
    cout<<"Bucle en un Rango:"<<endl;
    for(int i:str){
        cout<<(char)i<<" ";
    }
cout<<endl;
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-EJERCICIO_3-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
string replaceAll(const string& str, const string& from, const string& to){

    string sub_str;
    string str_copy=str;

    string::size_type pos_inicial=str_copy.find(from);
    string::size_type pos_final=str_copy.find(to);

    sub_str=str_copy.substr(pos_inicial,pos_final);
    cout<<sub_str;
return sub_str;
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-EJERCICIO_5-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
vector<unsigned int> create(unsigned int N, unsigned int from, unsigned int to){
        vector<unsigned int> vtc(N);
        cout<<endl;
        cout<<"El vecto generado es: ";
        for(unsigned int i=0;i<N;i++){
            vtc.at(i)=from + rand() % to;
            cout<<vtc.at(i)<<"; ";
        }
cout<<endl<<endl;
return vtc;
}
void print(vector<unsigned int> v, format f){

    switch (f){
case 0:{
    int tamano=v.size();
    for(int i=0;i<tamano;i++){
    cout<<v.at(i)<<"; ";
    }
break;
    }
case 1:{
    int tamano=v.size();
    for(int i=0;i<tamano;i++){
    cout<<v.at(i)<<";"<<endl;
    }
break;
}
}
}
void sort(vector<unsigned int> &v){
    cout<<"Vector Desordenado: ";
    for(vector<unsigned int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<"; ";
    }

    sort(v.begin(), v.end());
    cout<<endl;

    cout<<"Vector Ordenado: ";
    for(vector<unsigned int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<"; ";
    }
cout<<endl;
}
vector<unsigned int> insert(vector<unsigned int> v1, vector<unsigned int> v2, unsigned int pos){

    vector<unsigned int>::iterator it=v1.begin()+pos;
    unsigned int tamano=v1.size()+v2.size(),control;
    v1.resize(tamano);
    control=v2.size();

    for(unsigned int i=0;i<control;i++){
        unsigned int valor;
        valor=v2.at(i);
        v1.insert(it,valor);
        it++;
    }

return v1;
}
void print_frequency(vector<unsigned int> v){
    unsigned int tamano;
    tamano=v.size();
    unsigned int control;

    vector<unsigned int> myVtc(tamano);

    for(unsigned int i=0;i<tamano;i++){
        myVtc.at(i)=v.at(i);
    }

for(unsigned int i=0;i<tamano;i++){
        control=myVtc.at(i);
        if(control!=0){
                int sumador=0,l;
    for(unsigned int i=0;i<tamano;i++){
        if(control==myVtc.at(i) && myVtc.at(i)!=0){
            sumador++;
            l=myVtc.at(i);
        }
    }
    cout<<"El numero "<<l<<" se repite "<<sumador<<" veces"<<endl;
        for(unsigned int i=0;i<tamano;i++){
            if(control==myVtc.at(i)){
                myVtc.at(i)=0;
                }
        }
        }
    }
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-EJERCICIO_7-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
void print(std::queue<int> &myqueue){

while(!myqueue.empty()){
    cout<<myqueue.front()<<"; ";
    myqueue.pop();
}
}
#endif // EDYA2_H_INCLUDED

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-LLAMADAS A LAS FUNCIONES(MAIN)-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//

//#include <iostream>
//#include "edya2.h"

//using namespace std;
//
//int main(){
//    srand(time(0));
////*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-EJERCICIO_1-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
//    cout<<"Manejo de Strings: "<<endl<<endl;
//    cadenas();
////*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-EJERCICIO_3-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
//    string cadena="Para cada uno de los siguientes caps escalares, indique cual es el dominio de deinicion, y encuentre el plano tangente a la grafica f en el punto.",to,from;
//    cout<<cadena<<endl;
//    cout<<"Desde donde arranco a copiar?: ";
//    cin>>from;
//    cout<<"Hasta donde copio?: ";
//    cin>>to;
//    replaceAll(cadena,from,to);
//    cout<<endl;
////*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-EJERCICIO_5-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
//    cout<<"Manejo de Vectores: "<<endl<<endl;
//        //*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-INCISO_1-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
//    int cant_valores;
//    int prim_valor,seg_valor;
//    vector<unsigned int> myVtc(cant_valores);
//    cout<<"Ingrese el primer varlor de los numeros aleatorios: ";
//    cin>>prim_valor;
//    cout<<"Ingrese el segundo varlor de los numeros aleatorios: ";
//    cin>>seg_valor;
//    cout<<"Ingrese la cantidad de valores a generar: ";
//    cin>>cant_valores;
//    myVtc=create(cant_valores,prim_valor,seg_valor);
//        //*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-INCISO_2-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
//    char formato;
//    format test;
//    cout<<"Como desea imprimer el vector: 0=Linear; 1=Lista: ";
//    cin>>formato;
//    test=(format)((formato-48)%2);
//    print(myVtc,test);
//    cout<<endl<<endl;
//        //*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-INCISO_3-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
//    cout<<"Ordenamiento de los elementos: "<<endl;
//    sort(myVtc);
//    cout<<endl;
//        //*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-INCISO_4-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
//    vector<unsigned int> prime_vec(cant_valores),sec_vec(cant_valores),resultado(2*cant_valores);
//    unsigned int posicion=0;
//    cout<<"Ingrese una posicion para concatenar el vector secundario: ";
//    cin>>posicion;
//
//    for(int j=0;j<cant_valores;j++){
//        sec_vec.at(j)=prim_valor+rand()%seg_valor;
//    }
//    cout<<"Segundo vector: ";
//    for(int i=0;i<cant_valores;i++){
//        cout<<sec_vec.at(i)<<"; ";
//    }
//    resultado=insert(myVtc,sec_vec,posicion);
//    for(int i=0;i<(2*cant_valores);i++){
//        cout<<resultado.at(i)<<"; ";
//    }
//        //*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-INCISO_5-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
//    cout<<"Recuento de elementos: "<<endl;
//    print_frequency(myVtc);
//    cout<<endl;
////*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-EJERCICIO_7-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
//    cout<<"Manejo de Queue:"<<endl;
//    queue<int> myQ,myQ_copy;
//    for(int i=0;i<cant_valores;i++){
//        myQ.push(i);
//        myQ_copy.push(i);
//    }
//    for(int i=0;i<cant_valores;i++){
//    }
//    print(myQ_copy);
//    cout<<endl;
//return 0;
//}
