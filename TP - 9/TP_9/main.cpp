//========================================//
// Estructura de Datos y Algoritmos 2015
//=======================================//
#include <iostream>
#include <string>
#include <queue>
#include <time.h>
#include "include/arbol_test.h"

using namespace std;

template <class T>
ArbolBin<T> carga_ABB(ArbolBin<T> &tree, T elemento, Nodo<T>* &Pos);
template<class T>
size_t contarNodosHojasR(ArbolBin<T> &, Nodo<T> *);
template<class T>
size_t contarNodosHojas(ArbolBin<T> &);
template<class T>
ArbolBin<T> menorABB(ArbolBin<T> &tree);

void test_abb(unsigned int cant, unsigned int N);

int main(void) {
srand(time(0));
    unsigned int valores=0,cantidad=0;
    cout<<"Que cantidad de valores queres cargar? ";
    cin>>cantidad;
    cout<<"En que rango(-N;N)? ";
    cin>>valores;
    test_abb(cantidad,valores);

/*
//    ArbolBin<int> tree;
//    Nodo<int>* *root=tree.raizArbol();
//    cout<<"Raiz: ";
//    cin>>valores;
//    tree.asignarNodo(valores,*root);
//    unsigned int contador=0;
//    do{
//    cout<<"Elemento: ";
//    int elemento=0;
//    cin>>elemento;
////    elemento=((-1)*N)+rand()%N;
//    tree.carga_ABB(tree,elemento,*root);
//    contador++;
//    }while(contador!=cantidad);
//    Mostrar(tree);

//    test_02();
*/
return 0;
}

void test_abb(unsigned int cant, unsigned int N){
    ArbolBin<int> tree;
    Nodo<int>* *root=tree.raizArbol();
    unsigned int contador=0, random_sign;
    short min_val=(1),max_val=N;
    do{
    int elemento=0;
    elemento=min_val+rand()%max_val;
//    random_sign = (rand() % 2);
//    if (random_sign==0){
//        elemento=-elemento;
//        }
//    tree.carga_ABB(elemento,*root);
    carga_ABB(tree,elemento,*root);
    contador++;
    }while(contador!=cant);
    if(contador==cant){
    Mostrar(tree);
    system("pause");
    if(tree.esCompleto()){
        cout<<"Si";
    }else{
        cout<<"No";
    }
    cout<<endl<<contarNodosHojas(tree);
    }
    Nodo<int>* *menor=menorABB(tree);
    cout<<menor;
}

template <class T>
ArbolBin<T> carga_ABB(ArbolBin<T> &tree, T elemento, Nodo<T>* &Pos){
    if(*tree.raizArbol()==nullptr){
            tree.asignarNodo(elemento,Pos);
        }
        if(elemento>tree.recuperar(Pos)){
            if(*tree.hijoDer(Pos)==nullptr){
                tree.asignarNodo(elemento,*tree.hijoDer(Pos));
            }else{
                carga_ABB(tree,elemento,*tree.hijoDer(Pos));
            }
        }else{
        if(elemento<tree.recuperar(Pos)){
            if(*tree.hijoIzq(Pos)==nullptr){
                tree.asignarNodo(elemento,*tree.hijoIzq(Pos));
            }else{
                carga_ABB(tree,elemento,*tree.hijoIzq(Pos));
            }
        }
    }
return tree;
}

template<class T>
size_t contarNodosHojas(ArbolBin<T> &A){
Nodo<T>* *aux= A.raizArbol();
if(*aux){
    contarNodosHojasR(A,*aux);
} else error("arbol vacio",EXIT_ERROR);
}

template<class T>
size_t contarNodosHojasR(ArbolBin<T> &A, Nodo<T> *p){
if(p==NULL)
    return 0;
if(*A.hijoDer(p)==NULL && *A.hijoIzq(p)==NULL){
    return 1;
} else return (contarNodosHojasR(A,*A.hijoIzq(p))+contarNodosHojasR(A,*A.hijoDer(p)));
}

template<class T>
ArbolBin<T> menorABB(ArbolBin<T> &tree){
    Nodo<T>* *root=tree.raizArbol();

    if(root==nullptr){
        exit(0);
    }

    if(tree.hijoIzq(root)==nullptr){
        return *root;
    }else{
        root=tree.hijoIzq(root);
    }
}
