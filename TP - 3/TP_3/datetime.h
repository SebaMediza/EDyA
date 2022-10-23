#ifndef DATETIME_H_INCLUDED
#define DATETIME_H_INCLUDED

#define ANIO 31556926
#define MES 2629743
#define DIA 86400
#define HORA 3600
#define MINUTO 60

using namespace std;

class DateTime{
public:
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*ESTRUCTURA_INICIALIZADA_POR_FECHA_Y_HORA_DEL_SISTEMA*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
DateTime(){
    time_t t=time(NULL);
    struct tm today=*localtime(&t);
    this->day=today.tm_mday;
    this->month=today.tm_mon+1;
    this->year=(today.tm_year+1900);
    this->hour=today.tm_hour;
    this->minute=today.tm_min;
    t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    cout<<put_time(&tm,"%d/%m/%Y %H:%M");
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*ESTRUCTURA_INICIALIZADA_POR_PARAMETROS_DE_FUNCION*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
DateTime datetime(string dia, string mes, string anio, string hora, string minuto){
    this->day=dia;
    this->month=mes;
    this->year=anio;
    this->hour=hora;
    this->minute=minuto;
return *this;
}
DateTime datetime_CMP(string dia, string mes, string anio, string hora, string minuto){
    this->day_cmp=dia;
    this->month_cmp=mes;
    this->year_cmp=anio;
    this->hour_cmp=hora;
    this->minute_cmp=minuto;
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
void setHour(string hora){
    this->hour=hora;
}
void setMinutes(string minuto){
    this->minute=minuto;
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
void setHour_CMP(string hora){
    this->hour_cmp=hora;
}
void setMinutes_CMP(string minuto){
    this->minute_cmp=minuto;
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
string getHour(){
   return this->hour;
}
string getMinutes(){
   return this->minute;
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*OPERADORES_SOBRECARGADOS*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
friend istream& operator>>(istream &in, DateTime &dt){
    in>>dt.day;
    in>>dt.month;
    in>>dt.year;
    in>>dt.hour;
    in>>dt.month;
return in;
}
friend ostream& operator<<(ostream &o, const DateTime &dt){
    o<<dt.day;
    cout<<"/";
    o<<dt.month;
    cout<<"/";
    o<<dt.year;
    cout<<" ";
    o<<dt.hour;
    cout<<":";
    o<<dt.minute;
return o;
}
bool operator==(DateTime &dt){
    return this->day==dt.day_cmp && this->month==dt.month_cmp && this->year==dt.year_cmp && this->hour==dt.hour_cmp && this->minute==dt.minute_cmp;
}
bool operator!=(DateTime &dt){
    return !(this->day==dt.day_cmp && this->month==dt.month_cmp && this->year==dt.year_cmp && this->hour==dt.hour_cmp && this->minute==dt.minute_cmp);
}
bool operator<(DateTime &dt){
    return this->day<dt.day_cmp || this->month<dt.month_cmp || this->year<dt.year_cmp || this->hour<dt.hour_cmp || this->minute<dt.minute_cmp;
}
bool operator>(DateTime &dt){
    return this->day>dt.day_cmp || this->month>dt.month_cmp || this->year>dt.year_cmp || this->hour>dt.hour_cmp || this->minute>dt.minute_cmp;
}
bool operator>=(DateTime &dt){
    return this->day>=dt.day_cmp || this->month>=dt.month_cmp || this->year>=dt.year_cmp || this->hour>=dt.hour_cmp || this->minute>=dt.minute_cmp;
}
bool operator<=(DateTime &dt){
    return this->day<=dt.day_cmp || this->month<=dt.month_cmp || this->year<=dt.year_cmp || this->hour<=dt.hour_cmp || this->minute<=dt.minute_cmp;
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//
unsigned long timestamp(){
    time_t now=time(0);
    this->unix_time=now;
return this->unix_time;
}
private:
    string day,month,year,hour,minute;
    string day_cmp,month_cmp,year_cmp,hour_cmp,minute_cmp;
    unsigned long unix_time;
};
#endif // DATETIME_H_INCLUDED
