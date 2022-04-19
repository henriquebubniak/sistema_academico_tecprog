#pragma once

#include "pessoa.h"
class Departamento;
class Universidade;
class Aluno : public Pessoa
{
public:
    void associa_uni(Universidade* u);
    void mostra_dados_academicos();
    string get_nome();
    Aluno(string n, int d, int m, int a, long int r = 0);
    Aluno();
    ~Aluno();
private:
    Universidade* uni;
    int RA;
};