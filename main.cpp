#include <iostream>
#include "chelneri.h"

int main() {

    std::string s="ana";

    Chelner ob(s,2,1),ob2(ob);

    ob.setNume("mihai");

    ob2.prezentareAngajat(ob);

    return 0;
}
