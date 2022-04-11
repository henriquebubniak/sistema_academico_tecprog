#include "disciplina.h"
Disciplina::Disciplina(string n)
{
    nome = n;
    dep = NULL;
    prox = NULL;
    lista_aluno = NULL;
    primeiro_aluno = NULL;
}
Disciplina::Disciplina()
{
    nome = "";
    dep = NULL;
    prox = NULL;
    lista_aluno = NULL;
    primeiro_aluno = NULL;
}
string Disciplina::get_nome()
{
    return nome;
}
void Disciplina::adiciona_prox(Disciplina *d)
{
    prox = d;
}
Disciplina *Disciplina::get_prox()
{
    return prox;
}
void Disciplina::adiciona_dep(Departamento *d)
{
    dep = d;
}

void Disciplina::adiciona_aluno(Aluno *a)
{
    ElemAluno *aux;
    aux = new ElemAluno();
    aux->adiciona_aluno_apontado(a);
    if (lista_aluno == NULL)
    {
        primeiro_aluno = aux;
        lista_aluno = aux;
    }
    else
    {
        lista_aluno->adiciona_prox(aux);
        aux->adiciona_anterior(lista_aluno);
        lista_aluno = aux;
    }
}
void Disciplina::mostra_alunos()
{
    ElemAluno *aux;
    aux = primeiro_aluno;
    cout << "O nome dos alunos matriculados na disciplina " << nome << " são" << endl;
    while (aux != NULL)
    {
        cout << aux->get_nome() << endl;
        aux = aux->get_prox();
    }
}

Disciplina::~Disciplina()
{
    ElemAluno *aux1;
    ElemAluno *aux2;
    if (primeiro_aluno != NULL)
    {
        aux1 = primeiro_aluno;
        aux2 = primeiro_aluno->get_prox();
        while (aux2 != NULL)
        {
            delete aux1;
            aux1 = aux2;
            aux2 = aux2->get_prox();
        }
        delete aux1;
    }
}