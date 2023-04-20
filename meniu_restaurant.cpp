//
// Created by Octavian Farcasi on 19.04.2023.
//
#include"meniu_restaurant.h"
Meniu::Meniu()=default;

void Meniu::afis() {
    std::cout<<"Aperitiv: ";
    for(std::map<std::string,float>::iterator i=aperitiv.begin();i!=aperitiv.end();i++)
        std::cout<<i->first<<" "<<i->second<<" ";
    std::cout<<"\n";
    std::cout<<"Fel 1: ";
    for(std::map<std::string,float>::iterator i=fel1.begin();i!=fel1.end();i++)
        std::cout<<i->first<<" "<<i->second<<" ";
    std::cout<<"\n";
    std::cout<<"Fel 2: ";
    for(std::map<std::string,float>::iterator i=fel2.begin();i!=fel2.end();i++)
        std::cout<<i->first<<" "<<i->second<<" ";
    std::cout<<"\n";
    std::cout<<"Desert: ";
    for(std::map<std::string,float>::iterator i=desert.begin();i!=desert.end();i++)
        std::cout<<i->first<<" "<<i->second<<" ";
    std::cout<<"\n";
    std::cout<<"Bauturi: ";
    for(std::map<std::string,float>::iterator i=bauturi.begin();i!=bauturi.end();i++)
        std::cout<<i->first<<" "<<i->second<<" ";
}

void Meniu::updateMeniu() {
    std::string mancare;
    float pret;
    std::ifstream f("input.txt");

    f>>mancare;
    while(mancare!="."){
        f>>pret;
        aperitiv[mancare]=pret;
        f>>mancare;
    }
    mancare="";
    f>>mancare;
    while(mancare!="."){
        f>>pret;
        fel1[mancare]=pret;
        f>>mancare;
    }
    mancare="";
    f>>mancare;
    while(mancare!="."){
        f>>pret;
        fel2[mancare]=pret;
        f>>mancare;
    }
    mancare="";
    f>>mancare;
    while(mancare!="."){
        f>>pret;
        desert[mancare]=pret;
        f>>mancare;
    }
    mancare="";
    f>>mancare;
    while(mancare!="."){
        f>>pret;
        bauturi[mancare]=pret;
        f>>mancare;
    }
    f.close();
}

bool Meniu::find(std::string mancare, std::map<std::string, float> dictionar) {
    auto i=dictionar.begin();
    while(i!=dictionar.end()){
        if(i->first==mancare)
            return true;
        i++;
    }
    return false;
}

std::map<std::string, float> *Meniu::lista_aperitiv() {
    return &aperitiv;
}

std::map<std::string, float> *Meniu::lista_fel1() {
    return &fel1;
}

std::map<std::string, float> *Meniu::lista_fel2() {
    return &fel2;
}

std::map<std::string, float> *Meniu::lista_desert() {
    return &desert;
}

std::map<std::string, float> *Meniu::lista_bauturi() {
    return &bauturi;
}

Meniu::~Meniu()=default;



int main(){
    Meniu ob;
    ob.updateMeniu();
    ob.afis();

    return 0;
}