#include "listadedisciplinas.h"
#include "elemdisciplina.h"
#include "departamento.h"
#include "disciplina.h"
void ListaDeDisciplinas::inicializa_departamento(Departamento *d)
{
    ultima_disc = NULL;
    primeira_disc = NULL;
    departamento = d;
}
void ListaDeDisciplinas::adiciona_disciplina(Disciplina *d)
{
    ElemDisciplina *aux;
    aux = new ElemDisciplina();
    aux->adiciona_disciplina_apontada(d);
    if (ultima_disc->get_nome() == "")
    {
        primeira_disc = aux;
        ultima_disc = aux;
    }
    else
    {
        ultima_disc->adiciona_prox(aux);
        aux->adiciona_anterior(ultima_disc);
        ultima_disc = aux;
    }
}
void ListaDeDisciplinas::remove_disciplina(string n)
{
    ElemDisciplina *l = ultima_disc;
    ElemDisciplina *aux;
    ElemDisciplina *aux1;
    if (l->get_nome() == n)
    {
        aux1 = ultima_disc;
        ultima_disc = l->get_prox();
        delete aux1;
    }
    else
    {
        while (l->get_prox() != NULL && l->get_prox()->get_nome() != n)
        {
            l = l->get_prox();
        }

        if (l->get_prox())
        {
            aux = l->get_prox()->get_prox();
            delete l->get_prox();
            l->adiciona_prox(aux);
        }
    }
}
void ListaDeDisciplinas::mostra_disciplinas()
{
    ElemDisciplina *aux;
    aux = primeira_disc;
    cout << "O nome das disciplinas cadastradas no departamento " << departamento->get_nome() << " são" << endl;
    while (aux != NULL)
    {
        cout << aux->get_nome() << endl;
        aux = aux->get_prox();
    }
}
ListaDeDisciplinas::ListaDeDisciplinas(Departamento *d)
{
    ultima_disc = NULL;
    primeira_disc = NULL;
    departamento = d;
}
ListaDeDisciplinas::~ListaDeDisciplinas()
{
    ElemDisciplina *aux1;
    ElemDisciplina *aux2;
    if (primeira_disc != NULL)
    {
        aux1 = primeira_disc;
        aux2 = primeira_disc->get_prox();
        while (aux2 != NULL)
        {
            delete aux1;
            aux1 = aux2;
            aux2 = aux2->get_prox();
        }
        delete aux1;
    }
}