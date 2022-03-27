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
void Departamento::adiciona_disciplina(Disciplina* d)
{
    Disciplina* l = lista_disc;
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
    Disciplina* l = lista_disc;
    cout << "As disciplinas do departamento " << nome << " são:" << endl;
    while (l != NULL)
    {
        cout << l->get_nome() << endl;
        l = l->get_prox();
    }    
}