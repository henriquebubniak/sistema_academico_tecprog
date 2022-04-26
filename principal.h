#include <stdlib.h>
#include <iostream>
#include <string>
#include "tempo.h"
#include "listadedepartamentos.h"
#include "listadeuniversidades.h"
#include "listadedisciplinas.h"
#define NOME_ARQUIVO "dados.dat"
using namespace std;
class Principal
{
public:
    void gravar_dados();
    void recuperar_dados();
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
    void le_universidades();
    void le_departamentos();
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