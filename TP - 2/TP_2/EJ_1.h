#ifndef EJ_1_H_INCLUDED
#define EJ_1_H_INCLUDED

#include<string>
#include <iostream>

using namespace std;

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
#endif // EJ_1_H_INCLUDED
