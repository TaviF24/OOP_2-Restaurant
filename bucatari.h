//
// Created by Octavian Farcasi on 18.04.2023.
//

#ifndef OOP_BUCATARI_H
#define OOP_BUCATARI_H

#include "angajati.h"

class Bucatar: public Angajat{
    private:
        static int id_bucatar;
        int numarul_farfuriilor_facute;
    public:
        Bucatar(std::string &nume,int varsta, int numarul_farfuriilor_facute);

        Bucatar(const Bucatar &ob);

        Bucatar &operator=(const Bucatar &ob);

        int getNumarulFarfuriilor() const;

        void incrementNrFAR();

        void decrementNrFAR();

        static int getIdBucatar();

        static void incrementIdBucatar();

        static void decrementIdBucatar();

        void prezentareAngajat(Angajat &ob) override;

        ~Bucatar();
};

#endif //OOP_BUCATARI_H
