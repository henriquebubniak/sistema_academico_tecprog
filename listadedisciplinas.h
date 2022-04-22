#pragma once
#include "departamento.h"
#include "disciplina.h"
class Departamento;
class ElemDisciplina;
class Disciplina;
class ListaDeDisciplinas
{
public:
    void inicializa_departamento(Departamento* d);
    void adiciona_disciplina(Disciplina* a);
    void remove_disciplina(string n);
    void mostra_disciplinas();
    ElemDisciplina* get_primeira_disc();
    ListaDeDisciplinas(Departamento* d = NULL);
    ~ListaDeDisciplinas();
private:
    ElemDisciplina* ultima_disc;
    ElemDisciplina* primeira_disc;
    Departamento* departamento;
};