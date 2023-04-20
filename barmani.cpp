//
// Created by Octavian Farcasi on 18.04.2023.
//
#include "barmani.h"
#include<iostream>

Barman::Barman(std::string &nume, int varsta, int numarul_bauturilor_facute):
        Angajat(nume,varsta), numarul_bauturilor_facute(numarul_bauturilor_facute) { incrementIdBarman(); }

Barman::Barman(const Barman &ob): Angajat(ob),numarul_bauturilor_facute(ob.numarul_bauturilor_facute) {incrementIdBarman(); }

Barman &Barman::operator=(const Barman &ob){
    numarul_bauturilor_facute=ob.numarul_bauturilor_facute;
    return *this;
}

int Barman::getNumarulbauturilor() const {
    return numarul_bauturilor_facute;
}

void Barman::incrementNrBAUTURI() {
    ++numarul_bauturilor_facute;
}

void Barman::decrementNrBAUTURI() {
    --numarul_bauturilor_facute;
}

int Barman::getIdBarman() {
    return id_barman;
}

void Barman::incrementIdBarman() {
    ++id_barman;
}

void Barman::decrementIdBarman() {
    --id_barman;
}

void Barman::prezentareAngajat(Angajat &ob) {
    std::cout<<"Buna ziua! Ma numesc "<<ob.getNumeAngajat()<<" si sunt barmanul "<<id_barman<<" la acest restaurant.\n";
}

void Barman::update_agenda(std::shared_ptr<Chelner> &mancare) {
    agenda.push_back(mancare);
}

Barman::~Barman()=default;

int Barman::id_barman=0;

