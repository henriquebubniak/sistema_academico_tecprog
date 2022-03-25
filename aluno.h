#include "pessoa.h"

class Aluno : public Pessoa
{
public:
    void associa_uni(Universidade* u);
    void associa_dep(Departamento* dep);
    void mostra_dados_academicos();
    Aluno(string n, int d, int m, int a, long int r = 0);
    Aluno();
private:
    Universidade* uni;
    Departamento* dep;
    int RA;
};