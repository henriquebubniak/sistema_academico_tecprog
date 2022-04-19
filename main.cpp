#include "universidade.h"
#include "departamento.h"
#include "disciplina.h"
#include "aluno.h"
#include "professor.h"

int main()
{
//cria universidades
    Universidade UTFPR("Universidade Tecnológica do Paraná");
//cria departamentos
    Departamento DAINF("DAINF");
//cria disciplinas
    Disciplina fundamentos("Fundamentos de Programação");
    Disciplina estruturas("Estruturas de dados 1");
    Disciplina tecnicas("Técnicas de programação");
    Disciplina estruturas2("Estruturas de dados 2");
//cria pessoas
    Aluno Henrique("Henrique Gomes Pinto Bubniak", 26, 2, 2003, 2355876);
    Aluno Zamba("Henrique Ribas Zambenedetti", 24, 10, 2003);
    Aluno Greg("Gregório", 7,7,2003);
    Professor Simao("Simão", 12,7,1973);
//associa departamentos
    UTFPR.adiciona_dep(&DAINF);
//associa universidades
    Henrique.associa_uni(&UTFPR);
    Zamba.associa_uni(&UTFPR);
    Greg.associa_uni(&UTFPR);
//associa departamentos
    Simao.associa_dep(&DAINF);
//associa disciplinas
    DAINF.adiciona_disciplina(&fundamentos);
    DAINF.adiciona_disciplina(&estruturas);
    DAINF.adiciona_disciplina(&tecnicas);
    DAINF.adiciona_disciplina(&estruturas2);
    //UTFPR.get_dep()->remove_disciplina("Estruturas de dados");
    fundamentos.adiciona_aluno(&Henrique);
    fundamentos.adiciona_aluno(&Zamba);
    fundamentos.adiciona_aluno(&Greg);
    estruturas2.adiciona_aluno(&Greg);
    estruturas2.adiciona_aluno(&Henrique);
//adiciona notas e faltas
    fundamentos.incrementa_faltas("Henrique Ribas Zambenedetti");
    fundamentos.adiciona_nota_p1("Henrique Ribas Zambenedetti", 8.7);
    fundamentos.adiciona_nota_p1("Henrique Gomes Pinto Bubniak", 9);
    fundamentos.adiciona_nota_p1("Gregório", 9.5);

//mostra dados
    DAINF.mostra_disciplinas();
    Henrique.mostra_dados_pessoais();
    Henrique.mostra_dados_academicos();
    Zamba.mostra_dados_pessoais();
    Zamba.mostra_dados_academicos();
    Simao.mostra_dados_pessoais();
    Simao.mostra_dados_academicos();
    fundamentos.mostra_alunos();
    estruturas2.mostra_alunos();

    return 0;
}