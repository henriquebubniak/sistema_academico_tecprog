#include "principal.h"
#include "elemdisciplina.h"

Principal::Principal()
{
    get_data_int(&diaA, &mesA, &anoA);
    recuperar_dados();
    menu();
}
Principal::~Principal()
{
    lista_unis.gravar_dados();
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
        gravar_dados();
        exit(0);
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
void Principal::menu_leitura()
{
    int op;
    system("clear");
    cout << "1 - ler universidades no sistema" << endl;
    cout << "2 - ler departamentos no sistema" << endl;
    cout << "3 - ler disciplinas no sistema" << endl;
    cout << "4 - ler alunos no sistema" << endl;
    cin >> op;
    switch (op)
    {
    case 1:
        le_universidades();
        break;
    case 2:
        le_departamentos();
        break;
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
    aux_uni = lista_unis.localiza_uni(nome_uni);
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
    aux_dep = lista_deps.localiza_dep(nome_dep);
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
    aux_uni = lista_unis.localiza_uni(nome_uni);
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
    aux_disc = lista_discs.localiza_disc(nome_disc);
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
void Principal::le_universidades()
{
    int op;
    string nome_uni;
    system("clear");
    lista_unis.mostra_universidades();
    cout << "1 - ler alunos cadastrados em uma universidade" << endl;
    cout << "2 - ler departamentos cadastrados em uma universidade" << endl;
    cout << "3 - voltar ao menu principal" << endl;
    cin >> op;
    switch (op)
    {
    case 1:
        system("clear");
        cout << "digite o nome da universidade." << endl;
        cin >> nome_uni;
        lista_unis.localiza_uni(nome_uni)->mostra_alunos();
        break;
    
    default:
        break;
    }
}
void Principal::le_departamentos()
{
   int op;
    string nome_dep;
    system("clear");
    lista_deps.mostra_departamentos();
    cout << "1 - ler disciplinas cadastrados em um departamento" << endl;
    cout << "2 - ler departamentos cadastrados em uma universidade" << endl;
    cout << "3 - voltar ao menu principal" << endl;
    cin >> op;
    switch (op)
    {
    case 1:
        system("clear");
        cout << "digite o nome da departamento." << endl;
        cin >> nome_dep;
        lista_deps.localiza_dep(nome_dep)->mostra_disciplinas();
        break;
    case 3:
        menu();    
    default:
        break;
    } 
}
void Principal::gravar_dados()
{
    lista_unis.gravar_dados();
    lista_deps.gravar_dados();
}
void Principal::recuperar_dados()
{
    lista_unis.recuperar_dados();
    lista_deps.recuperar_dados(&lista_unis);
}