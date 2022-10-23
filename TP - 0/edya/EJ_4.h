#ifndef EJ_4_H_INCLUDED
#define EJ_4_H_INCLUDED

#include <iostream>

using namespace std;

size_t edya_ptr_strlen(char * str);

size_t edya_ptr_strlen(char * str){
    int cont=0;

    if(str==NULL){
        return 0;
    }

    do{
        str++;
        cont++;
    }while(*str!=NULL);
return cont;
}

#endif // EJ_4_H_INCLUDED
