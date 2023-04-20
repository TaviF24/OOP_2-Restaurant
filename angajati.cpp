//
// Created by Octavian Farcasi on 18.04.2023.
//
#include "angajati.h"
#include <iostream>

Angajat::Angajat(std::string nume, int varsta):nume(nume),varsta(varsta) {}

const std::string &Angajat::getNumeAngajat() const {
    return nume;
}

int Angajat::getVarsta() const {
    return varsta;
}

void Angajat::setNume(const std::string &nume_nou) {
    nume=nume_nou;
}

void Angajat::setVarsta(int varsta_noua) {
    varsta=varsta_noua;
}

std::ostream &operator<<(std::ostream &out,const Angajat &ob){
    ob.afisare(out);
    return out;
}

void Angajat::afisare(std::ostream &out) const {
    out<<nume;
}

Angajat::~Angajat()=default;

