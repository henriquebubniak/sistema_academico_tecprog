#include "pessoa.h"
#include <iostream>
using namespace std;


int main()
{
//cria universidades
    Universidade Cambridge("Cambridge");
    Universidade Princeton("Princeton");
//cria departamentos
    Cambridge.cria_dep("Departamento de matemática");
    Princeton.cria_dep("Departamento de física");
//cria pessoas
    Pessoa Einstein("Albert Einstein", 14, 3, 1879);
    Pessoa Newton("Isaac Newton", 4, 1, 1643);
//associa universidades
    Einstein.associa_uni(&Princeton);
    Newton.associa_uni(&Cambridge);
//associa departamentos
    Einstein.associa_dep(Princeton.get_dep());
    Newton.associa_dep(Cambridge.get_dep());

//mostra dados
    Einstein.mostra_dados();
    Newton.mostra_dados();

    return 0;
}