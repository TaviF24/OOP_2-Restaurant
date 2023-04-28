//
// Created by Octavian Farcasi on 20.04.2023.
//

#ifndef OOP_MANAGER_H
#define OOP_MANAGER_H

#include "meniu_restaurant.h"

class Manager:public Meniu{
    private:
        std::string nume;
        int varsta;
    public:
        Manager(std::string &nume);

        static void updateMeniu(Manager &ob);

        friend std::ostream &operator<<(std::ostream &out, const Manager &ob);

        void prezentare_manager(Manager &ob)const;

        void setVarsta(int varsta_noua);

        ~Manager();
};

#endif //OOP_MANAGER_H
