#include "disciplina.h"
class ElemDisciplina
{
public:
    ElemDisciplina();
    void adiciona_prox(ElemDisciplina* a);
    void adiciona_disciplina_apontada(Disciplina* a);
    string get_nome();
    ElemDisciplina* get_prox();
private:
    ElemDisciplina* prox;
    Disciplina* disciplina_apontada;
};