//
// Created by Octavian Farcasi on 18.04.2023.
//
#include "chelneri.h"

Chelner::Chelner(std::string &nume, int numarul_comenzilor):
         Angajat(nume), numarul_comenzilor(numarul_comenzilor) {id=++id_chelner;}

Chelner::Chelner(const Chelner &ob): Angajat(ob),numarul_comenzilor(ob.numarul_comenzilor) {
    id=++id_chelner;
    agenda=ob.agenda;
    pt_bauturi=ob.pt_bauturi;
    client_masa=ob.client_masa;
}

Chelner &Chelner::operator=(const Chelner &ob){
    numarul_comenzilor=ob.numarul_comenzilor;
    agenda=*lista_clienti(ob);
    pt_bauturi=*lista_bauturi_clienti(ob);
    client_masa=*lista_client_masa(ob);
    return *this;
}

int Chelner::getNumarulComenzilor() const {
    return numarul_comenzilor;
}

void Chelner::incrementNrCOM() {
    ++numarul_comenzilor;
}

//void Chelner::decrementNrCOM() {
//    --numarul_comenzilor;
//}

int Chelner::getId() const{
    return id;
}

void Chelner::setId() {
    id=++id_chelner;
}

void Chelner::prezentareAngajat(Angajat &ob){
    std::cout<<"Buna ziua! Ma numesc "<<ob<<" si sunt chelnerul "<<id<<" la acest restaurant.\n";
}

void Chelner::update_agenda(std::shared_ptr<Client> &client){
    agenda.push_back(client);
    client_masa[client]=client->getMasa();
}

void Chelner::update_ptbauturi(std::shared_ptr<Client> &client) {
    pt_bauturi.push_back(client);
    client_masa[client]=client->getMasa();
}

void Chelner::printagenda() const{
    for (auto it = client_masa.begin(); it != client_masa.end(); ++it){
        std::cout<<"Masa "<<it->second<<": ";
        it->first->afis();
        std::cout<<"\n";
    }
}

void Chelner::sterge_din_agenda(std::shared_ptr<Client> &ptr) {
    int i=-1;
    for(auto &it:agenda){
        i++;
        if(it==ptr) {
            agenda.erase(agenda.begin() + i);
            break;
        }
    }
    i=-1;
    for(auto &it:pt_bauturi){
        i++;
        if(it==ptr) {
            pt_bauturi.erase(pt_bauturi.begin() + i);
            break;
        }
    }
    client_masa.erase(ptr);
}

float Chelner::getPret(std::shared_ptr<Client> &masa,std::unique_ptr<Manager>&manager){
    float pret=0;
    for(auto it=masa->lista_de_mancare()->begin();it!=masa->lista_de_mancare()->end();it++){  //it se uita in lista de mancare a clientului
        if(find(it->first, *lista_aperitiv(*manager)))
            pret=pret+(*lista_aperitiv(*manager))[it->first]*(float(it->second));
        else
            if(find(it->first, *lista_fel1(*manager)))
                pret=pret+(*lista_fel1(*manager))[it->first]*(float(it->second));
            else
                if(find(it->first, *lista_fel2(*manager)))
                    pret=pret+(*lista_fel2(*manager))[it->first]*(float(it->second));
                else
                    if(find(it->first, *lista_desert(*manager)))
                        pret=pret+(*lista_desert(*manager))[it->first]*(float(it->second));
    }
    for(auto it=masa->lista_de_bauturi()->begin();it!=masa->lista_de_bauturi()->end();it++){
        if(find(it->first, *lista_bauturi(*manager)))
            pret=pret+( (*lista_bauturi(*manager))[it->first] )*(float(it->second));
    }
    return pret;
}   //calculez pretul clientului

//exceptie aici

void Chelner::achitare(float suma_de_bani,std::shared_ptr<Client> &masa,std::unique_ptr<Manager>&manager) {
    if(suma_de_bani>= getPret(masa,manager)){
        std::cout<<"Multumesc! O zi frumoasa!\n";
        sterge_din_agenda(masa);
        incrementNrCOM();
    }
    else
        throw Prea_mica_suma();

}//si aici inca o eroare

const std::vector<std::shared_ptr<Client>> *Chelner::lista_clienti(const Chelner &ob) const {
    return &ob.agenda;
}

const std::vector<std::shared_ptr<Client>> *Chelner::lista_bauturi_clienti(const Chelner &ob) const {
    return &ob.pt_bauturi;
}

const std::map<std::shared_ptr<Client>, int> *Chelner::lista_client_masa(const Chelner &ob) const {
    return &ob.client_masa;
}

Chelner::~Chelner()=default;

int Chelner::id_chelner=0;

