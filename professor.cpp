#include "professor.h"

Professor::Professor(string n, int d, int m, int a):
Pessoa(n, d, m, a)
{
    uni = NULL;
    dep = NULL;
}

Professor::Professor():
Pessoa()
{
    uni = NULL;
    dep = NULL;
}

void Professor::associa_uni(Universidade* u)
{
    uni = u;
}

void Professor::associa_dep(Departamento* d)
{
    dep = d;
    uni = d->get_uni();
}

void Professor::mostra_dados_academicos()
{
    if(uni != NULL && dep != NULL)
        cout << "Ele está associado a universidade de " << uni->get_nome() <<
        ", no departamento " << dep->get_nome() << "." << endl;
}