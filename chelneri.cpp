//
// Created by Octavian Farcasi on 18.04.2023.
//
#include "chelneri.h"

Chelner::Chelner(std::string &nume, int varsta, int numarul_comenzilor):
         Angajat(nume,varsta), numarul_comenzilor(numarul_comenzilor) {}

Chelner::Chelner(const Chelner &ob): Angajat(ob),numarul_comenzilor(ob.numarul_comenzilor) {}

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

int Chelner::getId() const{
    return id;
}

void Chelner::setId() {
    std::cout<<"da\n";
    id=++id_chelner;
}

void Chelner::prezentareAngajat(Angajat &ob){
    std::cout<<"Buna ziua! Ma numesc "<<ob<<" si sunt chelnerul "<<id<<" la acest restaurant.\n";
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

void Chelner::sterge_din_agenda(int pozitie) {
    agenda.erase(agenda.begin()+pozitie);
}

float Chelner::getPret(std::shared_ptr<Client> &masa,std::unique_ptr<Manager>&manager){
    float pret=0;
    for(auto it=masa->lista_de_mancare()->begin();it!=masa->lista_de_mancare()->end();it++){
        if(find(it->first, *lista_aperitiv(*manager)))
            pret=pret+(*lista_aperitiv(*manager))[it->first]*(it->second);
        else
            if(find(it->first, *lista_fel1(*manager)))
                pret=pret+(*lista_fel1(*manager))[it->first]*(it->second);
            else
                if(find(it->first, *lista_fel2(*manager)))
                    pret=pret+(*lista_fel2(*manager))[it->first]*(it->second);
                else
                    if(find(it->first, *lista_desert(*manager)))
                        pret=pret+(*lista_desert(*manager))[it->first]*(it->second);
    }
    for(auto it=masa->lista_de_bauturi()->begin();it!=masa->lista_de_bauturi()->end();it++){
        if(find(it->first, *lista_bauturi(*manager)))
            pret=pret+( (*lista_bauturi(*manager))[it->first] )*(it->second);
    }
    return pret;
}

Chelner::~Chelner()=default;

int Chelner::id_chelner=0;

