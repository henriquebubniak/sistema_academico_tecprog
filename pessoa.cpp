#include "pessoa.h"
#include <iostream>
using namespace std;

Pessoa::Pessoa(string n, int d, int m, int a)
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
Pessoa::Pessoa()
{
    nome = "";
    diaN = 0;
    mesN = 0;
    anoN = 0;
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

void Pessoa::mostra_dados_pessoais()
{
        cout << "a idade de " << nome << " é " << idade << " anos." << endl;
}
