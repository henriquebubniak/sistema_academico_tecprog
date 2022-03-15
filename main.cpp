#include "pessoa.h"
#include <iostream>
using namespace std;


int main()
{
    Universidade Cambridge("Cambridge");
    Universidade Princeton("Princeton");
    Pessoa Einstein("Albert Einstein", 14, 3, 1879, &Princeton);
    Pessoa Newton("Isaac Newton", 4, 1, 1643, &Cambridge);

    Einstein.mostra_dados();
    Newton.mostra_dados();

    return 0;
}