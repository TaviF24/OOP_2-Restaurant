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
        int numarul_bauturilor_facute;
        std::vector<std::shared_ptr<Chelner>>agenda;
    public:
        Barman(std::string &nume,int varsta, int numarul_bauturilor_facute);
    
        Barman(const Barman &ob);
    
        Barman &operator=(const Barman &ob);
    
        int getNumarulbauturilor() const;
    
        void incrementNrBAUTURI();
    
        void decrementNrBAUTURI();
    
        static int getIdBarman();
    
        static void incrementIdBarman();
    
        static void decrementIdBarman();
    
        void prezentareAngajat(Angajat &ob) override;

        void update_agenda(std::shared_ptr<Chelner> &mancare);
    
        ~Barman();
};

#endif //OOP_BARMANI_H
