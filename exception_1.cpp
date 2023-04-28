//
// Created by Octavian Farcasi on 28.04.2023.
//
#include "exception_1.h"

Nu_are_varsta_necesara::Nu_are_varsta_necesara()=default;

const char *Nu_are_varsta_necesara::what() const noexcept {
    return "Nu are varsta minima\n.";
}