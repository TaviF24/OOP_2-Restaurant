//
// Created by Octavian Farcasi on 18.04.2023.
//

#ifndef OOP_CHELNERI_H
#define OOP_CHELNERI_H

#include "angajati.h"
#include "clienti.h"

class Chelner: public Angajat {
    private:
        static int id_chelner;
        int id;
        int numarul_comenzilor;
        std::vector<std::shared_ptr<Client>>agenda;
        std::vector<std::shared_ptr<Client>>pt_bauturi;
        std::map<std::shared_ptr<Client>,int>client_masa;
    public:
        Chelner(std::string &nume,int varsta,int numarul_comenzilor);

        Chelner(const Chelner &ob);

        Chelner &operator=(const Chelner &ob);

        int getNumarulComenzilor() const;

        void incrementNrCOM();

        void decrementNrCOM();

        int getIdChelner() const;

        void setId();

        void prezentareAngajat(Angajat &ob)override;

        void update_agenda(std::shared_ptr<Client> &mancare);

        void update_ptbauturi(std::shared_ptr<Client> &bauturi);

        void printagenda() const;

        float getPret(std::shared_ptr<Client> &masa);

        ~Chelner();
};


#endif //OOP_CHELNERI_H
