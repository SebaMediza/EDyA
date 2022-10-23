#ifndef EJ_3_H_INCLUDED
#define EJ_3_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

string replaceAll(const string& str, const string& from, const string& to){

    string sub_str;
    string str_copy=str;

    string::size_type pos_inicial=str_copy.find(from);
    string::size_type pos_final=str_copy.find(to);

    sub_str=str_copy.substr(pos_inicial);
    cout<<sub_str;
return sub_str;
}

#endif // EJ_3_H_INCLUDED
