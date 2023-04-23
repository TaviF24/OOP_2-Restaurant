//
// Created by Octavian Farcasi on 18.04.2023.
//
//
// Created by Octavian Farcasi on 18.04.2023.
//
#include "bucatari.h"
#include<iostream>

Bucatar::Bucatar(std::string &nume, int varsta, int numarul_meselor_facute):
        Angajat(nume,varsta), numarul_meselor_facute(numarul_meselor_facute) {id=++id_bucatar; }

Bucatar::Bucatar(const Bucatar &ob): Angajat(ob),numarul_meselor_facute(ob.numarul_meselor_facute) {id=++id_bucatar; }

Bucatar &Bucatar::operator=(const Bucatar &ob){
    numarul_meselor_facute=ob.numarul_meselor_facute;
    agenda=ob.agenda;
    return *this;
}

int Bucatar::getNumarulMeselor() const {
    return numarul_meselor_facute;
}

void Bucatar::incrementNrMESE() {
    ++numarul_meselor_facute;
}

//void Bucatar::decrementNrFAR() {
//    --numarul_farfuriilor_facute;
//}

int Bucatar::getId() const{
    return id;
}

void Bucatar::setId() {
    id=++id_bucatar;
}

void Bucatar::prezentareAngajat(Angajat &ob) {
    std::cout<<"Buna ziua! Ma numesc "<<ob<<" si sunt bucatarul "<<id<<" la acest restaurant.\n";
}

void Bucatar::update_agenda(std::shared_ptr<Chelner> &mancare){
    agenda.push_back(mancare);
}

void Bucatar::sterge_din_agenda(std::shared_ptr<Chelner> &ptr) {
    int i=-1;
    for(auto &it:agenda){
        i++;
        if(it==ptr) {
            std::cout<<"Masa este gata, chelner "<<ptr->getId()<<"!\n";
            incrementNrMESE();
            agenda.erase(agenda.begin() + i);
            break;
        }
    }
} //aici sa se pune o eroare

Bucatar::~Bucatar()=default;

int Bucatar::id_bucatar=0;

