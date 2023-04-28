//
// Created by Octavian Farcasi on 28.04.2023.
//
#include "menu.h"
#include <unistd.h>

void Menu::start() {
//dynamic cast cu meniu-chelneri sau anagajti-chelneri

std::unique_ptr<Manager>manager;
std::vector<std::shared_ptr<Chelner>>chelneri;
std::vector<std::shared_ptr<Bucatar>>bucatari;
std::vector<std::shared_ptr<Barman>>barmani;
std::vector<std::shared_ptr<Client>>clienti_existenti;
std::map<std::shared_ptr<Client>,int>clienti;
std::shared_ptr<Rezervare>rezervare(new Rezervare);
int tasta,tasta_mod=1,ok=0,varsta,numar_mese;
std::string nume;

std::cout<<"START = Apasati tasta 1\n";
std::cout<<"END = Apasati tasta 2\n";
std::cin>>tasta;

if(tasta==2)
    std::cout<<"SFARSIT\n";
else
    if(tasta==1){
        bool ind_manag= false,ind_angaj= false,ind_mese= false;
        while(ok!=3){
            std::cout<<"\nStabiliti setarile:\n";
            if(!ind_manag)
                std::cout<<"   ● Manager = Apasati tasta 1\n";
            if(!ind_angaj)
                std::cout<<"   ● Angajatii = Apasati tasta 2\n";
            if(!ind_mese)
                std::cout<<"   ● Numarul de mese din restaurant = Apasati tasta 3\n";
            std::cout<<"\nTreceti la pasul urmator = Apasati tasta 4\n";

            std::cin>>tasta;

            if(tasta==4){
                std::cout<<"Nu va puteti deschide restaurantul, deoarece nu toate setarile au fost realizate!\n";
            }
            else
                if(tasta==1) {
                    if (!ind_manag) {
                        std::cout << "Ati ales sa setati manager-ul:\n";
                        std::cout << "   ● Numele lui va fi: "; std::cin >> nume;
                        std::cout << "   ● Varsta lui va fi: "; std::cin >> varsta;

                        try{
                            manager = std::make_unique<Manager>(nume);
                            manager->setVarsta(varsta);
                            ind_manag = true;
                            ok++;
                            manager->prezentare_manager(*manager);
                            std::cout<<*manager;
                            manager->updateMeniu(*manager);
                        }
                        catch(const Nu_are_varsta_necesara &ob){
                            std::cout<<ob.what();
                        }
                    }
                    else
                        std::cout << "Ati setat deja manager-ul!\n";
                }
                else
                    if(tasta==3){
                        if(!ind_mese){
                            std::cout<<"Ati ales sa setati capacitatea restaurantului:\n";
                            std::cout<<"   ● Numarul de mese va fi: "; std::cin>>numar_mese;
                            ind_mese=true;
                            ok++;
                        }
                        else
                            std::cout<<"Ati setat deja numarul de mese!\n";
                    }
                    else
                        if(tasta==2){
                            if(!ind_angaj){
                                ok++;
                                std::cout<<"Ati ales sa setati angajatii restaurantului:\n";
                                std::cout << "   ● Chelneri = Apasati 4\n   ● Bucatari = Apasati 5\n   ● Barmani = Apasati 6\n";


                                int nr=0;

                                while(nr!=3){
                                    std::cin>>tasta;
                                    if(tasta==4 && chelneri.empty()){
                                        std::cout<<"Introduceti chelneri\n";
                                        std::cout<<"● Adaugati un chelner = Apasati 3\n● Nu mai adaugati = Apasati 4\n";

                                        std::cin>>tasta;
                                        if(tasta==3){
                                            nr++;
                                            while(tasta==3){
                                                std::cout << "   ● Numele lui va fi: "; std::cin >> nume;
                                                std::cout << "   ● Varsta lui va fi: "; std::cin >> varsta;
                                                std::shared_ptr<Meniu>chelner(new Chelner(nume,0));
                                                chelneri.push_back(std::dynamic_pointer_cast<Chelner>(chelner));
                                                std::cout<<"● Adaugati un chelner = Apasati 3\n● Nu mai adaugati = Apasati 4\n";
                                                std::cin>>tasta;
                                            }
                                        }
                                        for(auto &i:chelneri)
                                            i->prezentareAngajat(*i);
                                    }
                                    if(tasta==5 && bucatari.empty()){
                                        std::cout<<"Introduceti bucatari\n";
                                        std::cout<<"● Adaugati un bucatar = Apasati 3\n● Nu mai adaugati = Apasati 4\n";

                                        std::cin>>tasta;
                                        if(tasta==3){
                                            nr++;
                                            while(tasta==3){
                                                std::cout << "   ● Numele lui va fi: "; std::cin >> nume;
                                                std::cout << "   ● Varsta lui va fi: "; std::cin >> varsta;
                                                bucatari.push_back(std::make_shared<Bucatar>(nume,0));
                                                std::cout<<"● Adaugati un bucatar = Apasati 3\n● Nu mai adaugati = Apasati 4\n";
                                                std::cin>>tasta;
                                            }
                                        }
                                        for(auto &i:bucatari)
                                            i->prezentareAngajat(*i);
                                    }
                                    if(tasta==6 && barmani.empty()){
                                        std::cout<<"Introduceti barmani\n";
                                        std::cout<<"● Adaugati un barman = Apasati 3\n● Nu mai adaugati = Apasati 4\n";

                                        std::cin>>tasta;
                                        if(tasta==3){
                                            nr++;
                                            while(tasta==3){
                                                std::cout << "   ● Numele lui va fi: "; std::cin >> nume;
                                                std::cout << "   ● Varsta lui va fi: "; std::cin >> varsta;
                                                barmani.push_back(std::make_shared<Barman>(nume,0));
                                                std::cout<<"● Adaugati un barman = Apasati 3\n● Nu mai adaugati = Apasati 4\n";
                                                std::cin>>tasta;
                                            }
                                        }
                                        for(auto &i:barmani)
                                            i->prezentareAngajat(*i);
                                    }

                                    if(chelneri.empty())
                                        std::cout << "   ● Chelneri = Apasati 4\n";
                                    if(bucatari.empty())
                                        std::cout<<"   ● Bucatari = Apasati 5\n";
                                    if(barmani.empty())
                                        std::cout<<"   ● Barmani = Apasati 6\n";

                                }

                                ind_angaj= true;
                            }
                        }

        }
        std::cout<<"\n\n";
        for(auto &i:chelneri)
            i->prezentareAngajat(*i);
        for(auto &i:bucatari)
            i->prezentareAngajat(*i);
        for(auto &i:barmani)
            i->prezentareAngajat(*i);

        std::cout<<"Setarile au fost facute. Puteti incepe:\n   ●Incepeti = Apasati 4\n   ●Terminati = Apasati 5\n";

        std::cin>>tasta;

        if(tasta==4){
            std::cout<<"\nSunteti in modul client. Puteti sa comutati intre client si angajat apasand tasta 0.\nPentru a termina, tastati 404.\n";
            std::cin>>tasta;
            while(tasta!=404){
                if(tasta==0){
                    std::cout<<"Selectati modul pe care il doriti:\n   ●Client = Apasati 1\n   ●Chelner = Apasati 2\n   ●Bucatar = Apasati 3\n   ●Barman = Apasati 4\n";
                    std::cin>>tasta_mod;
                }
                if(tasta_mod==1){
                    std::shared_ptr<Client>client_curent= nullptr;
                    std::cout<<"Sunteti in modul client.\n   ●Creati un nou client = Apasati 1\n   ●Alegeti din clientii existenti = Apasati 2\n";
                    std::cin>>tasta;
                    if(tasta==1){
                        std::cout<<"Numele clientului este: ";std::cin>>nume;
                        client_curent=std::make_shared<Client>(nume);
                    }
                    if(tasta==2){
                        std::cout<<"Alegeti din clientii existenti:\n";
                        if(!clienti_existenti.empty()) {
                            int j=0;
                            for (auto &i:clienti_existenti){
                                j++;
                                std::cout << "   " << j << " " << clienti_existenti[j-1]->getNume()
                                          << " ; Numarul mesei: " << i->getMasa() << "\n";}
                            std::cin>>tasta;
                            client_curent=clienti_existenti[tasta-1];
                        }
                        else
                            std::cout<<"Nu exista clienti\n";
                    }
                    if(client_curent!= nullptr) {
                        std::cout << "Sunteti clientul: " << client_curent->getNume() << ". Ce doriti sa efectuati?\n";
                        if (client_curent->getMasa() == 0) {
                            std::cout<< "   ●Faceti rezervare si apoi mergeti la restaurant = Apasati 1\n   ●Mergeti direct la restaurant = Apasati 2\n";
                            std::cin >> tasta;
                            if (tasta == 1) {
                                if (client_curent->getMasa() == 0 && numar_mese > 0) {
                                    if(numar_mese>0){
                                        rezervare->insert_in_tabel(client_curent->getNume());
                                        clienti_existenti.push_back(client_curent);
                                        clienti[client_curent]=0;
                                        client_curent->setMasa();
                                        numar_mese--;
                                    }
                                } else {
                                    if (numar_mese == 0)
                                        std::cout << "Ne pare rau dar nu mai sunt mese disponibile. Incercati la restaurant.\n";
                                    else
                                        std::cout << "Aveti deja o masa rezervata.\n";
                                }
                            }

                            std::shared_ptr <Chelner> chelner_curent = nullptr;
                            tasta_mod = 2;
                            std::cout << "\nModul s-a schimbat in chelner.\n";
                            std::cout << "Alegeti un chelner dintre cei existenti:\n";
                            int j=0;
                            for (auto &i:chelneri){
                                j++;
                                std::cout << "   " << j << " " << chelneri[j-1]->getNumeAngajat()
                                          << " ; Id: " << i->getId() << "\n";}
                            std::cin >> tasta;
                            chelner_curent = chelneri[tasta - 1];
                            std::cout << "Ati ales chelnerul " << chelner_curent->getNumeAngajat() << " cu ID-ul "
                                      << chelner_curent->getId() << "\n";

                            tasta_mod = 1;
                            std::cout << "Modul s-a schimbat in client.\n";
                            std::cout << ".";
                            sleep(1);
                            std::cout << ".";
                            sleep(1);
                            std::cout << ".\n";
                            sleep(1);
                            std::cout << "Ati ajuns la restaurant\n";
                            sleep(2);
                            std::cout << "-Buna ziua!\n";
                            sleep(1);
                            std::cout << "-Buna ziua. Am dori o masa. Se poate?\n";
                            sleep(1);
                            std::cout << "-Da, aveti rezervare?\n";
                            sleep(1);
                            std::cout << "   ●-Da = Apasati 1\n   ●-Nu = Apasati 2\n";
                            std::cin >> tasta;
                            if (tasta == 1) {
                                std::cout << "-Spuneti-mi numele, va rog\n";
                                sleep(1);
                                std::cout << "-" << client_curent->getNume() << "\n";
                                sleep(2);
                                if (rezervare->verif_si_scoatere(client_curent->getNume())) {
                                    std::cout << "-V-am gasit. Urmati-ma!\n";
                                } else {
                                    std::cout << "-Nu v-am gasit.";
                                    if (numar_mese > 0) {
                                        sleep(1);
                                        std::cout << "Mai sunt mese libere, urmati-ma!\n";
                                        clienti_existenti.push_back(client_curent);
                                        clienti[client_curent]=0;
                                        client_curent->setMasa();
                                        numar_mese--;
                                    }
                                    else{
                                        sleep(1);
                                        std::cout<<"Ne cerem scuze, dar nu mai sunt mese disponibile\n";}
                                }
                            }
                            else{
                                if (numar_mese > 0) {
                                    std::cout << "-Ok, urmati-ma!\n";
                                    clienti_existenti.push_back(client_curent);
                                    clienti[client_curent]=0;
                                    client_curent->setMasa();
                                    numar_mese--;
                                }
                                else
                                    std::cout << "Ne cerem scuze, dar nu mai sunt mese disponibile\n";
                            }
                        }
                    }

                }
                if(tasta_mod==2){
                    std::shared_ptr<Client>client_curent= nullptr;
                    std::shared_ptr <Chelner> chelner_curent = nullptr;
                    int nrmasa;
                    std::cout<<"Sunteti in modul chelner.\n   ●Alegeti chelnerul curent = Apasati 1\n   ●Creati nota unui client = Apasati 2\n";
                    std::cin>>tasta;

                    if(tasta==1){
                        int j=0;
                        for (auto &i:chelneri){
                            j++;
                            std::cout << "   " << j << " " << chelneri[j-1]->getNumeAngajat()
                                      << " ; Id: " << i->getId() << "\n";
                        }
                        std::cin>>tasta;
                        chelner_curent=chelneri[tasta-1];
                    }
                    if(tasta==2){
                        std::cout<<"Masa clientului este: ";std::cin>>nrmasa;
                        float suma=0;
                        for(auto & i : clienti_existenti)
                            if(i->getMasa()==nrmasa)
                                try{
                                    std::cout<<"Aveti de platit:"<<chelner_curent->getPret(i,manager)<<"RON. \n Cat alegeti sa platiti?\n";std::cin>>suma;
                                    chelner_curent->achitare(suma,i,manager);
                                }
                                catch(const Prea_mica_suma &ob){
                                    std::cout<<ob.what();
                                }

                    }
                }
                std::cout<<"Pentru a termina, tastati 404: ";std::cin>>tasta;
            }
        }

    }




}