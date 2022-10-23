#include <iostream>
#include "filaa.h"
#include <queue>
#include <string>
#include <time.h>
using namespace std;

template <class T>
void mostrarFila(FilaA<T> queuee);
template <class T>
queue<T> insertarAlFrente(queue<T> queuee, T elemento);


int main(){
    srand(time(0));
    FilaA<int> my_queue;
    int elemento=0;

    int eleccion=0;
    do{
    cout<<"Que desea hacer?"<<endl<<"1: Encolar un numero"<<endl<<"2: Desencolar un numero"<<endl<<"3: Imprimir la Fila"<<endl<<"4: Verificar Estado"<<endl<<"5: Vaciar la Fila"<<endl<<"6: Verificar Indices"<<endl<<"7: Salir"<<endl<<"Opcion: ";
    cin>>eleccion;
    switch(eleccion){
        case 1:
            for(int i=0;i<14;i++){
                elemento=1+rand()%10;
                cout<<"Elemento: "<<elemento<<"; ";
//              cin>>elemento;
                my_queue.poner(elemento);
            }
            system("pause");
            system("cls");
            break;
        case 2:
            cout<<"Se ha eleminado el elemento "<<my_queue.recuperarFrente()<<endl;
            my_queue.quitar();
            system("pause");
            system("cls");
            break;
        case 3:
            mostrarFila(my_queue);
           break;
        case 4:
            cout<<"my_queue, esta vacia?"<<endl<<"0=NO"<<" 1=SI"<<endl<<"Resultado: "<<my_queue.estaVacia()<<";"<<endl;
            cout<<"my_queue, esta llena?"<<endl<<"0=NO"<<" 1=SI"<<endl<<"Resultado: "<<my_queue.estaLlena()<<";"<<endl;
            cout<<"Cantidad de elementos: "<<my_queue.cantidad()<<endl;
            system("pause");
            system("cls");
            break;
        case 5:
            my_queue.vaciar();
            cout<<"Fila vaciada"<<endl;
            system("pause");
            system("cls");
            break;
        case 6:
            cout<<"El indice PRIMERO esta en la pocision: "<<my_queue.re_prim()<<endl;
            cout<<"El indice ULTIMO esta en la pocision: "<<my_queue.re_ulti()<<endl;
            cout<<"La longitud del arreglo es de: "<<my_queue.long_fila()<<endl;
            system("pause");
            system("cls");
            break;
            }
    }while(eleccion!=7);
return 0;
}

template <class T>
void mostrarFila(FilaA<T> queuee){
    do{
    cout<<queuee.recuperarFrente()<<"; ";
    queuee.quitar();
    }while(!queuee.estaVacia());
    system("pause");
    system("cls");
}
template <class T>
queue<T> insertarAlFrente(queue<T> queuee, T elemento){
    queue<T> return_queue;
    return_queue.push(elemento);
    unsigned short size_queue=queuee.size();
    for(unsigned short i=0;i<size_queue;i++){
        return_queue.push(queuee.front());
        queuee.pop();
    }
return return_queue;
}
