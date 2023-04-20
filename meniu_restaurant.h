//
// Created by Octavian Farcasi on 19.04.2023.
//

#ifndef OOP_MENIU_RESTAURANT_H
#define OOP_MENIU_RESTAURANT_H

#include<iostream>
#include<fstream>
#include<vector>
#include<map>

class Meniu{
    private:
        std::map<std::string,float>aperitiv,fel1,fel2,desert,bauturi;
    public:
        Meniu();

        virtual void afis();

        void updateMeniu();

        bool find(std::string mancare,std::map<std::string,float>dictionar);

        std::map<std::string,float> *lista_aperitiv();

        std::map<std::string,float> *lista_fel1();

        std::map<std::string,float> *lista_fel2();

        std::map<std::string,float> *lista_desert();

        std::map<std::string,float> *lista_bauturi();

        virtual ~Meniu();
};


#endif //OOP_MENIU_RESTAURANT_H
