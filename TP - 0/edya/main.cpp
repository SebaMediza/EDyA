#include <iostream>
#include "EJ_1.h"
#include "EJ_2.h"
#include "EJ_4.h"
#include "EJ_5.h"
using namespace std;

int main(){

    int seleccion=0;

do{

    cout << "Ingrese el numero de ejercicio\n-1\n-2\n-3(INCOMPLETO)\n-4\n-5\n-6(Salir) " << endl << "\nOperacion: ";
    cin >> seleccion;

    switch(seleccion){

        case 1:
{
    int resultado=0,n=1,valor,base;
    char * str;
    char * str_2;
    char * str_3;
    char *cadena_concatenada;
    char *cadena_copiada;
    char *cadena_numerica;

    str=(char*)malloc(n*sizeof(char));
    str_2=(char*)malloc(n*sizeof(char));
    str_3=(char*)malloc(n*sizeof(char));

    int eleccion=0;
    do{
    cout << "Elija una opcion:\n1-Medir una cadena\n2-Unir dos cadenas\n3-Reemplazar el contenido de una cadena con la otra\n4-Convertir numeros\n5-Volver" << endl << "Operacion: ";
    cin >> eleccion;
    cout << endl;
    switch(eleccion){
            case 1:
{
    cout << "Ingrese una Cadena de Texto: ";
    cin >> str;

    resultado=edya_strlen(str);

    cout << "El Largo de la Cadena es: " << resultado << endl << "\n";
    break;
}
            case 2:
{
    cout << "Ingrese una cadena para Conactenar: ";
    cin >> str;
    cout << "Ingrese otra cadena para comcatenar: ";
    cin >> str_2;

    cadena_concatenada=edya_strcat(str,str_2);
    break;
}
            case 3:
{
    cout << "Ingrese la informacion de destino: ";
    cin >> str;
    cout << "Ingrese la informacion de origen: ";
    cin >> str_2;
    cadena_copiada=edya_strcpy(str,str_2);
    cout << cadena_copiada << endl;
    break;
}
            case 4:
{
    cout << "Ingrese el valor que desea convertir: ";
    cin >> valor;
    cout << "Ingrese la base a la que desea convertir(2,8,10,16): ";
    cin >> base;
    cadena_numerica=edya_itoa(valor,str_3,base);
    cout << cadena_numerica << endl;
    break;
}
}
    }while(eleccion!=5);
     break;
}
        case 2:
{
    bool check_year;
    bool check_date;
    int check_datecmp,eleccion=0;

    do{
    cout << "Elija una opcion:\n1-Verificar si un año es bisiesto\n2-Verificar si una fecha es bisiesta\n3-Comparar dos fechas\n4-Calular cuantos dias pasaron del año nuevo\n5-Volver" << endl << "Opcion: ";
    cin >> eleccion;
    switch(eleccion){
        case 1:
{
    cout<<"Ingrese el Año: ";
  cin >> date.Year;
  check_year=leapYear(date.Year);
    if(check_year==true){
        cout << "El Año es Bisiesto";
    }else{
        cout << "El Año NO es Bisiesto";
    }
    cout << endl;
break;
}
        case 2:
{
    cout<<"Ingrese el Año: ";
  cin >> date.Year;
     cout<<"Ingrese el Mes: ";
  cin >> date.Month;
    cout<<"Ingrese el Día: ";
  cin >> date.Day;
  check_date=leapYear(date);
    if(check_date==true){
        cout << "La Fecha Pertenece a un Año Bisiesto" << endl;
    }else{
        cout << "La Fecha NO Pertenece a un Año Bisiesto" << endl;
    }
break;
}
        case 3:
{
    cout << "Ingrese la primera fecha (AAAA/MM/DD): " << endl;
      cout<<"Ingrese el Año: ";
  cin >> date.Year;
     cout<<"Ingrese el Mes: ";
  cin >> date.Month;
    cout<<"Ingrese el Día: ";
  cin >> date.Day;
  cout << "Ingrese la segunda fecha (AAAA/MM/DD): " << endl;
    cout<<"Ingrese el Año: ";
  cin >> date_1.Year_1;
    cout<<"Ingrese el Mes: ";
  cin >> date_1.Month_1;
    cout<<"Ingrese el Día: ";
  cin >> date_1.Day_1;

  cout << "\nReferencias:\n<0 la fecha 1 es menor que la fecha 2\n0 la fecha 1 es igual que la fecha 2\n>0 la fecha 1 es mayor que la fecha 2\n" << endl;

    check_datecmp=datecmp(date, date_1);
    cout<< "\nEl resultado de la compracion es: " << check_datecmp << endl;
    break;
}
        case 4:
{
    cout << "Dia: ";
    cin >> date.Day;
    cout << "Mes: ";
    cin >> date.Month;
    cout << "La cantidad de dias transcurridos es: " << dayOfYear(date) << endl;
break;
}

    }
    }while(eleccion!=5);
    break;
}
        case 3:
{
        //test_pointer();
break;
}
        case 4:
{
    int n=1;
    char *chain=(char*)malloc(n*sizeof(char));

    cout << "Cadena: ";
    cin >> chain;

    cout << edya_ptr_strlen(chain) << endl;
            break;
}
        case 5:
{
        int ROWS = 3, COLS = 4;
    int num[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int j=0;

    int *ptr = &num[0][0];

    for(int i=0;i<12;i++){
    cout << *ptr;
    cout << ", ";
    ptr++;
    j++;
    if(j==4){
        cout << endl;
        j=0;
    }
}
break;
}
};
}while (seleccion!=6);
return 0;
}
