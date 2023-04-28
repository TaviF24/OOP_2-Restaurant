//
// Created by Octavian Farcasi on 28.04.2023.
//

#ifndef OOP_EXCEPTION_2_H
#define OOP_EXCEPTION_2_H

#include<iostream>
class Prea_mica_suma:public std::exception{
public:
    Prea_mica_suma();
    const char* what() const noexcept override;
};

#endif //OOP_EXCEPTION_2_H
