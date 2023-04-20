//
// Created by Octavian Farcasi on 18.04.2023.
//

#ifndef OOP_ANGAJATI_H
#define OOP_ANGAJATI_H

#include <iostream>
#include <memory>
#include"meniu_restaurant.h"

class Angajat:public Meniu{
    private:
        std::string nume;
        int varsta;
    public:
        Angajat(std::string nume,int varsta);

        const std::string &getNumeAngajat() const;

        int getVarsta() const;

        void setNume(const std::string &nume_nou);

        void setVarsta(int varsta_noua);

        friend std::ostream &operator<<(std::ostream &out,const Angajat &ob);

        virtual void afisare(std::ostream &out) const;

        virtual void prezentareAngajat(Angajat &ob)=0;

        virtual ~Angajat();

};


#endif //OOP_ANGAJATI_H
