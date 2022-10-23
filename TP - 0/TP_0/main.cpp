#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){

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
return 0;
}
