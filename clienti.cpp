//
// Created by Octavian Farcasi on 20.04.2023.
//
#include "clienti.h"

Client::Client()=default;

Client::Client(std::map<std::string, int> &lista_mancare) : lista_mancare(lista_mancare) {}

Client::Client(std::string &nume):nume(nume) {}

bool Client::find(std::string &mancare) {
    auto i = lista_mancare.begin();
    while (i != lista_mancare.end()) {
        if (i->first == mancare)
            return true;
        i++;
    }
    return false;
}

void Client::update_lista(std::string &mancare) {
    if (find(mancare) == true)
        lista_mancare[mancare]++;
    else
        lista_mancare[mancare] = 1;
}

void Client::update_lista_bauturi(std::string &bauturi) {
    if (find(bauturi) == true)
        lista_mancare[bauturi]++;
    else
        lista_mancare[bauturi] = 1;
}

void Client::afis(){
    for (std::map<std::string, int>::iterator it = lista_mancare.begin(); it != lista_mancare.end(); ++it) {
        std::cout << it->first << " " << it->second << "  ";
    }
}

void Client::incrementMasa() {
    ++nr_masa;
}

void Client::setMasa(){
    incrementMasa();
    masa=nr_masa;
}

int Client::getMasa()const{
    return masa;
}

std::string Client::getNume() const {
    return nume;
}
//int Client::getcantitateMancare(const std::string &mancare){
//    return lista_mancare[mancare];
//}
//
//int Client::getcantitateBautura(const std::string &bautura){
//    return lista_bauturi[bautura];
//}

std::map<std::string, int> *Client::lista_de_mancare() {
    return &lista_mancare;
}

std::map<std::string, int> *Client::lista_de_bauturi() {
    return &lista_bauturi;
}

int Client::nr_masa=0;


