#include "pessoa.h"

Pessoa::Pessoa(const char *n, int d, int m, int a)
{
    nome = n;
    diaN = d;
    mesN = m;
    anoN = a;
    idade = 0;
}

void Pessoa::calcula_idade(int diaA, int mesA, int anoA)
{
    idade = anoA - anoN;
    if (mesA < mesN)
        idade--;
    else if (mesA == mesN)
        if (diaA < diaN)
            idade--;
}

void Pessoa::mostra_idade()
{
    printf("a idade de %s é %u anos\n", nome, idade);
}