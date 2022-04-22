#pragma once

#include "pessoa.h"
class Departamento;
class Universidade;
class Aluno : public Pessoa
{
public:
    void associa_uni(Universidade* u);
    void mostra_dados_academicos();
    void set_ra(int r);
    string get_nome();
    Aluno(string n, int d, int m, int a);
    Aluno();
    ~Aluno();
private:
    Universidade* uni;
    int RA;
};