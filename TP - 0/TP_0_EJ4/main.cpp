#include <iostream>

using namespace std;

size_t edya_ptr_strlen(char * str);

int main(){
    int n;
    char *chain=(char*)malloc(n*sizeof(char));

    cout << "Cadena: ";
    cin >> chain;

    cout << edya_ptr_strlen(chain);

    return 0;
}

size_t edya_ptr_strlen(char * str){
    int cont=0;
    do{
        str++;
        cont++;
    }while(*str!=NULL);
return cont;
}
