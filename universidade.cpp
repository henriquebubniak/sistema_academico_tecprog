#include "universidade.h"

Universidade::Universidade(string n)
{
    nome = n;
}
Universidade::Universidade()
{
    nome = "";
}

string Universidade::get_nome()
{
    return nome;
}