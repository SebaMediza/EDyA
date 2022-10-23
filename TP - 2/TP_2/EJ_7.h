#ifndef EJ_7_H_INCLUDED
#define EJ_7_H_INCLUDED
#include <queue>
#include<iostream>

using namespace std;

void print(std::queue<int> &myqueue){

while(!myqueue.empty()){
    cout<<myqueue.front()<<"; ";
    myqueue.pop();
}
}
#endif // EJ_7_H_INCLUDED
