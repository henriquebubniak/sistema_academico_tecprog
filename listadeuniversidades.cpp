#include "listadeuniversidades.h"
#include "universidade.h"
#include "departamento.h"
#include "elemdep.h"
#include "elemuni.h"
#include <fstream>
#include<iostream>
#include <sstream>
using namespace std;
ListaDeUniversidades::ListaDeUniversidades()
{
    ultima_uni = NULL;
    primeira_uni = NULL;
}
ListaDeUniversidades::~ListaDeUniversidades()
{
    gravar_dados();
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
Universidade* ListaDeUniversidades::localiza_uni(string n)
{
    ElemUni* aux = get_primeira_uni();
    while(aux != NULL && aux->get_nome() != n)
    {
        aux = aux->get_prox();
    }
    if (aux != NULL)
        return aux->get_uni_apontada();
    else
        return NULL;    
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
ElemUni* ListaDeUniversidades::get_primeira_uni()
{
    return primeira_uni;
}
void ListaDeUniversidades::gravar_dados()
{
    fstream file;
    file.open("dados.csv", ios::out);
    ElemUni* auxuni;
    auxuni = primeira_uni;
    while (auxuni != NULL)
    {
        file << 1 << "," << auxuni->get_nome() << endl;
        auxuni = auxuni->get_prox();
    } 
    file.close();
}
void ListaDeUniversidades::recuperar_dados()
{
    fstream file;
    file.open("dados.csv", ios:: in);
    int i;
    string nome;
    string atributo;
    string aux, linha;
    vector<string> row;
    while (file >> linha)
    {
        row.clear();
        stringstream s(linha);
        while(getline(s, atributo, ','))
            row.push_back(atributo);
        if(row[0] == "1")
        {
            Universidade* auxuni = new Universidade(row[1]);
            adiciona_universidade(auxuni);
        }
    } 


}
