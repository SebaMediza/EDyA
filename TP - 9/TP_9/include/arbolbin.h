// Copyright [2019] <Estructura de Datos y Algoritmos>

#include <iostream>
#include <string>

#define EXIT_ERROR 255

using namespace std;

/**
 * @brief Imprime mensaje de error y finaliza el programa
 * @param mensaje
 * @param cod
 */
void error(const std::string &mensaje, int cod) {
    std::cerr << mensaje;
    exit(cod);
}

template<class T>
struct Nodo {
 public:
    T elemento;
    Nodo<T> *HIzq;
    Nodo<T> *HDer;
};


template<class T>
class ArbolBin{
 private:
        Nodo<T> *raiz;
        void talarR(Nodo<T> *pos);
 public:
        ArbolBin();
        Nodo<T>* padre(Nodo<T>*, Nodo<T>*);
        Nodo<T>* *hijoIzq(Nodo<T>*);
        Nodo<T>* *hijoDer(Nodo<T>*);
        T recuperar(Nodo<T>*);
        Nodo<T>* *raizArbol();
        void asignarNodo(const T &, Nodo<T>* &);
        void modificarDato(const T &, Nodo<T>*);
        void talar();

        //**//**//**//**//
        void listarPostOrden();
        void listarPostOrdenR(Nodo<T> *);
        bool esCompleto();
        int height(Nodo<T> *);
        bool esCompletoR(Nodo<T> *, int , int );
        int cantidad(Nodo<T> *);
        void carga_ABB(T ,Nodo<T>* &);
        friend ostream& operator << (ostream& out, const ArbolBin &A) {return out << A.elemento;}
};

template<class T>
ArbolBin<T>::ArbolBin() {
    raiz = nullptr;
}

template<class T>
Nodo<T>* *ArbolBin<T>::raizArbol() {
    return &raiz;
}

template<class T>
void ArbolBin<T>::asignarNodo(const T &x, Nodo<T>* &p) {
    if (p == nullptr) {
        p = new Nodo<T>;
        if (p) {
            p->HDer = p->HIzq = nullptr;
            p->elemento = x;
        }
    } else {
        p->elemento = x;
    }
}

template<class T>
Nodo<T>* ArbolBin<T>::padre(Nodo<T> *p, Nodo<T> *A) {
    Nodo<T> *R;
    if ((A == nullptr) || (p == nullptr)) {
        R = nullptr;
    } else {
        if (A->HIzq == p || A->HDer == p) {
            R = A;
        } else {
            R = padre(p, A->HIzq);
            if (R == nullptr)
                R = padre(p, A->HDer);
        }
    }
    return R;
}

template<class T>
Nodo<T>* *ArbolBin<T>::hijoIzq(Nodo<T> *p) {
    if (p == nullptr)
        error("Ha intentado obtener el hijo izq. de un nodo inexistente",
        EXIT_ERROR);
    return &(p->HIzq);
}

template<class T>
Nodo<T>* *ArbolBin<T>::hijoDer(Nodo<T> *p) {
    if (p == nullptr)
        error("Ha intentado obtener el hijo der. de un nodo inexistente",
        EXIT_ERROR);
    return &(p->HDer);
}

template<class T>
T ArbolBin<T>::recuperar(Nodo<T> *p) {
    T r;
    if (p)
        r = p->elemento;
    else
        error("Ha intentado recuperar en una posicion inexistente", EXIT_ERROR);
    return r;
}

template<class T>
void ArbolBin<T>::modificarDato(const T &x, Nodo<T> *p) {
    if (p)
        p->elemento = x;
    else
        error("Ha intentado modificar en una posicion inexistente", EXIT_ERROR);
}

template<class T>
void ArbolBin<T>::talar() {
    if (raiz) {
        talarR(raiz);
        delete raiz;
        raiz = nullptr;
    }
}

template<class T>
void ArbolBin<T>::talarR(Nodo<T> *p) {
    if (p) {
        if (p->HIzq) {
            talarR(p->HIzq);
            delete p->HIzq;
            p->HIzq = nullptr;
        }
        if (p->HDer) {
            talarR(p->HDer);
            delete p->HDer;
            p->HDer = nullptr;
        }
    }
}

template <class T>
void ArbolBin<T>::carga_ABB(T elemento,Nodo<T>* &r){
        if(this->raiz==nullptr){
            asignarNodo(elemento,r);
        }else{
        if(elemento>r->elemento){
            if(r->HDer==nullptr){
                asignarNodo(elemento,r->HDer);
            }else{
                carga_ABB(elemento,r->HDer);
            }
        }else{
        if(elemento<r->elemento){
            if(r->HIzq==nullptr){
                asignarNodo(elemento,r->HIzq);
            }else{
                carga_ABB(elemento,r->HIzq);
                }
            }
        }
    }
}

//**// GRUPO 005 - ROCIO LEGUIZAMON Y SEBASTIAN MEDIZA //**//
//**// PUNTO 1 //**//

template<class T>
void ArbolBin<T>::listarPostOrden(){
if(raiz)
    listarPostOrdenR(raiz);
else error("No se puede imprimir un arbol vacio",EXIT_ERROR);

}

template<class T>
void ArbolBin<T>::listarPostOrdenR(Nodo<T> *p){
if(p==NULL) return;
listarPostOrdenR(p->HIzq);
listarPostOrdenR(p->HDer);
cout << p->elemento << ",";

}
//**// PUNTO 5 //**//

template<class T>
int ArbolBin<T>::cantidad(Nodo<T> *p){
    if(p == NULL){
        return 0;
    }
    else{
        return 1 + cantidad(p->HIzq) + cantidad(p->HDer);
    }
}

template<class T>
bool ArbolBin<T>::esCompleto(){
int i=0,total=cantidad(raiz);
return(esCompletoR(raiz,i,total));
}

template<class T>
bool ArbolBin<T>::esCompletoR(Nodo<T> *p, int i, int cant){
    if (p == NULL)
        return (true);

    if (i >= cant)
        return (false);

    return (esCompletoR(p->HIzq, (2*i) + 1, cant) && esCompletoR(p->HDer, (2*i) + 2, cant));
}
//template <class T>
//void ArbolBin<T>::carga_ABB(ArbolBin<T> &tree, T elemento,Nodo<T>* r){ //Sacar el tree, y el nodo debe pasar por & para que los cambios sean permanentes
//        if(*tree.raizArbol()==nullptr){ //Aca al no recibir el arblo seria *raizArbol() o AUN MEJOR como consecuencia que estas en una operación basica raiz
//            tree.asignarNodo(elemento,r); //solo asignarNodo(elemento,r)
//            Mostrar(tree);//Ojo con esto no tendria que estar aca, supongo que es para probarlo
//        } //OJO aca te falta un else... si el arbol tiene raiz me fijo donde va
//        if(elemento>tree.recuperar(r)){ //Mejor r->elemento
//            if(*tree.hijoDer(r)==nullptr){ //Mejor r->HDer
//                tree.asignarNodo(elemento,*tree.hijoDer(r));  //solo asignarNodo(elemento,r->HDer)
//            }else{
//                carga_ABB(tree,elemento,*tree.hijoDer(r)); //Mejor carga_ABB(tree,elemento, r->HDer  );
//            }
//        }else{
//        if(elemento<tree.recuperar(r)){ //Para esta parte la misma consideración que arriba solo que con r->HIzq
//            if(*tree.hijoIzq(r)==nullptr){
//                tree.asignarNodo(elemento,*tree.hijoIzq(r));
//            }else{
//                carga_ABB(tree,elemento,*tree.hijoIzq(r));
//            }
//        }
//    }
//}
