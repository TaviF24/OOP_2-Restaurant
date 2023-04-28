//
// Created by Octavian Farcasi on 28.04.2023.
//
#include "exception_2.h"

Prea_mica_suma::Prea_mica_suma()=default;

const char *Prea_mica_suma::what() const noexcept {
    return "Ati achitat mai putin decat trebuia\n.";
}