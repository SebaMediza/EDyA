#ifndef P_2_H_INCLUDED
#define P_2_H_INCLUDED
#include "stdlib.h"
#include "string.h"
#include "iostream"
#define MAX 100

char* to_str(Date d);
Date to_date(char *str);
bool leapYear(Date d);
bool isValidDate(Date d);
int getDifference(Date dt1, Date dt2);



/*
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
*/
#endif // P_2_H_INCLUDED
