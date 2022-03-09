#include "pessoa.h"

int main()
{
    Pessoa Einstein("Albert Einstein", 14, 3, 1879);
    Pessoa Newton("Isaac Newton", 4, 1, 1643);
    int diaA, mesA, anoA;

    diaA = 7;
    mesA = 3;
    anoA = 2022;

    Einstein.calcula_idade(diaA, mesA, anoA);
    Newton.calcula_idade(diaA, mesA, anoA);
    Einstein.mostra_idade();
    Newton.mostra_idade();

    return 0;
}
//teste
void teste();
//teste
int teste2();