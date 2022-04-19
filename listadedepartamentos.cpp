#include "listadedepartamentos.h"
#include "universidade.h"
#include "departamento.h"
#include "elemdep.h"
void ListaDeDepartamentos::inicializa_universidade(Universidade* u)
{
    primeiro_dep = NULL;
    ultimo_dep = NULL;
    universidade = u;
}
void ListaDeDepartamentos::adiciona_departamento(Departamento* d)
{
    ElemDep* aux;
    aux = new ElemDep();
    aux->adiciona_departamento_apontado(d);
    if (ultimo_dep == NULL && primeiro_dep == NULL)
    {
        ultimo_dep = aux;
        primeiro_dep = aux;
    }
    else
    {
        ultimo_dep->adiciona_prox(aux);
        aux->adiciona_anterior(ultimo_dep);
        ultimo_dep = aux;
    }
}
/*void ListaDeDepartamentos::remove_departamento(string n)
{
    ElemDep* aux;
    aux = primeiro_dep;
    while(aux != NULL && aux->get_nome() != n){}
    if (aux == NULL)
        exit(1);
    else
    {
        aux->get_anterior()->adiciona_prox(aux->get_prox());
        aux->get_prox()->adiciona_anterior(aux->get_anterior());
        delete aux;
    }
}*/

void ListaDeDepartamentos::mostra_departamentos()
{
    ElemDep* aux;
    aux = primeiro_dep;
    cout << "Os departamentos listados na universidade " << universidade->get_nome() << " são:" << endl;
    while(aux != NULL)
    {
        cout << aux->get_nome() << endl;
        aux = aux->get_prox();
    }
}

ListaDeDepartamentos::ListaDeDepartamentos(Universidade* u)
{
    ultimo_dep = NULL;
    primeiro_dep = NULL;
    universidade = u;
}

ListaDeDepartamentos::~ListaDeDepartamentos()
{
    if (primeiro_dep != NULL)
    {
        ElemDep* aux1;
        ElemDep* aux2;
        aux1 = primeiro_dep;
        aux2 = aux1->get_prox();
        while(aux2 != NULL)
        {
            delete aux1;
            aux1 = aux2;
            aux2 = aux2->get_prox();
        }
        delete aux1;        
    }
}
