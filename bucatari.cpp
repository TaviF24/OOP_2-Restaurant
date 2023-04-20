//
// Created by Octavian Farcasi on 18.04.2023.
//
//
// Created by Octavian Farcasi on 18.04.2023.
//
#include "bucatari.h"
#include<iostream>

Bucatar::Bucatar(std::string &nume, int varsta, int numarul_farfuriilor_facute):
        Angajat(nume,varsta), numarul_farfuriilor_facute(numarul_farfuriilor_facute) { incrementIdBucatar(); }

Bucatar::Bucatar(const Bucatar &ob): Angajat(ob),numarul_farfuriilor_facute(ob.numarul_farfuriilor_facute) {incrementIdBucatar(); }

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

int Bucatar::getIdBucatar() {
    return id_bucatar;
}

void Bucatar::incrementIdBucatar() {
    ++id_bucatar;
}

void Bucatar::decrementIdBucatar() {
    --id_bucatar;
}

void Bucatar::prezentareAngajat(Angajat &ob) {
    std::cout<<"Buna ziua! Ma numesc "<<ob.getNumeAngajat()<<" si sunt bucatarul "<<id_bucatar<<" la acest restaurant.\n";
}

Bucatar::~Bucatar()=default;

int Bucatar::id_bucatar=0;

