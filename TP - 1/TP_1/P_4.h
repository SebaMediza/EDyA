#ifndef P_4_H_INCLUDED
#define P_4_H_INCLUDED
#include "stdlib.h"
#include "string.h"
#include "iostream"
#define MAX 100

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-EJERCICIO_4-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//

void ordenar( int *p , Date *d, int j){

    int var;
    Date aux;

    var = p[j];
    p[j] = p[j+1];
    p[j+1] = var;

    aux = d[j];
    d[j] =d[j+1];
    d[j+1] = aux;
}

void sort(Date *dates, size_t N, orden o){

    int i, j, vec[MAX], *p, mes;
    dates = (Date*)malloc(N*sizeof(Date));
    p = vec;

    for( i=0 ; i<N ; i++ ){
        cout << "Ingrese la fecha (XX XX XXXX) " << i << ": ";
        do{
            cin >> dates[i].day;
            cin >> mes;
            cin >> dates[i].year;
        }while( dates[i].day>1 || dates[i].day>31 || mes>1 || mes<12 || dates[i].year>0 );
        dates[i].month = (Month)mes;
        p[i] = (int)dates[i].day + (int)dates[i].month*30 + (int)dates[i].year*365;
    }

    for( i=0 ; i<N ; i++ ){
        for( j=0 ; j<N-1 ; j++ ){
            if( p[j] < p[j+1] && o == desc) ordenar(p,dates,j);
            if( p[j] > p[j+1] && o == asc ) ordenar(p,dates,j);
        }
    }

    for(i=0;i<N;i++){
        cout << dates[i].day << " " << dates[i].month << " " << dates[i].year << endl;
    }

    free(dates);
}

char * edya_strcpy(char * destination, char * source){

int i,a,tope=sizeof(destination);

for(i=0;source[i]!=NULL;i++){
 if(tope!=i)
 destination[i]=source[i];
 else break;
}

destination[i]=NULL;

return (destination);

}


#endif // P_4_H_INCLUDED
