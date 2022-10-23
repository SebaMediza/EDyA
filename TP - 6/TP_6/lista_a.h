#ifndef LISTAA_H
#define LISTAA_H

#ifndef EXIT_ERROR
#define EXIT_ERROR 250
#endif

#include <iostream>
#include <cstdlib>

template<class T, unsigned short CANTELE=100>
class ListaA {
public:

    typedef int posicion;

    ListaA() {
        ultimo=-1;
        cant=0;
    };

    void insertar(T x, posicion p) {
        if((p>=0) && (p<=ultimo+1)) {
            int i;
            for(i=ultimo; i>=p; i--) {
                elementos[i+1] = elementos[i];
            }
            elementos[p] = x;
            ultimo++;
            cant++;
        } else {
            std::cerr << "\nHa intentado insertar en una posicion invalida\n";
            exit(EXIT_ERROR);
        }
    };

    void eliminar(posicion p) {
        if((p>=0) && (p<=ultimo)) {
            int i;
            for(i=p; i<ultimo; i++) {
                elementos[i] = elementos[i+1];
            }
            ultimo--;
            cant--;
        } else {
            std::cerr << "\nHa intentado eliminar en una posicion invalida\n";
            exit(EXIT_ERROR);
        }
    };

    int cantidad() {
        return(cant);
    };

    posicion localizar(T x) {
        int i;
        for(i=0; ((i<=ultimo)&&(elementos[i]!=x)); i++);
        return(i);
    };

    T recuperar(posicion p) {
        T result;
        if((p>=0) && (p<=ultimo))
            result = elementos[p];
        else {
            std::cerr << "\nHa intentado recuperar en una posicion invalida\n";
            exit(EXIT_ERROR);
        }
        return(result);
    };

    posicion siguiente(posicion p) {
        posicion result;
        if((p>=0) && (p<=ultimo)) {
                result=p+1;
        } else {
             std::cerr << "\nHa intentado encontrar el proximo de una posicion invalida\n";
            exit(EXIT_ERROR);
        }
        return(result);
    };

    posicion anterior(posicion p) {
        posicion result;
        if((p>0) && (p<=ultimo+1)) {
                result = p-1;
        } else {
            std::cerr << "\nHa intentado obtener el anterior de una posicion invalida\n";
            exit(EXIT_ERROR);
        }
        return(result);
    };

    posicion fin() {
        return(ultimo+1);
    };

    posicion primer() {
        return 0;
    };

    void vaciar() {
        ultimo = -1;
        cant = 0;
    }
/*
    ListaA mixList(ListaA l){
        ListaA<T> return_list;
        typename ListaA<T>::posicion pos_1=l.primer();
        typename ListaA<T>::posicion pos_2=*this.primer();
        int cont=0,elementos;
        bool control_void_l1=true;
        bool control_void_l2=true;

        while(pos_1!=l.fin()){
            cont++;
            pos_1=l.siguiente(pos_1);
        }
        while(pos_2!=*this.fin()){
            cont++;
            pos_2=*this.siguiente(pos_2);
        }
        pos_1=l.primer();
        pos_2=*this.primer();

        while(cont!=0){
            if(pos_1==l.fin()){
                control_void_l1=false;
            }
            if(control_void_l1==true){
                return_list.insertar(l.recuperar(pos_1),return_list.fin());
                pos_1=l.siguiente(pos_1);
                cont--;
            }
            if(pos_2==*this.fin()){
                control_void_l2=false;
            }
            if(control_void_l2==true){
                return_list.insertar(*this.recuperar(pos_2),return_list.fin());
                pos_2=*this.siguiente(pos_2);
                cont--;
                }
        }
return return_list;
};
*/
protected:

private:
    T elementos[CANTELE];
    posicion ultimo;
    int cant;
};

void test_lista_a(){
    std::cout << std::endl << "Test lista array" << std::endl;
    int cantidad;
	ListaA<int> numeros;
	numeros.vaciar();

	for (cantidad=0;(cantidad<10);cantidad++)
			numeros.insertar(cantidad, numeros.fin());

	ListaA<int>::posicion pos=numeros.primer();
	while(pos!=numeros.fin()){
		std::cout << numeros.recuperar(pos) << "; ";
		pos=numeros.siguiente(pos);
	}
}

#endif // LISTAA_H
