#pragma once
#include <string>
using namespace std;

class Universidade
{
public:
    Universidade();
    Universidade(string n);
    string get_nome();
private:
    string nome;
};