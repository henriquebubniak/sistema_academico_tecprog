#include "pessoa.h"
#include <iostream>
using namespace std;

Pessoa::Pessoa(const char *n, int d, int m, int a)
{
    nome = n;
    diaN = d;
    mesN = m;
    anoN = a;
    idade = 0;
    int diaA, mesA, anoA;
    get_data_int(&diaA, &mesA, &anoA);
    calcula_idade (diaA, mesA, anoA);
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
    cout << "a idade de " << nome << " é " << idade << " anos\n" << endl;
}