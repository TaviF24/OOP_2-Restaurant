//
// Created by Octavian Farcasi on 19.04.2023.
//

#ifndef OOP_MENIU_RESTAURANT_H
#define OOP_MENIU_RESTAURANT_H

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
#include<memory>

class Meniu{
    private:
        std::map<std::string,float>aperitiv,fel1,fel2,desert,bauturi;
    public:
        Meniu();

        virtual void afis();


        static bool find(const std::string &mancare,std::map<std::string,float>dictionar);

        static std::map<std::string,float> *lista_aperitiv(Meniu &ob);

        static std::map<std::string,float> *lista_fel1(Meniu &ob);

        static std::map<std::string,float> *lista_fel2(Meniu &ob);

        static std::map<std::string,float> *lista_desert(Meniu &ob);

        static std::map<std::string,float> *lista_bauturi(Meniu &ob);

        virtual ~Meniu();
};


#endif //OOP_MENIU_RESTAURANT_H
