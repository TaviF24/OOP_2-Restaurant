//
// Created by Octavian Farcasi on 18.04.2023.
//

#ifndef OOP_BARMANI_H
#define OOP_BARMANI_H

#include "angajati.h"
#include "chelneri.h"

class Barman: public Angajat{
    private:
        static int id_barman;
        int id=0;
        int numarul_meselor_cu_bautura_facute;
        std::vector<std::shared_ptr<Chelner>>agenda;
    public:
        Barman(std::string &nume,int varsta, int numarul_bauturilor_per_masa_facute);
    
        Barman(const Barman &ob);
    
        Barman &operator=(const Barman &ob);
    
        int getNumarul_meselor_cu_bautura_facute() const;
    
        void incrementNrMESEcuBAUT();
    
//        void decrementNrBAUTURI();

        int getId() const override;

        void setId() override;
    
        void prezentareAngajat(Angajat &ob) override;

        void update_agenda(std::shared_ptr<Chelner> &bautura);

        void sterge_din_agenda(std::shared_ptr<Chelner> &ptr);

        ~Barman();
};

#endif //OOP_BARMANI_H
