//
// Created by Octavian Farcasi on 18.04.2023.
//
#include "angajati.h"

Angajat::Angajat(std::string &nume):nume(nume) {}

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
    if(varsta_noua<18)
        throw Nu_are_varsta_necesara();
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

