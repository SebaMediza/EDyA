#ifndef WORD_H_INCLUDED
#define WORD_H_INCLUDED

#include <iostream>

using namespace std;

union word{
    unsigned int data;
        struct{
            unsigned char b0;
            unsigned char b1;
            unsigned char b2;
            unsigned char b3;
        };
};

void parlabra();

void parlabra(){
word w = {0xA0B1C2D3};
cout << endl << "word: "<< hex << w.data;
w.b0 = 0xD3;
w.b1 = 0xC2;
w.b2 = 0xB1;
w.b3 = 0xA1;
cout << endl << "b0: "<< hex << int(w.b0);
cout << endl << "b1: "<< hex << int(w.b1);
cout << endl << "b2: "<< hex << int(w.b2);
cout << endl << "b3: "<< hex << int(w.b3);

cout << endl << "word: "<< hex << w.data;
}
#endif // WORD_H_INCLUDED
