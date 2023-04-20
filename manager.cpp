//
// Created by Octavian Farcasi on 20.04.2023.
//
#include "manager.h"

Manager::Manager(std::string &nume, int varsta):Meniu(),nume(nume),varsta(varsta) {}

void Manager::updateMeniu(Manager &ob) {
    std::string mancare;
    float pret;
    std::ifstream f("input.txt");

    f>>mancare;
    while(mancare!="."){
        f>>pret;
        (*lista_aperitiv(ob))[mancare]=pret;
        f>>mancare;
    }
    mancare="";
    f>>mancare;
    while(mancare!="."){
        f>>pret;
        (*lista_fel1(ob))[mancare]=pret;
        f>>mancare;
    }
    mancare="";
    f>>mancare;
    while(mancare!="."){
        f>>pret;
        (*lista_fel2(ob))[mancare]=pret;
        f>>mancare;
    }
    mancare="";
    f>>mancare;
    while(mancare!="."){
        f>>pret;
        (*lista_desert(ob))[mancare]=pret;
        f>>mancare;
    }
    mancare="";
    f>>mancare;
    while(mancare!="."){
        f>>pret;
        (*lista_bauturi(ob))[mancare]=pret;
        f>>mancare;
    }
    f.close();
}

std::ostream &operator<<(std::ostream &out,const Manager &ob){
    out<<"Buna ziua! Ma numesc "<<ob.nume<<", am "<<ob.varsta<<" ani si sunt managerul acestui restaurant.\n";
    return out;
}

void Manager::prezentare_manager(Manager &ob)const{
    std::cout<<ob;
}

Manager::~Manager()=default;

//int main(){
//    std::string nume="ion";
////
////    std::unique_ptr<Manager>m(new Manager(nume,24));
////    std::unique_ptr<Manager>p;
////    p=std::move(m);
////    p->updateMeniu();
////    p->afis();
//
//    Chelner ob(nume,24,2);
//
//
//    return 0;
//}