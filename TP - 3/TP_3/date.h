#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

using namespace std;

#include<string>
#include<time.h>
#include <iomanip>
#include <ctime>


class Date{
public:
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*ESTRUCTURA_INICIALIZADA_POR_FECHA_DEL_SISTEMA*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
Date(){
    time_t t=time(NULL);
    struct tm today=*localtime(&t);
    this->day=today.tm_mday;
    this->month=today.tm_mon+1;
    this->year=(today.tm_year+1900);
    t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    //cout<<put_time(&tm,"%d/%m/%Y")<<endl;
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*ESTRUCTURA_INICIALIZADA_POR_PARAMETROS_DE_FUNCION*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
Date date(string dia, string mes, string anio){
    this->day=dia;
    this->month=mes;
    this->year=anio;
return *this;
}
Date date_CMP(string dia, string mes, string anio){
    this->day_cmp=dia;
    this->month_cmp=mes;
    this->year_cmp=anio;
return *this;
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*METODOS_SET*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
void setDay(string dia){
    this->day=dia;
}
void setMonth(string mes){
    this->month=mes;
}
void setYear(string anio){
    this->year=anio;
}
void setDay_CMP(string dia){
    this->day_cmp=dia;
}
void setMonth_CMP(string mes){
    this->month_cmp=mes;
}
void setYear_CMP(string anio){
    this->year_cmp=anio;
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*METODOS_GET*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
string getDay(){
    return this->day;
}
string getMonth(){
    return this->month;
}
string getYear(){
    return this->year;
}
string getDay_CMP(){
    return this->day_cmp;
}
string getMonth_CMP(){
    return this->month_cmp;
}
string getYear_CMP(){
    return this->year_cmp;
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*OPERADORES_SOBRECARGADOS*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
friend ostream& operator<<(ostream &o, const Date &d){
    o<<d.day;
    cout<<"/";
    o<<d.month;
    cout<<"/";
    o<<d.year;
return o;
}
friend istream& operator>>(istream &in, Date &d){
    in>>d.day;
    in>>d.month;
    in>>d.year;
return in;
}
bool operator==(const Date &d){
    return this->day==d.day_cmp && this->month==d.month_cmp && this->year==d.year_cmp;
}
bool operator!=(const Date &d){
    return !(this->day==d.day_cmp || this->month==d.month_cmp || this->year==d.year_cmp);
}
bool operator<(const Date &d){
    return this->day<d.day_cmp || this->month<d.month_cmp || this->year<d.year_cmp;
}
bool operator>(const Date &d){
    return !(this->day>d.day_cmp || this->month>d.month_cmp || this->year>d.year_cmp);
}
bool operator>=(Date &d){
    return this->day>=d.day_cmp || this->month>=d.month_cmp || this->year>=d.year_cmp;
}
bool operator<=(Date &d){
    return this->day<=d.day_cmp || this->month<=d.month_cmp || this->year<=d.year_cmp;
}
private:
    string day,month,year;
    string day_cmp,month_cmp,year_cmp;
};
#endif // DATE_H_INCLUDED
