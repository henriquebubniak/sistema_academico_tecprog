#include "departamento.h"

Departamento::Departamento(string n)
{
    nome = n;
    lista_disc = NULL;
}
void Departamento::inicializa_dep(string n_dep)
{
    nome = n_dep;
}
string Departamento::get_nome()
{
    return nome;
}
void Departamento::adiciona_disciplina(Disciplina *d)
{
    d->adiciona_dep(this);
    ElemDisciplina *aux;
    aux = new ElemDisciplina();
    aux->adiciona_disciplina_apontada(d);
    ElemDisciplina *aux2;
    aux2 = lista_disc;
    if (lista_disc == NULL)
        lista_disc = aux;
    else
    {
        while (aux2->get_prox() != NULL)
            aux2 = aux2->get_prox();
        aux2->adiciona_prox(aux);
    }
}
void Departamento::mostra_disciplinas()
{
    ElemDisciplina *l = lista_disc;
    cout << "As disciplinas do departamento " << nome << " são:" << endl;
    while (l != NULL)
    {
        cout << l->get_nome() << endl;
        l = l->get_prox();
    }
}

void Departamento::remove_disciplina(string n)
{
    ElemDisciplina *l = lista_disc;
    ElemDisciplina *aux;
    ElemDisciplina *aux1;
    if (l->get_nome() == n)
    {
        aux1 = lista_disc;
        lista_disc = l->get_prox();
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