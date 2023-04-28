//
// Created by Octavian Farcasi on 26.04.2023.
//
#include "rezervari.h"

Rezervare::Rezervare()=default;

void Rezervare::insert_in_tabel(const std::string &nume) {
    tabel_cu_rezervari.push_back(nume);
}

bool Rezervare::verif_si_scoatere(const std::string &nume) {
    for(auto i=0;i<tabel_cu_rezervari.size();i++ )
        if(tabel_cu_rezervari[i]==nume){
            tabel_cu_rezervari.erase(tabel_cu_rezervari.begin() + i);
            return true;
        }
    return false;
}

unsigned long Rezervare::get_nr_rezervari() {
    return tabel_cu_rezervari.size();
}
