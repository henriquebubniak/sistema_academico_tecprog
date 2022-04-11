#include "aluno.h"
class ElemAluno
{
public:
    ElemAluno();
    void adiciona_prox(ElemAluno* a);
    void adiciona_anterior(ElemAluno* a);
    void adiciona_aluno_apontado(Aluno* a);
    void incrementa_faltas();
    void adiciona_nota_p1(float p);
    void adiciona_nota_p2(float p);
    void adiciona_nota_p3(float p);
    string get_nome();
    int get_faltas();
    ElemAluno* get_prox();
private:
    float p1;
    float p2;
    float p3;
    int n_faltas;
    ElemAluno* prox;
    ElemAluno* anterior;
    Aluno* aluno_apontado;
};