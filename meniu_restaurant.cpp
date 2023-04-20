//
// Created by Octavian Farcasi on 19.04.2023.
//
#include"meniu_restaurant.h"
Meniu::Meniu()=default;

void Meniu::afis() {
    std::cout<<"Aperitiv: ";
    for(std::map<std::string,float>::iterator i=aperitiv.begin();i!=aperitiv.end();i++)
        std::cout<<i->first<<" "<<i->second<<" RON ";
    std::cout<<"\n";
    std::cout<<"Fel 1: ";
    for(std::map<std::string,float>::iterator i=fel1.begin();i!=fel1.end();i++)
        std::cout<<i->first<<" "<<i->second<<" RON ";
    std::cout<<"\n";
    std::cout<<"Fel 2: ";
    for(std::map<std::string,float>::iterator i=fel2.begin();i!=fel2.end();i++)
        std::cout<<i->first<<" "<<i->second<<" RON ";
    std::cout<<"\n";
    std::cout<<"Desert: ";
    for(std::map<std::string,float>::iterator i=desert.begin();i!=desert.end();i++)
        std::cout<<i->first<<" "<<i->second<<" RON ";
    std::cout<<"\n";
    std::cout<<"Bauturi: ";
    for(std::map<std::string,float>::iterator i=bauturi.begin();i!=bauturi.end();i++)
        std::cout<<i->first<<" "<<i->second<<" RON ";
}

bool Meniu::find(const std::string &mancare, std::map<std::string, float> dictionar) {
    auto i=dictionar.begin();
    while(i!=dictionar.end()){
        if(i->first==mancare)
            return true;
        i++;
    }
    return false;
}

std::map<std::string, float> *Meniu::lista_aperitiv(Meniu &ob) {
    return &ob.aperitiv;
}

std::map<std::string, float> *Meniu::lista_fel1(Meniu &ob) {
    return &ob.fel1;
}

std::map<std::string, float> *Meniu::lista_fel2(Meniu &ob) {
    return &ob.fel2;
}

std::map<std::string, float> *Meniu::lista_desert(Meniu &ob) {
    return &ob.desert;
}

std::map<std::string, float> *Meniu::lista_bauturi(Meniu &ob) {
    return &ob.bauturi;
}

Meniu::~Meniu()=default;



//int main(){
//    Meniu ob;
//    ob.updateMeniu();
//    ob.afis();
//
//    return 0;
//}