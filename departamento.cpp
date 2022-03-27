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
    Disciplina *l = lista_disc;
    if (l == NULL)
        lista_disc = d;
    else
    {
        while (l->get_prox() != NULL)
            l = l->get_prox();
        l->adiciona_prox(d);
    }
}
void Departamento::mostra_disciplinas()
{
    Disciplina *l = lista_disc;
    cout << "As disciplinas do departamento " << nome << " são:" << endl;
    while (l != NULL)
    {
        cout << l->get_nome() << endl;
        l = l->get_prox();
    }
}

void Departamento::remove_disciplina(string n)
{
    Disciplina *l = lista_disc;
    if (l->get_nome() == n)
        lista_disc = l->get_prox();
    else
    {
        while (l->get_prox() != NULL && l->get_prox()->get_nome() != n)
        {
            l = l->get_prox();
        }
    }
    if (l->get_prox())
        if (l->get_prox()->get_nome() == n)
            l->adiciona_prox(l->get_prox()->get_prox());
}