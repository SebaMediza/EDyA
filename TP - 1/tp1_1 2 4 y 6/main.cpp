#include <iostream>

using namespace std;
#include "date.h"
#include "edya_array.h"

int main()
{

// llamadas a actv 1

char control;
Month mes;
​
cout<<"Ingrese el numero del mes: ";
cin>>control;
​
mes=(Month)((control-48)%12);
​
cout<<"El siguiente mes es: "<<(int)(Month)next(mes)<<endl;
​
cout<<"El nombre del mes es: "<<to_str(mes)<<endl;
​
cout<<"El numero de mes es: "<<to_int(mes)<<endl;



// llamadas a actv 2

//cout << to_str(d) << endl;
//
//char *s={"01/01/2021"};
//
//struct Date fecha=to_date(s);
//
//cout << fecha.day << "/" << fecha.month << "/" << fecha.year << endl;

//cout << getDifference(d,d2);


// llamadas a actv 6


//size_t n=3;
//size_t new_n=8;
//
//EArray ea1=createArray(n);
//resize(ea1,new_n);
//show(ea1);

}
