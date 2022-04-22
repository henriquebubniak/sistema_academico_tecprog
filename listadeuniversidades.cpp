#include "listadeuniversidades.h"
#include "universidade.h"
#include "departamento.h"
#include "elemdep.h"
void ListaDeUniversidades::adiciona_universidade(Universidade* u)
{
    ElemUni* aux;
    aux = new ElemUni();
    aux->adiciona_universidade_apontada(u);
    if (ultima_uni == NULL && primeira_uni == NULL)
    {
        ultima_uni = aux;
        primeira_uni = aux;
    }
    else
    {
        ultima_uni->adiciona_prox(aux);
        aux->adiciona_anterior(ultima_uni);
        ultima_uni = aux;
    }
}
void ListaDeUniversidades::remove_universidade(string n)
{
    ElemUni* aux;
    aux = primeira_uni;
    while(aux != NULL && aux->get_nome() != n){}
    if (aux == NULL)
        return;
    else
    {
        aux->get_anterior()->adiciona_prox(aux->get_prox());
        aux->get_prox()->adiciona_anterior(aux->get_anterior());
        delete aux;
    }
}

void ListaDeUniversidades::mostra_universidades()
{
    ElemUni* aux;
    aux = primeira_uni;
    cout << "As universidades listadas no sistema são:" << endl;
    while(aux != NULL)
    {
        cout << aux->get_nome() << endl;
        aux = aux->get_prox();
    }
}

ListaDeUniversidades::ListaDeUniversidades()
{
    ultima_uni = NULL;
    primeira_uni = NULL;
}

ListaDeUniversidades::~ListaDeUniversidades()
{
    if (primeira_uni != NULL)
    {
        ElemUni* aux1;
        ElemUni* aux2;
        aux1 = primeira_uni;
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
ElemUni* ListaDeUniversidades::get_primeira_uni()
{
    return primeira_uni;
}
