#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include "stdlib.h"
#include "string.h"
#include "iostream"
#define MAX 100

//

enum Month {JANUARY=1,FEBRUARY,MARCH,APRIL,MAY,JUNE,JULY,AUGUST,SEPTEMBER,OCTOBER,NOVEMBER,DECEMBER};

enum orden{asc,desc};

//

struct Date{
 unsigned int day;
 Month month;
 unsigned int year;
};

Date d={1,JANUARY,1970};
Date d2={7,JANUARY,1970};

// ACTV 2

char* to_str(Date d){

char *dia= (char*)malloc(sizeof(char));
dia=itoa(d.day,dia,10);
strcat(dia,"/");
char *mes= (char*)malloc(sizeof(char));
mes=itoa(d.month,mes,10);
strcat(dia,mes);
strcat(dia,"/");
char *anio= (char*)malloc(sizeof(char));
anio=itoa(d.year,anio,10);
strcat(dia,anio);


free(mes);
free(anio);

return (dia);
}

Date to_date(char *str){
Date var;
var.day = (int)(str[0]-48)*10 + (int)str[1]-48;
int m = (int)((str[3]-48)*10) + (int)(str[4]-48);
var.month= (Month)m;
var.year= (int)(str[6]-48)*1000 + (int)(str[7]-48)*100 +(int)(str[8]-48)*10 +(int)(str[9]-48);

return var;
}

bool leapYear(Date d){
return (d.year%4==0 && d.year%100!=0 || d.year%400==0);
}

bool isValidDate(Date d){

if (!leapYear(d) && d.month==2 && d.day<=28 && d.day>0 ){
    return true;
}
else if (leapYear(d) && d.month==2 && d.day<=29 && d.day>0 && d.month>0){
      return true;
}
 else if (d.month==1 || d.month==3 || d.month==5 || d.month==7 || d.month==8 || d.month==10 || d.month==12 && d.day<=31 && d.day>0 && d.month>0){
         return true;
}
  else if (d.month==4 || d.month==6 || d.month==9 || d.month==11 && d.day<=30 && d.day>0 && d.month>0){
            return true;
  }
   else return false;

}

int getDifference(Date dt1, Date dt2){

int res,d1,d2;

// d1

if(leapYear(dt1)){
 d1=dt1.year*366;}
 else if(!leapYear(dt1)){
    d1=dt1.year*365;
 }
 if(dt1.month==1 || dt1.month==3 || dt1.month==5 || dt1.month==7 || dt1.month==8 || dt1.month==10 || dt1.month==12){
  d1=d1+(dt1.month*31)+dt1.day;
}
  else if(dt1.month==4 || dt1.month==6 || dt1.month==9 || dt1.month==11){
    d1=d1+(dt1.month*30)+dt1.day;
  }
  else if(dt1.month==2){
    d1=d1+(dt1.month*28)+dt1.day;
  }

// dt2

if(leapYear(dt2)){
 d2=dt2.year*366;}
 else if(!leapYear(dt2)){
    d2=dt2.year*365;
 }
if(dt2.month==1 || dt2.month==3 || dt2.month==5 || dt2.month==7 || dt2.month==8 || dt2.month==10 || dt2.month==12){
  d2=d2+(dt2.month*31)+dt2.day;
}
 else if(dt2.month==4 || dt2.month==6 || dt2.month==9 || dt2.month==11){
    d2=d2+(dt2.month*30)+dt2.day;
  }
  else if(dt2.month==2){
    d2=d2+(dt2.month*28)+dt2.day;
  }
   else if(dt2.month==2){
    d2=d2+(dt2.month*28)+dt2.day;
  }

  return (d1-d2);

}

// ACTIV 4

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

// ACTV 1
/*
Month next(Month m){
​
    switch (m){
    case 1:
        m=FEBRUARY;
        break;
    case 2:
        m=MARCH;
        break;
    case 3:
        m=APRIL;
        break;
    case 4:
        m=MAY;
        break;
    case 5:
        m=JUNE;
        break;
    case 6:
        m=JULY;
        break;
    case 7:
        m=AUGUST;
        break;
    case 8:
        m=SEPTEMBER;
        break;
    case 9:
        m=OCTOBER;
        break;
    case 10:
        m=NOVEMBER;
        break;
    case 11:
        m=DECEMBER;
        break;
    case 12:
        m=JANUARY;
        break;
}
return m;
}
Month previous(Month m){
​
    switch (m){
    case 1:
        m=DECEMBER;
        break;
    case 2:
        m=JANUARY;
        break;
    case 3:
        m=FEBRUARY;
        break;
    case 4:
        m=MARCH;
        break;
    case 5:
        m=APRIL;
        break;
    case 6:
        m=MAY;
        break;
    case 7:
        m=JUNE;
        break;
    case 8:
        m=JULY;
        break;
    case 9:
        m=AUGUST;
        break;
    case 10:
        m=SEPTEMBER;
        break;
    case 11:
        m=OCTOBER;
        break;
    case 12:
        m=NOVEMBER;
        break;
}
return m;
}
unsigned short to_int(Month m){
return m;
}
char* to_str(Month m){
​
    switch(m){
    case 1:
        cout << "Enero";
        break;
    case 2:
        cout << "Febrero";
        break;
    case 3:
        cout << "Marzo";
        break;
    case 4:
        cout << "Abril";
        break;
    case 5:
        cout << "Mayo";
        break;
    case 6:
        cout << "Junio";
        break;
    case 7:
        cout << "Julio";
        break;
    case 8:
        cout << "Agosto";
        break;
    case 9:
        cout << "Sepiembre";
        break;
    case 10:
        cout << "Octubre";
        break;
    case 11:
        cout << "Noviembre";
        break;
    case 12:
        cout << "Diciember";
        break;
    }
return 0;
}
Month to_month(unsigned short m){
}
*/
//

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
#endif // DATE_H_INCLUDED
