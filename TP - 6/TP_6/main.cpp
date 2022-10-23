#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "lista_a.h"
#include "lista_p.h"
#include "Punto_6.h"

#define Lista ListaA
//#define Lista ListaP

using namespace std;

void insertarOrdenado(Lista<string> &listaOrdenada, string entrada);
template<class T>
void invertir(Lista<T> &aInvertir);
//template <class T>
//Lista<T> mixList (Lista<T> l1 ,Lista<T> l2);

int main(){
    Lista<int> my_list;
    my_list.insertar(15,my_list.fin());
    cout<<my_list.recuperar(my_list.primer());
return 0;
}

//template <class T>
//Lista<T> Lista<T>::mixList (Lista<T> l){
//
//}
