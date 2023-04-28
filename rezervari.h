//
// Created by Octavian Farcasi on 26.04.2023.
//

#ifndef OOP_REZERVARI_H
#define OOP_REZERVARI_H

#include "clienti.h"


class Rezervare{
    private:
//        std::map<std::shared_ptr<Client>,std::string>tabel_cu_rezervari
        std::vector<std::string>tabel_cu_rezervari;
    public:
        Rezervare();

        void insert_in_tabel(const std::string &nume);

        bool verif_si_scoatere(const std::string &nume);

        unsigned long get_nr_rezervari();
};

#endif //OOP_REZERVARI_H
