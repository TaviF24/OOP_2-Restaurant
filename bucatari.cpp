//
// Created by Octavian Farcasi on 18.04.2023.
//
//
// Created by Octavian Farcasi on 18.04.2023.
//
#include "bucatari.h"
#include<iostream>

Bucatar::Bucatar(std::string &nume, int varsta, int numarul_farfuriilor_facute):
        Angajat(nume,varsta), numarul_farfuriilor_facute(numarul_farfuriilor_facute) { }

Bucatar::Bucatar(const Bucatar &ob): Angajat(ob),numarul_farfuriilor_facute(ob.numarul_farfuriilor_facute) { }

Bucatar &Bucatar::operator=(const Bucatar &ob){
    numarul_farfuriilor_facute=ob.numarul_farfuriilor_facute;
    return *this;
}

int Bucatar::getNumarulFarfuriilor() const {
    return numarul_farfuriilor_facute;
}

void Bucatar::incrementNrFAR() {
    ++numarul_farfuriilor_facute;
}

void Bucatar::decrementNrFAR() {
    --numarul_farfuriilor_facute;
}

int Bucatar::getId() const{
    return id;
}

void Bucatar::setId() {
    id=++id_bucatar;
}

void Bucatar::prezentareAngajat(Angajat &ob) {
    std::cout<<"Buna ziua! Ma numesc "<<ob.getNumeAngajat()<<" si sunt bucatarul "<<id_bucatar<<" la acest restaurant.\n";
}

void Bucatar::update_agenda(std::shared_ptr<Chelner> &mancare){
    agenda.push_back(mancare);
}

void Bucatar::sterge_din_agenda(int pozitie) {
    agenda.erase(agenda.begin()+pozitie);
}

Bucatar::~Bucatar()=default;

int Bucatar::id_bucatar=0;

