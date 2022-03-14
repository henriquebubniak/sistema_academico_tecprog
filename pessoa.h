#include <stdio.h>
#include "tempo.h"
#include "universidade.h"

class Pessoa
{
public:
    Pessoa (const char* n, int d, int m, int a);
    Pessoa();
    void calcula_idade(int diaA, int mesA, int anoA);
    void mostra_idade();
    void associa_uni(Universidade* u);

private:
    const char *nome;
    unsigned diaN;
    unsigned mesN;
    unsigned anoN;
    unsigned idade;  
    Universidade* uni;
};