#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/funcoes_implementam_estudantes_com_disciplinas.h"
#include "headers/funcoes_remocao_estudantes_disciplinas.h"
#include "headers/funcoes_mostrar_informacoes_estudantes.h"
#include <locale.h>

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
se ele n˜ao tiver nenhuma disciplina). OK
(j) 10 - Desalocar TUDO - estudantes e disciplinas. OK
(k) 11 - Sair. (Antes de fechar o programa, tudo que foi alocado deve ser desalocado); OK

*/

lerEspacoTeclado(){

    scanf("\n"); // ler espaço teclado
}

int main()
{

    setlocale(LC_ALL, "Portuguese");

    Estudante *iniEstudante = NULL;
    int opMenu;
    char nomeEstudante[50];
    char nomePai[50];
    char nomeMae[50];
    char nomeDisciplina[50];
    char ra[15];
    int periodo;
    double creditos;

    do{
        printf("SISTEMA DE ALUNOS E LISTA DE DISCIPLINAS\n");
        printf("1 e enter - Cadastrar estudante\n");
        printf("2 e enter - Cadastrar disciplina para um estudante\n");
        printf("3 e enter - Mostrar somente os estudantes\n");
        printf("4 e enter - Mostrar os estudantes com suas respectivas disciplinas\n");
        printf("5 e enter - Mostrar os estudantes que estão cursando apenas 1 disciplinas\n");
        printf("6 e enter - Mostrar os estudantes que não cursam nenhuma disciplinas\n");
        printf("7 e enter - Mostrar o estudante com a maior soma em creditos das disciplinas\n");
        printf("8 e enter - Desalocar todas as disciplinas\n");
        printf("9 e enter - Desalocar todos os estudantes. (Lembre-se que um estudante só pode ser desalocado se ele n˜ao tiver nenhuma disciplina)\n");
        printf("10 e enter - Desalocar TUDO - estudantes e disciplinas\n");
        printf("11 e enter - Limpar a tela\n");
        printf("12 e enter - Sair\n");

        scanf("%d",&opMenu);
        fflush(stdin);

        switch(opMenu){

            case 1:
                printf("informe o nome do estudante e tecle enter\n");
                gets(nomeEstudante);
                //lerEspacoTeclado();

                printf("informe o RA do estudante e tecle enter\n");
                gets(ra);
                //lerEspacoTeclado();

                printf("informe o nome do pai do estudante e tecle enter\n");
                gets(nomePai);
                //lerEspacoTeclado();

                printf("informe o nome da mae do estudante e tecle enter\n");
                gets(nomeMae);
                //lerEspacoTeclado();

                iniEstudante = insereEstudante(iniEstudante,nomeEstudante,ra,nomePai,nomeMae);
                break;

            case 2:

                printf("informe o nome do estudante que tera a disciplina e tecle enter\n");
                gets(nomeEstudante);
                //lerEspacoTeclado();

                printf("informe o nome da disciplina e tecle enter\n");
                gets(nomeDisciplina);
                //lerEspacoTeclado();

                printf("digite o periodo da disciplina e tecle enter\n");
                scanf(" %d",&periodo);

                printf("digite os creditos da disciplina e tecle enter\n");
                scanf("%lf",&creditos);

                iniEstudante = insereDisciplina(iniEstudante,nomeEstudante,nomeDisciplina
                                                ,periodo,creditos);
                break;

            case 3:
                mostrarAluno(iniEstudante);
                break;

            case 4:
                mostrarEstudantesEDisciplinas(iniEstudante);
                break;

            case 5:
                mostrarEstudantesComUmaDisciplina(iniEstudante);
                break;

            case 6:
                mostrarEstudantesSemDisciplinas(iniEstudante);
                break;

            case 7:
                mostrarEstudantesComMaiorCredito(iniEstudante);
                break;

            case 8:
                iniEstudante = removerTodasDisciplinas(iniEstudante);
                break;

            case 9:
                iniEstudante = removerTodosAlunos(iniEstudante);
                break;

            case 10:
                iniEstudante = removeTudo(iniEstudante);
                break;

            case 11:
                system("cls");
                break;
        }

    fflush(stdin);

    }while(opMenu!=12);

    return 0;
}
