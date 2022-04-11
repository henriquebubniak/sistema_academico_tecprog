#include "aluno.h"
class ElemAluno
{
public:
    ElemAluno();
    void adiciona_prox(ElemAluno* a);
    void adiciona_anterior(ElemAluno* a);
    void adiciona_aluno_apontado(Aluno* a);
    string get_nome();
    ElemAluno* get_prox();
private:
    ElemAluno* prox;
    ElemAluno* anterior;
    Aluno* aluno_apontado;
};