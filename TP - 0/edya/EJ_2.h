#ifndef EJ_2_H_INCLUDED
#define EJ_2_H_INCLUDED

#include <iostream>
using namespace std;

struct Date{
    unsigned int Year, Month, Day;
}date;
struct Date_1{
    unsigned int Year_1, Month_1, Day_1;
}date_1;

bool leapYear(unsigned int y);
bool leapYear(Date d);
int datecmp(Date d1, Date_1 d2);
unsigned int dayOfYear(Date d);

bool leapYear(unsigned int y){
    if((y%4 == 0 and y%100 != 0) or (y%400 == 0)) //Condición de año bisiesto
        return true;
   else
        return false;
}

bool leapYear(Date d){
    if((d.Year%4 == 0 and d.Year%100 != 0) or (d.Year%400 == 0)) //Condición de año bisiesto
        return true;
   else
        return false;
}

int datecmp(Date d1, Date_1 d2){

    int day_control=0,month_control=0,year_control=0;

    if(d1.Year>d2.Year_1){
        return 1;
    }else{
        year_control=1;
    }

    if(d1.Month>d2.Month_1){
        return 1;
    }else{
        month_control=1;
    }

    if(d1.Day>d2.Day_1){
        return 1;
    }else{
        if(d1.Day<d2.Day_1){
        day_control=1;
        }
    }

    if(year_control==1 && month_control==1 && day_control==1){
        return -1;
    }

    if(d1.Year==d2.Year_1 && d1.Month==d2.Month_1 && d1.Day==d2.Day_1){
        return 0;
    }
return 0;
}

unsigned int dayOfYear(Date d){

 int time;

 time = (((d.Month-1)*30)+d.Day);

return time;
}


#endif // EJ_2_H_INCLUDED
