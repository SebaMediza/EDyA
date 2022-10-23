#include <iostream>
#include <ctime>
#include <cassert>

#include "arbolbin.h"
#include "arbolbinviewer.h"

void GenerarArray(int array[],int min,int max,int cant) {
    srand (time(NULL));
    for(int i=0;i<cant;i++)
        array[i]=(int) ((rand()%(max-min)+min));
}

void CargarArrayEnArbol(ArbolBin<int> &arbolito,int array[],Nodo<int>* &posi,int pri,int ult) {
    if(pri<ult) {
        int medio=(int) ((pri+ult)/2);
        arbolito.asignarNodo(array[medio],posi);
        Nodo<int>* *temp1=arbolito.hijoIzq(posi);
        CargarArrayEnArbol(arbolito,array,*temp1,pri,medio);
        Nodo<int>* *temp2=arbolito.hijoDer(posi);
        CargarArrayEnArbol(arbolito,array,*temp2,medio+1,ult);
    }

}

template<typename T> void Mostrar(ArbolBin<T> &a){
    ArbolBinViewer<T> arbolBinViewer(&a);
    arbolBinViewer.view();
}

/**
 * @brief
El recorrido para mostrar el árbol, no es ninguno de los clásicos (Pre,In,Postorden),
primero se muestra la raíz del árbol, luego el sub árbol derecho y por último el sub árbol
izquierdo. La vista es similar a la de un directorio.
    Raíz
     |___HDer
     |___HIzq
Si no existe alguno de los hijos muestra.
    Raíz
     |___H
Lo cual imposibilita distinguir cual hijo es el que se muestra.
El parámetro nivel de la función Mostrar se utiliza para tabular la información de acuerdo al nivel al cual
pertenezca el nodo que se está mostrando.
 * @param a ArbolBin
 * @param n Nodo
 * @param nivel char
 */
template<typename T>
void Mostrar(ArbolBin<T> &a, Nodo<T>* n,char nivel){
    if(n!=nullptr){
        std::cout << endl;
        for(char i=0;i<nivel;i++)
            std::cout << "    ";
        std::cout<< a.recuperar(n);
        Mostrar(a,*a.hijoDer(n),nivel+1);
        Mostrar(a,*a.hijoIzq(n),nivel+1);
    }
}

void test_00(){
    ArbolBin<int> a;
    Nodo<int>* *r=a.raizArbol();
    assert(r!=nullptr);
    assert(*r==nullptr);
    a.asignarNodo(1, *r);
    assert(a.recuperar(*r)==1);
    assert(*a.hijoIzq(*r)==nullptr);
    assert(*a.hijoDer(*r)==nullptr);
    a.asignarNodo(2, *r);
    assert(a.recuperar(*r)==2);
    a.modificarDato(3, *r);
    assert(a.recuperar(*r)==3);    
    a.asignarNodo(31, *a.hijoIzq(*r));
    assert(a.recuperar(*a.hijoIzq(*r))==31);
    a.talar();
    assert(*r==nullptr);
    assert(r!=nullptr);
}

void test_01(){
    ArbolBin<string> search;
    Nodo<string>* *r=search.raizArbol();
    search.asignarNodo("Karen", *r);
    search.asignarNodo("bob", *search.hijoIzq(*r));
    search.asignarNodo("Robert", *search.hijoDer(*r));
    if(*search.hijoIzq(*r)!=nullptr){
        search.asignarNodo("Alan", *search.hijoIzq(*search.hijoIzq(*r)));
        search.asignarNodo("Daisy", *search.hijoDer(*search.hijoIzq(*r)));
    }
    search.asignarNodo("Bob", *search.hijoIzq(*r));
    Mostrar(search,*r,0);
    Mostrar(search);
    search.talar();
}

void test_02(){
    ArbolBin<int> arbolito;
    Nodo<int>* *R;
    R=arbolito.raizArbol();
    int array[100];
    int cant=15;
    int min=97, max=122;
    GenerarArray(array,min,max,cant);
    CargarArrayEnArbol(arbolito,array,*R,0,cant);
    //mostrar arbol
    cout << "Arbol: " << endl;
    Mostrar(arbolito,*R,0);
    Mostrar(arbolito);
    arbolito.talar();
}
