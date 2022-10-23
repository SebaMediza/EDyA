#ifndef EJ_5_H_INCLUDED
#define EJ_5_H_INCLUDED

#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<ctime>

enum format{FMT_LINE,FMT_LIST};

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
    unsigned int tamano=v1.size()+v2.size();
    v1.resize(tamano);

    for(unsigned int i=0;i<tamano;i++){
        cout<<v1.at(i)<<"; ";
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

#endif // EJ_5_H_INCLUDED
