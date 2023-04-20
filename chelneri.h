//
// Created by Octavian Farcasi on 18.04.2023.
//

#ifndef OOP_CHELNERI_H
#define OOP_CHELNERI_H

#include "manager.h"
#include "angajati.h"
#include "clienti.h"

class Chelner: public Angajat {
    private:
        static int id_chelner;
        int id=0;
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

        int getId() const override;

        void setId() override;

        void prezentareAngajat(Angajat &ob)override;

        void update_agenda(std::shared_ptr<Client> &mancare);

        void update_ptbauturi(std::shared_ptr<Client> &bauturi);

        void printagenda() const;

        void sterge_din_agenda(int pozitie);

        float getPret(std::shared_ptr<Client> &masa, std::unique_ptr<Manager> &manager);

        ~Chelner();
};


#endif //OOP_CHELNERI_H
