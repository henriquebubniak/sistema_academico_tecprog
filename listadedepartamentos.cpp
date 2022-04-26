#include "listadedepartamentos.h"
#include "universidade.h"
#include "departamento.h"
#include "listadeuniversidades.h"
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
void ListaDeDepartamentos::remove_departamento(string n)
{
    ElemDep* aux;
    aux = primeiro_dep;
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
Departamento* ListaDeDepartamentos::localiza_dep(string n)
{
    ElemDep* aux = get_primeiro_dep();
    while(aux != NULL && aux->get_nome() != n)
    {
        aux = aux->get_prox();
    }
    if (aux != NULL)
        return aux->get_dep_apontado();
    else
        return NULL;    
}
void ListaDeDepartamentos::mostra_departamentos()
{
    ElemDep* aux;
    aux = primeiro_dep;
    cout << "Os departamentos listados no sistema são:" << endl;
    while(aux != NULL)
    {
        cout << aux->get_nome() << ", cadastrado na universidade " << aux->get_dep_apontado()->get_uni()->get_nome() << endl;
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
ElemDep* ListaDeDepartamentos::get_primeiro_dep()
{
    return primeiro_dep;
}
void ListaDeDepartamentos::gravar_dados()
{
    ofstream file;
    file.open("dados.csv", ios::app);
    ElemDep* auxdep;
    auxdep = primeiro_dep;
    while (auxdep != NULL)
    {
        file << 2 << "," << auxdep->get_dep_apontado()->get_uni()->get_nome() << "," << auxdep->get_nome() << endl;
        auxdep = auxdep->get_prox();
    } 
    file.close();
}
void ListaDeDepartamentos::recuperar_dados(ListaDeUniversidades* lista_unis)
{
    fstream file;
    file.open("dados.csv", ios:: in);
    int i;
    Departamento* auxdep = NULL;
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
        if(row[0] == "2")
        {
            auxdep = new Departamento(row[2]);
            auxdep->adiciona_uni(lista_unis->localiza_uni(row[1]));     
        }
        if(auxdep != NULL)
            adiciona_departamento(auxdep);
        auxdep = NULL;
    } 
}