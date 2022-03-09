#include <stdio.h>

class Pessoa
{
public:
    Pessoa (const char* n, int d, int m, int a);
    void calcula_idade(int diaA, int mesA, int anoA);
    void mostra_idade();

private:
    const char *nome;
    unsigned diaN;
    unsigned mesN;
    unsigned anoN;
    unsigned idade;  
};