#include "principal.h"
#include "elemdisciplina.h"

Principal::Principal()
{
    get_data_int(&diaA, &mesA, &anoA);
    menu();
}
Principal::~Principal()
{

}
void Principal::menu()
{
    int op;
    system("clear");
    cout << "1 - Cadastrar" << endl;
    cout << "2 - Ler" << endl;
    cout << "3 - Sair" << endl;
    cin >> op;
    switch (op)
    {
    case 1:
        menu_cadastro();
        break;
    case 2:
        menu_leitura();
        break;
    case 3:
        exit(1);
    default:
        cout << "Opção inválida" << endl;
        break;
    }
}
void Principal::menu_cadastro()
{
    int op;
    system("clear");
    cout << "1 - Universidade" << endl;
    cout << "2 - Departamento" << endl;
    cout << "3 - Disciplina" << endl;
    cout << "4 - Aluno" << endl;
    cout << "5 - Sair" << endl;

    cin >> op;
    switch (op)
    {
    case 1:
        cadastro_universidade();
        break;
    case 2:
        cadastro_departamento();
        break;
    case 3:
        cadastro_disciplina();
        break;
    case 4:
        cadastro_aluno();
        break;
    case 5:
        exit(1);
    default:
        break;
    }
}
void Principal::cadastro_universidade()
{
    string nome_uni;
    system("clear");
    cout << "insira o nome da universidade." << endl;
    cin >> nome_uni;
    Universidade* aux;
    aux = new Universidade(nome_uni);
    lista_unis.adiciona_universidade(aux);
    system("clear");
    cout << "sucesso. pressione qualquer tecla para voltar ao menu." << endl;
    getchar();
    getchar();
    menu();
}
void Principal::cadastro_departamento()
{
    string nome_dep;
    string nome_uni;
    Universidade* aux_uni;
    Departamento* aux_dep;
    system("clear");
    cout << "insira o nome do departamento." << endl;
    cin >> nome_dep;
    cout << "insira o nome da universidade a qual o departamento pertence." << endl;
    cin >> nome_uni;
    aux_dep = new Departamento(nome_dep);
    aux_uni = localiza_uni(nome_uni);
    if (aux_uni != NULL)
    {
        aux_uni->adiciona_dep(aux_dep);
        lista_deps.adiciona_departamento(aux_dep);
        cout << "sucesso. pressione qualquer tecla para voltar ao menu." << endl;
    }
    else
    {
        cout << "universidade não encontrada. pressione qualquer tecla para voltar ao menu." << endl;
    }
    getchar();
    getchar();
    menu();
}
void Principal::cadastro_disciplina()
{
    string nome_disc;
    string nome_dep;
    Departamento* aux_dep;
    Disciplina* aux_disc;
    system("clear");
    cout << "insira o nome da disciplina." << endl;
    cin >> nome_disc;
    cout << "insira o nome do departamento a qual a disciplina pertence." << endl;
    cin >> nome_dep;
    aux_disc = new Disciplina(nome_disc);
    aux_dep = localiza_dep(nome_dep);
    if (aux_dep != NULL)
    {
        aux_dep->adiciona_disciplina(aux_disc);
        lista_discs.adiciona_disciplina(aux_disc);
        cout << "sucesso. pressione qualquer tecla para voltar ao menu." << endl;
    }
    else
    {
        cout << "departamento não encontrada. pressione qualquer tecla para voltar ao menu." << endl;
    }
    getchar();
    getchar();
    menu();
}
void Principal::menu_leitura()
{
    int op;
    int i = 1;
    int j = 1;
    ElemUni* aux_uni;
    aux_uni = lista_unis.get_primeira_uni();
    system("clear");
    while(aux_uni != NULL)
    {
        cout << i << " - " << aux_uni->get_nome() << endl;
        i++;
        aux_uni = aux_uni->get_prox();
    }    
    cout << i << " - Sair" << endl;
    cin >> op;
    aux_uni = lista_unis.get_primeira_uni();
    while(j != op)
    {
        aux_uni = aux_uni->get_prox();
        j++;
    }
    aux_uni->get_uni_apontada()->mostra_deps();   
    getchar();
    getchar(); 
    menu_leitura();
}


void Principal::cadastro_aluno()
{
    int op;
    system("clear");
    cout << "1 - cadastrar um novo aluno" << endl;
    cout << "2 - cadastrar um aluno existente em uma disciplina" << endl;
    cin >> op;
    switch (op)
    {
    case 1:
        cadastro_aluno_novo();
        break;
    case 2:
        cadastro_aluno_em_disc();
        break;
    default:
        cout << "Opção inválida" << endl;
        break;
    }
}
void Principal::cadastro_aluno_novo()
{
    int op;
    string nome_aluno;
    string nome_uni;
    int diaN;
    int mesN;
    int anoN;
    Universidade* aux_uni;
    Aluno* aux_aluno;
    system("clear");
    cout << "insira o nome do aluno." << endl;
    cin.ignore();
    getline(cin, nome_aluno);
    cout << "insira a data de nascimento." << endl;
    scanf("%d/%d/%d", &diaN, &mesN, &anoN);
    cout << "insira o nome da universidade a qual o aluno pertence." << endl;
    cin >> nome_uni;
    aux_aluno = new Aluno(nome_aluno, diaN, mesN, anoN);
    //aux_aluno->set_ra(lista_alunos.get_quant_alunos());
    aux_uni = localiza_uni(nome_uni);
    if (aux_uni != NULL)
    {
        aux_uni->adiciona_aluno(aux_aluno);
        lista_alunos.adiciona_aluno(aux_aluno);
        aux_aluno->associa_uni(aux_uni);
        cout << "sucesso. deseja cadastra-lo em alguma disciplina?." << endl;
        cout << "1 - sim" << endl;
        cout << "2 - nao" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            cadastro_aluno_em_disc(aux_aluno);
            break;        
        default:
            break;
        }
    }
    else
    {
        cout << "universidade não encontrada. pressione qualquer tecla para voltar ao menu." << endl;
    }
    getchar();
    getchar();
    menu();    
}
void Principal::cadastro_aluno_em_disc()
{

}
void Principal::cadastro_aluno_em_disc(Aluno* a)
{
    string nome_disc;
    Disciplina* aux_disc;
    system("clear");
    cout << "insira o nome da disciplina em que deseja cadastrar o aluno" << endl;
    cin.ignore();
    getline(cin, nome_disc);
    aux_disc = localiza_disc(nome_disc);
    system("clear");
    if (aux_disc != NULL)
    {
        aux_disc->adiciona_aluno(a);
        cout << "sucesso. pressione qualquer tecla para voltar ao menu" << endl;
    }
    else
        cout << "disciplina não encontrada. aluno nao foi cadastrado em nenhuma disciplina. pressione qualquer tecla para voltar ao menu" << endl;
    getchar();
    menu();
}
Universidade* Principal::localiza_uni(string n)
{
    ElemUni* aux = lista_unis.get_primeira_uni();
    while(aux != NULL && aux->get_nome() != n)
    {
        aux = aux->get_prox();
    }
    if (aux != NULL)
        return aux->get_uni_apontada();
    else
        return NULL;    
}
Departamento* Principal::localiza_dep(string n)
{
    ElemDep* aux = lista_deps.get_primeiro_dep();
    while(aux != NULL && aux->get_nome() != n)
    {
        aux = aux->get_prox();
    }
    if (aux != NULL)
        return aux->get_dep_apontado();
    else
        return NULL;    
}
Disciplina* Principal::localiza_disc(string n)
{
    ElemDisciplina* aux = lista_discs.get_primeira_disc();
    while(aux != NULL && aux->get_nome() != n)
    {
        aux = aux->get_prox();
    }
    if (aux != NULL)
        return aux->get_disciplina_apontada();
    else
        return NULL;      
}