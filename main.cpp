#include "pessoa.h"
#include <iostream>
using namespace std;


int main()
{
    Pessoa Einstein("Albert Einstein", 14, 3, 1879);
    Pessoa Newton("Isaac Newton", 4, 1, 1643);

    Einstein.mostra_idade();
    Newton.mostra_idade();

    return 0;
}