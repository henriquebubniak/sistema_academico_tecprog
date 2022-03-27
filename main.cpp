#include "pessoa.h"
#include "professor.h"
#include "aluno.h"
#include <iostream>
using namespace std;


int main()
{
//cria universidades
    Universidade UTFPR("Universidade Tecnológica do Paraná");
//cria departamentos
    UTFPR.cria_dep("DAINF");
//cria disciplinas
    Disciplina fundamentos("Fundamentos de Programação");
    Disciplina estruturas("Estruturas de dados 1");
    Disciplina tecnicas("Técnicas de programação");
    Disciplina estruturas2("Estruturas de dados 2");
//cria pessoas
    Aluno Henrique("Henrique Gomes Pinto Bubniak", 26, 2, 2003, 2355876);
    Professor Simao("Simão", 12,7,1973);
//associa universidades
    Henrique.associa_uni(&UTFPR);
    Simao.associa_uni(&UTFPR);
//associa departamentos
    Henrique.associa_dep(UTFPR.get_dep());
    Simao.associa_dep(UTFPR.get_dep());
//associa disciplinas
    UTFPR.get_dep()->adiciona_disciplina(&fundamentos);
    UTFPR.get_dep()->adiciona_disciplina(&estruturas);
    UTFPR.get_dep()->adiciona_disciplina(&tecnicas);
    UTFPR.get_dep()->adiciona_disciplina(&estruturas2);
    UTFPR.get_dep()->remove_disciplina("Fundamentos de Programaçao");
//mostra dados
    UTFPR.get_dep()->mostra_disciplinas();
    Henrique.mostra_dados_pessoais();
    Henrique.mostra_dados_academicos();
    Simao.mostra_dados_pessoais();
    Simao.mostra_dados_academicos();

    return 0;
}