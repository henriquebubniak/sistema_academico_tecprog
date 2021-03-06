#pragma once
#include <iostream>
#include <string>
#include "tempo.h"

using namespace std;

class Pessoa
{
public:
    Pessoa (string n, int d, int m, int a);
    Pessoa();
    void mostra_dados_pessoais();
protected:
    string nome;
    unsigned diaN;
    unsigned mesN;
    unsigned anoN;
    unsigned idade;
    void calcula_idade(int diaA, int mesA, int anoA);
};