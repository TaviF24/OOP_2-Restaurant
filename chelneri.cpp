//
// Created by Octavian Farcasi on 18.04.2023.
//
#include "chelneri.h"
#include "meniu_restaurant.h"
#include<iostream>

Chelner::Chelner(std::string &nume, int varsta, int numarul_comenzilor):
         Angajat(nume,varsta), numarul_comenzilor(numarul_comenzilor) { setId(); }

Chelner::Chelner(const Chelner &ob): Angajat(ob),numarul_comenzilor(ob.numarul_comenzilor) {setId(); }

Chelner &Chelner::operator=(const Chelner &ob){
    numarul_comenzilor=ob.numarul_comenzilor;
    return *this;
}

int Chelner::getNumarulComenzilor() const {
    return numarul_comenzilor;
}

void Chelner::incrementNrCOM() {
    ++numarul_comenzilor;
}

void Chelner::decrementNrCOM() {
    --numarul_comenzilor;
}

int Chelner::getIdChelner() const{
    return id;
}

void Chelner::setId() {
    id=++id_chelner;
}

void Chelner::prezentareAngajat(Angajat &ob){
    std::cout<<"Buna ziua! Ma numesc "<<ob.getNumeAngajat()<<" si sunt chelnerul "<<id<<" la acest restaurant.\n";
}

void Chelner::update_agenda(std::shared_ptr<Client> &mancare){
    agenda.push_back(mancare);
    client_masa[mancare]=mancare->getMasa();
}

void Chelner::update_ptbauturi(std::shared_ptr<Client> &bauturi) {
    pt_bauturi.push_back(bauturi);
}

void Chelner::printagenda() const{
    for (auto it = client_masa.begin(); it != client_masa.end(); ++it){
        std::cout<<"Masa "<<it->second<<": ";
        it->first->afis();
        std::cout<<"\n";
    }
}

float Chelner::getPret(std::shared_ptr<Client> &masa){
    float pret=0;
    for(auto it=masa->lista_de_mancare()->begin();it!=masa->lista_de_mancare()->end();it++){
        if(find(it->first, *lista_aperitiv())||find(it->first, *lista_fel1())
         ||find(it->first, *lista_fel2())||find(it->first, *lista_desert()))
            pret=pret+(it->second)*masa->getcantitateMancare(it->first);
    }
    for(auto it=masa->lista_de_bauturi()->begin();it!=masa->lista_de_bauturi()->end();it++){
        if(find(it->first, *lista_bauturi())){
            pret=pret+(it->second)*masa->getcantitateBautura(it->first);
        }
    }
    return pret;
}

Chelner::~Chelner()=default;

int Chelner::id_chelner=0;

