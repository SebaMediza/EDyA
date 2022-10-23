#include <iostream>
#include "pila_a.h"
#include <vector>


#define Pila PilaA
using namespace std;

int main(){
   Pila<int,5> batery;
   unsigned int num,cont=6;
   Pila<int,5> batery_1;
   cout<<"Pila this:"<<endl;
   do{
    cin>>num;
    batery.apilar(num);
    cont--;
   }while(cont!=3);
//   cout<<"Cuantos elementos desea desapilar? ";
//   cin>>num;
   cout<<"Pila Por Parametro: "<<endl;
   do{
    cin>>num;
    batery_1.apilar(num);
    cont--;
   }while(cont!=0);
    batery.swap(batery_1);


    return 0;
}
