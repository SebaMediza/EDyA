#ifndef EJ_1_H_INCLUDED
#define EJ_1_H_INCLUDED

#include <iostream>
#include <stdlib.h>

using namespace std;

size_t edya_strlen(char * str);
char * edya_strcat(char * str1, char * str2);
char * edya_strcpy(char * destination, char * source);
char * edya_itoa(unsigned int value, char * str, int base);

size_t edya_strlen(char * str){

    int i;
    int cont=0;
    for(i=0;str[i]!=NULL;i++){
        cont++;
    }

return cont;
}

char * edya_strcat(char * str1, char * str2){
/*
    int cont=0;
    for(int i=0;str1[i]!=NULL;i++){
        cont++;
    }
    for(int h=0;str2[h]!=NULL;h++){
        cont++;
    }
    char *chain=(char*)malloc(sizeof(cont));
    chain=(str1) + (str2);
*/
    cout << "\n";
    cout << str1 << str2 << endl << "\n";
return 0;
}

char * edya_strcpy(char * destination, char * source){

    destination=(char*)malloc(sizeof(source));

    destination=source;

return destination;
}

char * edya_itoa(unsigned int value, char * str, int base){
char* str2;
int i=0,k=0,j=0,n,z;


if (base==2){
 while (value!=0){
 str[i]=(value%2) + '0';
 i++;
 value=value/2;
 }

str[i]=NULL;

}

if (base==8){
while(value!=0){
str[i]=(value%8) + '0';
i++;
value=value/8;
}
str[i]=NULL;
}


if (base==16){
while(value!=0){
if(value%16==10){
    str[i]= 'A';
}
if(value%16==11){
    str[i]= 'B';
}
if(value%16==12){
    str[i]= 'C';
}
if(value%16==13){
    str[i]= 'C';
}
if(value%16==14){
    str[i]= 'D';
}
if(value%16==15){
    str[i]= 'E';
}
if(value%16==16){
    str[i]= 'F';
}
if((value%16)!=10 && (value%16)!=11 && (value%16)!=12 && (value%16)!=13 && (value%16)!=14 && (value%16)!=15 && (value%16)!=16){
 str[i]=(value%16) + '0';
}
i++;
value=value/16;
}
str[i]=NULL;
}

if (base==10){
while(value!=0){
str[i]=value%10 + '0';
i++;
value=value/10;
}
str[i]=NULL;
}

str2=(char*)malloc((n*sizeof(char)));
edya_strcpy(str,str2);

for(z=0;str[z]!=NULL;z++){
    j++;
}
j--;
do{
    str[k]=str2[j];
    k++;
    j--;
}while (str2[j]!=NULL && j>=0);

return (str);

}
#endif // EJ_1_H_INCLUDED
