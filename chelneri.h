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
        int numarul_comenzilor=0;
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

        void update_agenda(std::shared_ptr<Client> &client);

        void update_ptbauturi(std::shared_ptr<Client> &client);

        void printagenda() const;

        void sterge_din_agenda(std::shared_ptr<Client> &ptr);

        float getPret(std::shared_ptr<Client> &masa, std::unique_ptr<Manager> &manager);

        const std::vector<std::shared_ptr<Client>> *lista_clienti(const Chelner &ob)const;

        const std::vector<std::shared_ptr<Client>> *lista_bauturi_clienti(const Chelner &ob)const;

        const std::map<std::shared_ptr<Client>,int> *lista_client_masa(const Chelner &ob)const;

        ~Chelner();
};


#endif //OOP_CHELNERI_H
