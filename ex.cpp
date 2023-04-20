//
// Created by Octavian Farcasi on 18.04.2023.
//
#include<iostream>
#include<string>
#include<vector>
int main(){
    std::string s,d;
    s="ana are mere\n";
    std::cout<<s<<s[5];

    std::string *p=&s;


    d=s;
    s[1]='v';
    std::cout<<s<<" "<<d<<'\n';

    std::cout<<p<<" "<<*p<<" ";

    std::cout<<"hello\n";


    std::vector<std::string>v;
    v.push_back("ana");
    v.push_back("as");
    v.push_back("mere");
    for(int i=0;i<int(v.size());i++)
        std::cout<<v[i]<<" ";

    return 0;
}