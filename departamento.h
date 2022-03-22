#pragma once
#include <string>
using std::string;

class Departamento
{
public:
    Departamento(string n = "");
    void inicializa_dep(string n_dep);
    string get_nome();
private:
    string nome;
};