#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/funcoes_implementam_estudantes_com_disciplinas.h"

int main()
{
    Estudante *iniEstudante = NULL;
    Disciplina *iniDisciplinas = NULL;

    iniEstudante = insereEstudante(iniEstudante,"Gustavo","10...","Wanderley","Maira");
    iniEstudante = insereEstudante(iniEstudante,"Gabriel","7878...","Wanderley","Maira");
    iniEstudante = insereEstudante(iniEstudante,"Joe","3335...","Manoel","Manoela");
    iniEstudante = insereEstudante(iniEstudante,"Fabio","1015....","Joao","Juliana");
    iniEstudante = insereEstudante(iniEstudante,"Fabiana","787...","Jose","Ana Maria");

    iniEstudante = insereDisciplina(iniEstudante,"Gabriel",iniDisciplinas,"Estruturas de dados",
                                      2,85.55);
    iniEstudante = insereDisciplina(iniEstudante,"Joe",iniDisciplinas,"Banco de dados",
                                      3,76.55);
    iniEstudante = insereDisciplina(iniEstudante,"Gustavo",iniDisciplinas,"Programacao WEB 1",
                                      4,123.64);

    iniEstudante = insereDisciplina(iniEstudante,"Gabriel",iniDisciplinas,"Programacao WEB 2",
                                      4,12.55);

    iniEstudante = insereDisciplina(iniEstudante,"Gabriel",iniDisciplinas,"Programacao WEB 3",
                                      4,25.55);

    mostrarEstudantesComMaiorCredito(iniEstudante,iniDisciplinas);

    mostrarEstudantesEDisciplinas(iniEstudante,iniDisciplinas);

    return 0;
}
