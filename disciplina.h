#pragma once
#include "professor.h"
#include "listadealunos.h"
#include <list>
#include <string>
using namespace std;
class Departamento;
class Professor;
class Disciplina 
{
public:
    Disciplina(string n);
    Disciplina();
    ~Disciplina();
    string get_nome();
    void adiciona_dep(Departamento *d);
    void adiciona_aluno(Aluno* a);
    void mostra_alunos();
    void incrementa_faltas(string n);
    void adiciona_nota_p1(string n, float p);
    void adiciona_nota_p2(string n, float p);
    void adiciona_nota_p3(string n, float p);
private:
    string nome;
    Departamento* dep;
    ListaDeAlunos lista_alunos;
    Professor* professor;
};