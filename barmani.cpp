//
// Created by Octavian Farcasi on 18.04.2023.
//
#include "barmani.h"
#include<iostream>

Barman::Barman(std::string &nume, int numarul_meselor_cu_bautura_facute):
        Angajat(nume), numarul_meselor_cu_bautura_facute(numarul_meselor_cu_bautura_facute) {id=++id_barman; }

Barman::Barman(const Barman &ob): Angajat(ob),numarul_meselor_cu_bautura_facute(ob.numarul_meselor_cu_bautura_facute) {id=++id_barman; }

Barman &Barman::operator=(const Barman &ob){
    numarul_meselor_cu_bautura_facute=ob.numarul_meselor_cu_bautura_facute;
    agenda=ob.agenda;
    return *this;
}

int Barman::getNumarul_meselor_cu_bautura_facute() const {
    return numarul_meselor_cu_bautura_facute;
}

void Barman::incrementNrMESEcuBAUT() {
    ++numarul_meselor_cu_bautura_facute;
}

//void Barman::decrementNrBAUTURI() {
//    --numarul_bauturilor_facute;
//}

int Barman::getId() const{
    return id;
}

void Barman::setId() {
    id=++id_barman;
}

void Barman::prezentareAngajat(Angajat &ob) {
    std::cout<<"Buna ziua! Ma numesc "<<ob<<" si sunt barmanul "<<id<<" la acest restaurant.\n";
}

void Barman::update_agenda(std::shared_ptr<Chelner> &bautura) {
    agenda.push_back(bautura);
}

void Barman::sterge_din_agenda(std::shared_ptr<Chelner> &ptr) {
    int i=-1;
    for(auto &it:agenda){
        i++;
        if(it==ptr) {
            std::cout<<"Bautura este gata, chelner "<<ptr->getId()<<"!\n";
            incrementNrMESEcuBAUT();
            agenda.erase(agenda.begin() + i);
            break;
        }
    }
}

Barman::~Barman()=default;

int Barman::id_barman=0;

