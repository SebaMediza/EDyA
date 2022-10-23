#include <iostream>
#include <stdlib.h>

using namespace std;

size_t edya_strlen(char * str);
char * edya_strcat(char * str1, char * str2);
char * edya_strcpy(char * destination, char * source);
char * edya_itoa(unsigned int value, char * str, int base);


int main()
{
    int resultado=0,n,valor,base;
    char * str;
    char * str_2;
    char * str_3;
    char *cadena_concatenada;
    char *cadena_copiada;
    char *cadena_numerica;

    str=(char*)malloc(n*sizeof(char));
    str_2=(char*)malloc(n*sizeof(char));

    cout << "Ingrese una Cadena de Texto: ";
    cin >> str;

    resultado=edya_strlen(str);

    cout << "El Largo de la Cadena es: " << resultado << endl;

    cout << "Ingrese otra cadena para Conactenar: ";
    cin >> str_2;

    cadena_concatenada=edya_strcat(str,str_2);

    cout << *cadena_concatenada;

    cadena_copiada=edya_strcpy(str,str_2);
    cout << cadena_copiada;

    cout << "Ingrese el valor que desea convertir: ";
    cin >> valor;
    cout << "Ingrese la base a la que desea convertir(2,8,10,16): ";
    cin >> base;
    cadena_numerica=edya_itoa(valor,str_3,base);
    cout << cadena_numerica;

return 0;
}

size_t edya_strlen(char * str){

    int i;
    int cont=0;
    for(i=0;str[i]!=NULL;i++){
        cont++;
    }

return cont;
}

char * edya_strcat(char * str1, char * str2){
    char *chain=(char*)malloc(sizeof(unsigned int));

    *chain=*str1;

    int i;
    int cont=0;
    for(i=0;str2[i]!=NULL;i++){
        cont++;
    }

    for(int j=0;j==cont;j++){
//        chain=chain+"";
    }
    *chain=+ *str2;

return chain;
}

char * edya_strcpy(char * destination, char * source){

    destination=(char*)malloc(sizeof(source));

    destination=source;

return destination;
}

char * edya_itoa(unsigned int value, char * str, int base){

    if(base==2){
        char test;
        while (value != 0){
        //test += ( value % 2 == 0 ? "0" : "1" );
        value /= 2;
    }
    }else{
    if(base==8){
        int remainder;
        long octal = 0, i = 1;

        while(value != 0) {
            remainder = value%8;
            value = value/8;
            octal = octal + (remainder*i);
            i = i*10;
        }
        str=(char*)octal;
        return str;

    }
}
return 0;
}
