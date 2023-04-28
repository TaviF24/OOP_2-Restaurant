//
// Created by Octavian Farcasi on 28.04.2023.
//

#ifndef OOP_EXCEPTION_1_H
#define OOP_EXCEPTION_1_H

#include<iostream>
class Nu_are_varsta_necesara:public std::exception{
    public:
        Nu_are_varsta_necesara();
        const char* what() const noexcept override;
};

#endif //OOP_EXCEPTION_1_H
