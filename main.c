#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/funcoes_implementam_estudantes_com_disciplinas.h"
#include "headers/funcoes_remocao_estudantes_disciplinas.h"
#include "headers/funcoes_mostrar_informacoes_estudantes.h"

/*
(a) 1 - Cadastrar estudante. OK
(b) 2 - Cadastrar disciplina. OK
(c) 3 - Mostrar somente os estudantes. OK
(d) 4 - Mostrar os estudantes com suas respectivas disciplinas. OK
(e) 5 - Mostrar os estudantes que est˜ao cursando apenas 1 disciplinas. OK
(f) 6 - Mostrar os estudantes que n˜ao cursam nenhuma disciplinas. OK
(g) 7 - Mostrar o estudante que possui a maior soma em cr´editos das disciplinas que
cursa. OK
(h) 8 - Desalocar todas as disciplinas. OK
(i) 9 - Desalocar todos os estudantes. (Lembre-se que um estudante s´o pode ser desalocado
se ele n˜ao tiver nenhuma disciplina).
(j) 10 - Desalocar TUDO - estudantes e disciplinas.
(k) 11 - Sair. (Antes de fechar o programa, tudo que foi alocado deve ser desalocado); OK

*/

int main()
{
    Estudante *iniEstudante = NULL;

    iniEstudante = insereEstudante(iniEstudante,"Gustavo","10...","Wanderley","Maira");
    iniEstudante = insereEstudante(iniEstudante,"Gabriel","7878...","Wanderley","Maira");
    iniEstudante = insereEstudante(iniEstudante,"Joe","3335...","Manoel","Manoela");
    iniEstudante = insereEstudante(iniEstudante,"Fabio","1015....","Joao","Juliana");
    iniEstudante = insereEstudante(iniEstudante,"Fabiana","787...","Jose","Ana Maria");

    iniEstudante = insereDisciplina(iniEstudante,"Gabriel","Estruturas de dados",
                                      2,85.55);
    iniEstudante = insereDisciplina(iniEstudante,"Joe","Banco de dados",
                                      3,76.55);
    iniEstudante = insereDisciplina(iniEstudante,"Gustavo","Programacao WEB 1",
                                      4,123.64);

    iniEstudante = insereDisciplina(iniEstudante,"Gabriel","Programacao WEB 2",
                                      4,12.55);

    iniEstudante = insereDisciplina(iniEstudante,"Gabriel","Programacao WEB 3",
                                      4,25.55);

    iniEstudante = removerTodasDisciplinas(iniEstudante);

    mostrarEstudantesSemDisciplinas(iniEstudante);

    return 0;
}
