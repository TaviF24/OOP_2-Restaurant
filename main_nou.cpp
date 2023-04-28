//
// Created by Octavian Farcasi on 18.04.2023.
//
#include "menu.h"

int main() {
//    std::string nume="ion";
//
//    std::unique_ptr<Manager>m(new Manager(nume,24));
//    std::unique_ptr<Manager>p;
//    p=std::move(m);
//    p->updateMeniu(*p);
//    p->afis();
//
//    std::cout<<"\n\n\n";
//
//    Chelner ob(nume,24,1);
//    std::shared_ptr<Client>ob2(new Client);
//    std::shared_ptr<Client>ob3(new Client);
//
//    ob2->setMasa();
//    ob3->setMasa();
//
//    std::string food="ciorba",d="tiramisu";
//    ob2->update_lista(food);
//    ob2->update_lista(food);
//    ob2->update_lista(food);
//    ob2->update_lista(food);
//    ob2->update_lista(d);
//
//    ob3->update_lista(d);
//    ob3->update_lista(d);
//
//    ob.update_agenda(ob2);
//    ob.update_ptbauturi(ob2);
//    //ob.update_agenda(ob3);
//    //ob.printagenda();
//    //std::cout<<ob.getPret(ob2,p)<<"\n"<<ob.getPret(ob3,p);
//    Chelner obj(ob),obj1(nume,4,2);
//    obj1=ob;
////    obj.prezentareAngajat(obj);
////    obj.printagenda();
////    obj1.prezentareAngajat(obj1);
////    obj1.printagenda();
////    ob.sterge_din_agenda(ob2);
////    std::cout<<ob2.use_count();
////    std::cout<<"\n"<<(*ob.lista_clienti(ob))[0].use_count()<<" "<<(*ob.lista_client_masa(ob)).begin()->first.use_count();
//        //rezultatul//3 ==> nr chelneri;
//
//    std::cout<<"Agenda lui ob:";
//    ob.printagenda();
//    ob.sterge_din_agenda(ob2);
//
//    std::cout<<"Agenda lui ob nou:";
//    ob.printagenda();
//
//    std::cout<<"\nAgenda lui obj1:";
//    obj1.printagenda();
//
//
//    std::shared_ptr<Chelner>chelner(new Chelner(nume,100,0));
//    std::shared_ptr<Chelner>chelner2(new Chelner(nume,100,0));
//    chelner->update_agenda(ob2);
//    Bucatar buc(nume,23,0);
//    buc.update_agenda(chelner);
//    buc.update_agenda(chelner2);
//    buc.sterge_din_agenda(chelner);
//    buc.sterge_din_agenda(chelner2);
//    std::cout<<buc.getNumarulMeselor();
//    buc.prezentareAngajat(buc);


    Menu ob;
    ob.start();

    return 0;
}

