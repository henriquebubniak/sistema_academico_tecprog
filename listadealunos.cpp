#include "listadealunos.h"
#include "disciplina.h"
void ListaDeAlunos::incrementa_faltas(string n)
{
    ElemAluno *aux;
    aux = primeiro_aluno;
    while (aux->get_nome() != n && aux != NULL)
    {
        aux = aux->get_prox();
    }
    if (aux->get_nome() == n)
        aux->incrementa_faltas();
}
void ListaDeAlunos::adiciona_nota_p1(string n, float p)
{
    ElemAluno *aux;
    aux = primeiro_aluno;
    while (aux->get_nome() != n && aux != NULL)
    {
        aux = aux->get_prox();
    }
    if (aux->get_nome() == n)
        aux->adiciona_nota_p1(p);
}
void ListaDeAlunos::adiciona_nota_p2(string n, float p)
{
    ElemAluno *aux;
    aux = primeiro_aluno;
    while (aux->get_nome() != n && aux != NULL)
    {
        aux = aux->get_prox();
    }
    if (aux->get_nome() == n)
        aux->adiciona_nota_p2(p);
}
void ListaDeAlunos::adiciona_nota_p3(string n, float p)
{
    ElemAluno *aux;
    aux = primeiro_aluno;
    while (aux->get_nome() != n && aux != NULL)
    {
        aux = aux->get_prox();
    }
    if (aux->get_nome() == n)
        aux->adiciona_nota_p3(p);
}
ListaDeAlunos::ListaDeAlunos()
{
    lista_aluno = NULL;
    primeiro_aluno = NULL;
    disciplina = NULL;
}
ListaDeAlunos::ListaDeAlunos(Disciplina* d)
{
    lista_aluno = NULL;
    primeiro_aluno = NULL;
    disciplina = d;
}
ListaDeAlunos::~ListaDeAlunos()
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

void ListaDeAlunos::adiciona_aluno(Aluno* a)

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

void ListaDeAlunos::mostra_alunos()
{
    ElemAluno *aux;
    aux = primeiro_aluno;
    cout << "O nome dos alunos matriculados na disciplina " << disciplina->get_nome() << " são" << endl;
    while (aux != NULL)
    {
        cout << aux->get_nome() << endl;
        aux = aux->get_prox();
    }
}

void ListaDeAlunos::inicializa_disciplina(Disciplina* d)
{
    disciplina = d;
}
