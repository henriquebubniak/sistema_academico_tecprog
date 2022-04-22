#include <stdlib.h>
#include "tempo.h"
#include "listadedepartamentos.h"
#include "listadeuniversidades.h"
#include "listadedisciplinas.h"
#include <iostream>
using namespace std;
class Principal
{
public:
    void menu();
    void menu_cadastro();
    void menu_leitura();
    void cadastro_universidade();
    void cadastro_departamento();
    void cadastro_disciplina();
    void cadastro_aluno();
    void cadastro_aluno_novo();
    void cadastro_aluno_em_disc();
    void cadastro_aluno_em_disc(Aluno* a);
    Universidade* localiza_uni(string n);
    Departamento* localiza_dep(string n);
    Disciplina* localiza_disc(string n);
    Principal();
    ~Principal();
private:
    int diaA;
    int mesA;
    int anoA;
    ListaDeUniversidades lista_unis;
    ListaDeDepartamentos lista_deps;
    ListaDeDisciplinas lista_discs;
    ListaDeAlunos lista_alunos;

};