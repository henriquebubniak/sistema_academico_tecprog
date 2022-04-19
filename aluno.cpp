#include "aluno.h"
#include "universidade.h"

Aluno::Aluno(string n, int d, int m, int a, long int r):
Pessoa(n, d, m, a)
{
    uni = NULL;
    RA = r;
}

Aluno::Aluno():
Pessoa()
{
    uni = NULL;
    RA = 0;
}

void Aluno::associa_uni(Universidade* u)
{
    uni = u;
}

void Aluno::mostra_dados_academicos()
{
    if(uni != NULL)
        cout << "Ele está associado a universidade de " << uni->get_nome() << ". Seu RA é "
        << RA << "." << endl;
}

string Aluno::get_nome()
{
    return nome;
}
Aluno::~Aluno()
{    
}