/**
    ArbolBinViewer.h
    @author Daniel Pérez
    @version 1.1 12/05/16
*/

#ifndef ARBOLBINVIEWER_H
#define ARBOLBINVIEWER_H

#include <iostream>
#include <map>
#include <list>
#include <sstream>
#include <string>
#include <fstream>
#include <stdint.h>
#ifdef _WIN32//http://nadeausoftware.com/articles/2012/01/c_c_tip_how_use_compiler_predefined_macros_detect_operating_system
#include <windows.h>
#endif


using namespace std;

template <class T>
inline std::string to_string (const T& t){
    std::stringstream ss;
    ss << t;
    return ss.str();
}

template <class T>
class ArbolBinViewer
{
    public:
        ArbolBinViewer(ArbolBin<T> *arbol){
            this->plantilla = "template/template.html";
            this->salida = "salida.html";
            this->arbol = arbol;
        }
        virtual ~ArbolBinViewer() {
            this->arbol = NULL;
        }
        void setSalida(const string &salida){
            this->salida = salida;
        }

        void view(){
            std::map<uintptr_t,T> mymap;
            std::list<string> edgesList;

            std::stringstream nodes;
            std::stringstream edges;

            Nodo<T>* *R=arbol->raizArbol();
            this->construir(this->arbol, *R, mymap, edgesList);

            for (typename std::map<uintptr_t,T>::iterator it =mymap.begin(); it!=mymap.end(); ++it)
                nodes <<endl<< "{id: "<< it->first << ", label: '"<<it->second<<" '},";

            for (std::list<string>::iterator it=edgesList.begin(); it != edgesList.end(); ++it)
                edges << endl << *it;

            ifstream t(this->plantilla.c_str());
            string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
            t.close();

            string var_nodes("{{nodes}}");
            string var_edges("{{edges}}");
            str.replace(str.find(var_nodes),var_nodes.length(),nodes.str());
            str.replace(str.find(var_edges),var_edges.length(),edges.str());

            ofstream out(this->salida.c_str());
            out << str;
            out.close();

            #ifdef _WIN32
            ShellExecute(NULL, "open", this->salida.c_str(), NULL, NULL, SW_SHOWNORMAL);
            #endif
            #ifdef __linux__
            system(("x-www-browser " + this->salida+ " &").c_str());
            #endif
        }
    protected:
    private:
        ArbolBin<T> *arbol;
        string plantilla;
        string salida;

        string to_str(Nodo<T> *n){
            uintptr_t addr = reinterpret_cast<uintptr_t>(n);
            return to_string(addr);
        }


        void construir(ArbolBin<T> *a, Nodo<T>*n, std::map<uintptr_t, T> &m, std::list<string> &l){
            if(n!=NULL){
                Nodo<T>* i = *a->hijoIzq(n);
                Nodo<T>* d = *a->hijoDer(n);
                if(i!=NULL)
                    l.push_back("{from: "+to_str(n)+", to: "+to_str(i)+",arrows:'to', label: 'hi' },");
                if(d!=NULL)
                    l.push_back("{from: "+to_str(n)+", to: "+to_str(d)+",arrows:'to', label: 'hd' },");

                construir(a, i,m,l);
                construir(a, d,m,l);

                m[uintptr_t(n)]=a->recuperar(n);
            }
        }
};

#endif // ARBOLBINVIEWER_H
