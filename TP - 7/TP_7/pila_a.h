#ifndef PILAA_H
#define PILAA_H
#ifndef EXIT_ERROR
#define EXIT_ERROR 253
#endif
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
/**
 * Implementación parametrizable del TDA Pila.
 * Se utiliza un array de tipo T para almacenar los elementos en memoria.
 */
template <class T, unsigned int LONG_MAX_PILA=15>
class PilaA {
public:
    PilaA() {
        tope = LONG_MAX_PILA;
        cant = 0;
    };
    ~PilaA() {}
    bool estaVacia() {
        return tope == LONG_MAX_PILA;
    }
    void apilar(T x) {
        if (tope==0) {
            std::cout << "La pila esta llena" << std::endl;
            exit(EXIT_ERROR);
        } else {
            tope--;
            elementos[tope] = x;
            cant++;
        }
    }
    void desapilar() {
        if (tope==LONG_MAX_PILA) {
            std::cerr<<"Ha intentado despilar de una pila vacia"<<std::endl;
            exit(EXIT_ERROR);
        } else {
            tope++;
            cant--;
        }
    }
    T recuperarTope() {
        T resul;
        if (tope==LONG_MAX_PILA) {
            std::cerr<<"Ha intentado obtener el tope de una pila vacia"<<std::endl;
            exit(EXIT_ERROR);
        } else
            resul = elementos[tope];
        return resul;
    }
    unsigned int cantidad() {
        return cant;
    }
/*
    void swap(PilaA &x){
        vector<T> vec_x(x.cantidad()),vec_this(this->cantidad());
        T var_aux_this,var_aux_x;
        int control_this=this->cantidad();
        int control_x=x.cantidad();

        for(int i=0;i<control_this;i++){
            var_aux_this=this->recuperarTope();
            vec_x.at(i)=var_aux_this;
            this->desapilar();
        }
        for(int i=0;i<control_x;i++){
            var_aux_x=x.recuperarTope();
            vec_this.at(i)=var_aux_x;
            x.desapilar();
        }
        cout<<"vec_this:"<<endl;
        for(int i=0;i<3;i++){
            cout<<vec_this.at(i)<<";"<<endl;
        }
        cout<<"vec_x:"<<endl;
        for(int i=0;i<3;i++){
            cout<<vec_x.at(i)<<";"<<endl;
        }
        while(!this->estaVacia()){
            this->desapilar();
        }
        while(!x.estaVacia()){
            x.desapilar();
        }
        cout<<this->estaVacia()<<endl;
        cout<<x.estaVacia()<<endl;

        for(typename vector<T>::iterator it_this=vec_this.begin();it_this!=vec_this.end();){
            this->apilar(vec_this[*it_this]);
            it_this++;

        }
        for(typename vector<T>::iterator it_x=vec_x.begin();it_x!=vec_x.end();it_x++){
            x.apilar(vec_x[*it_x]);
        }
        cout<<this->estaVacia()<<endl;
        cout<<x.estaVacia()<<endl;
        control_this=this->cantidad();
        control_x=x.cantidad();
        cout<<"Pila pasada por parametro: "<<endl;
        for(int i=0;i<control_x;i++){
            cout<<x.recuperarTope()<<";"<<endl;
            x.desapilar();
        }
        cout<<"Objeto Implicito: "<<endl;
        for(int i=0;i<control_this;i++){
            cout<<this->recuperarTope()<<";"<<endl;
            this->desapilar();
        }
    }

    void desapilarN(unsigned int N){

        if(N>this->cantidad()){
            cout<<endl<<"Esta intentando desapilar mas elementos de los que tiene la pila."<<endl;
            exit(EXIT_ERROR);
        }else{
        for(unsigned int i=0;i<N;i++){
            this->desapilar();
        }
        cout<<"La pila resultante es: "<<endl;
        while(!this->estaVacia()){
            cout<<this->recuperarTope()<<";"<<endl;
            this->desapilar();
        }
        }
    }
    */
protected:
private:
    T elementos[LONG_MAX_PILA];
    int tope;
    int cant;
};

void test_pila() {
    PilaA<int,25> numeros;

    std::cout << __func__ << std::endl;
    std::cout << "La pila posee " << numeros.cantidad() << " elementos" << std::endl;
    ///////////////////////////////////////////////////
    for (unsigned short i=0; i<12; ++i)
        numeros.apilar(1+i);
    ///////////////////////////////////////////////////
    if (!numeros.estaVacia())
        std::cout << "El elemento que se encuentra en el tope es " << numeros.recuperarTope() << std::endl;
    if (!numeros.estaVacia())
        numeros.desapilar();
    if (!numeros.estaVacia())
        std::cout << "El elemento que se encuentra en el tope es " << numeros.recuperarTope() << std::endl;
    ///////////////////////////////////////////////////
    std::cout << "La pila posee " << numeros.cantidad() << " elementos" << std::endl;
    ///////////////////////////////////////////////////
    std::cout << "Elementos: ";
    while (!numeros.estaVacia()) {
        std::cout << std::setw(3) << std::setfill(' ') << numeros.recuperarTope() << ", ";
        numeros.desapilar();
    }
    ///////////////////////////////////////////////////
    std::cout << std::endl << "La pila posee " << numeros.cantidad() << " elementos" << std::endl;
    std::cout << "La pila esta vacia " << (numeros.estaVacia()?"Si":"No") << std::endl;

}

#endif  // PILAA_H
