//
// Created by Octavian Farcasi on 18.04.2023.
//
#include <iostream>
#include "clienti.h"
#include "chelneri.h"
#include "manager.h"

int main() {
    std::string nume="ion";

    std::unique_ptr<Manager>m(new Manager(nume,24));
    std::unique_ptr<Manager>p;
    p=std::move(m);
    p->updateMeniu(*p);
    p->afis();

    std::cout<<"\n\n\n";

    Chelner ob(nume,24,1);
    std::shared_ptr<Client>ob2(new Client);
    std::shared_ptr<Client>ob3(new Client);

    ob2->setMasa();
    ob3->setMasa();

    std::string food="ciorba",d="tiramisu";
    ob2->update_lista(food);
    ob2->update_lista(food);
    ob2->update_lista(food);
    ob2->update_lista(food);
    ob2->update_lista(d);

    ob3->update_lista(d);
    ob3->update_lista(d);

    //std::cout<<ob2.use_count()<<"\n";
    ob.update_agenda(ob2);
    ob.update_agenda(ob3);
    ob.printagenda();
    std::cout<<ob.getPret(ob2,p)<<"\n"<<ob.getPret(ob3,p);



    return 0;
}

