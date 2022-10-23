#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include "stdlib.h"
#include "string.h"
#include "iostream"
#define MAX 100

enum Month {JANUARY=1, FEBRUARY=2, MARCH=3, APRIL=4, MAY=5, JUNE=6, JULY=7, AUGUST=8, SEPTEMBER=9, OCTOBER=10, NOVEMBER=11, DECEMBER=12};

enum orden{asc,desc};

using namespace std;

struct Date{
 unsigned int day;
 Month month;
 unsigned int year;
};

Date d={1,JANUARY,1970};
Date d2={7,JANUARY,1970};

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-EJERCICIO_1-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
Month next(Month m){

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

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-EJERCICIO_2-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//

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
#endif // DATE_H_INCLUDED
