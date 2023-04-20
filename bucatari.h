//
// Created by Octavian Farcasi on 18.04.2023.
//

#ifndef OOP_BUCATARI_H
#define OOP_BUCATARI_H

#include "angajati.h"
#include "chelneri.h"

class Bucatar: public Angajat{
    private:
        static int id_bucatar;
        int id=0;
        int numarul_farfuriilor_facute;
        std::vector<std::shared_ptr<Chelner>>agenda;
public:
        Bucatar(std::string &nume,int varsta, int numarul_farfuriilor_facute);

        Bucatar(const Bucatar &ob);

        Bucatar &operator=(const Bucatar &ob);

        int getNumarulFarfuriilor() const;

        void incrementNrFAR();

        void decrementNrFAR();

        int getId() const override;

        void setId() override;

        void prezentareAngajat(Angajat &ob) override;

        void update_agenda(std::shared_ptr<Chelner> &mancare);

        void sterge_din_agenda(int pozitie);

        ~Bucatar();
};

#endif //OOP_BUCATARI_H
