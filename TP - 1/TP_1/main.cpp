#include <iostream>
#include "date.h"
#include "edya_array.h"
#include "word.h"
#include "P_3.h"
#include "P_4.h"

using namespace std;

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-TRABAJO_PRACTICO_1--GRUPO_005-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//

int main()
{
    int ejercicio=0;
    do{
    ejercicio=0;
    cout<<"Ingrese el numero de ejercicio 1-6; 7(Salir): ";
    cin>>ejercicio;

    switch(ejercicio){
    case 1:{
        char control;
        Month mes;

        cout<<"Ingrese el numero del mes: ";
        cin>>control;

        mes=(Month)((control-48)%12);

        cout<<"El siguiente mes es: "<<(int)(Month)next(mes)<<endl;

        cout<<"El nombre del mes es: "<<to_str(mes)<<endl;

        cout<<"El numero de mes es: "<<to_int(mes)<<endl;
    break;
}
    case 2:{
        cout << to_str(d) << endl;

        char *s={"01/01/2021"};

        struct Date fecha=to_date(s);

        cout << fecha.day << "/" << fecha.month << "/" << fecha.year << endl;

        cout << getDifference(d,d2);
    break;
}
    case 3:{
        parlabra();
        cout<<endl<<endl;
    break;
}
    case 4:
    break;
    case 5:{
        cout<<endl<<"En formarto Markdown"<<endl<<endl;
    break;
}
    case 6:{
        size_t n=3;
        size_t new_n=8;
        EArray ea1=createArray(n);
        resize(ea1,new_n);
        show(ea1);

    break;
}
    }
    }while(ejercicio!=7);
return 0;
}
