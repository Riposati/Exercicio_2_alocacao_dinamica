#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct disciplina{

    char nomeDisciplina[50];
    int periodo;
    double creditos;
    struct disciplina *prox;

}typedef Disciplina;

struct estudante{

    char nomeEstudante[50];
    char RA[15];
    char nomePai[50];
    char nomeMae[50];
    struct estudante *prox;
    Disciplina *disciplina;

}typedef Estudante;

void mostrarAluno(Estudante *ini){

    Estudante *aux = ini;

    printf("\n\n********** Mostra todos estudantes **********\n\n\n");

    while(aux!=NULL){

        printf("nome do estudante = %s\n",aux->nomeEstudante);
        printf("RA do estudante = %s\n",aux->RA);
        printf("nome do pai do estudante = %s\n",aux->nomePai);
        printf("nome da mae do estudante = %s\n",aux->nomeMae);
        printf("\n");
        aux = aux->prox;
    }
}

void mostrarEstudantesEDisciplinas(Estudante *inicioAlunos){

    Estudante *aux = inicioAlunos;

    printf("\n\n********** Mostra estudantes e disciplinas **********\n\n\n");

    while(aux!=NULL){

        printf("ALUNO : %s\n",aux->nomeEstudante);
        printf("Disciplinas deste aluno:\n");
        if(aux->disciplina!=NULL){

            printf("\n-----------------------------------------\n");

            Disciplina *auxDisciplinas = aux->disciplina;

            while(auxDisciplinas!=NULL){

                printf("nome da disciplina = %s\n",auxDisciplinas->nomeDisciplina);
                printf("periodo da disciplina = %d\n",auxDisciplinas->periodo);
                printf("creditos da disciplina = %lf\n",auxDisciplinas->creditos);
                printf("\n");
                auxDisciplinas = auxDisciplinas->prox;
            }

            printf("\n-----------------------------------------\n");
        }else{

            printf("Aluno sem disciplinas cadastradas\n");
        }

        aux = aux->prox;
    }
}

void mostrarEstudantesComUmaDisciplina(Estudante *inicioAlunos){

    Estudante *aux = inicioAlunos;

    printf("\n\n********** Mostra estudantes com 1 disciplina cadastrada **********\n\n\n");

    while(aux!=NULL){

        printf("ALUNO : %s\n",aux->nomeEstudante);
        printf("Disciplinas deste aluno:\n");
        if(aux->disciplina!=NULL && aux->disciplina->prox==NULL){

            printf("\n-----------------------------------------\n");

            Disciplina *auxDisciplinas = aux->disciplina;

            while(auxDisciplinas!=NULL){

                printf("nome da disciplina = %s\n",auxDisciplinas->nomeDisciplina);
                printf("periodo da disciplina = %d\n",auxDisciplinas->periodo);
                printf("creditos da disciplina = %lf\n",auxDisciplinas->creditos);
                printf("\n");
                auxDisciplinas = auxDisciplinas->prox;
            }

            printf("\n-----------------------------------------\n");
        }else{

            printf("\nAluno tem mais de 1 disciplina cadastrada\n");
        }

        aux = aux->prox;
    }
}

void mostrarEstudantesSemDisciplinas(Estudante *inicioAlunos){

    Estudante *aux = inicioAlunos;

    printf("\n\n********** Mostra estudantes sem disciplinas cadastradas **********\n\n\n");

    while(aux!=NULL){

        if(aux->disciplina!=NULL){

            printf("\nAluno %s tem mais de 1 disciplina cadastrada\n",aux->nomeEstudante);
        }else{
            printf("\nALUNO SEM DISCIPLINAS : %s\n",aux->nomeEstudante);
        }

        aux = aux->prox;
    }
}

void mostrarEstudantesComMaiorCredito(Estudante *inicioAlunos){

    Estudante *aux = inicioAlunos;
    double maiorEmCreditos = 0;
    double maior = 0;
    double maiorAux=0;
    char nomeEstudante[50];

    printf("\n\n********** Mostra estudante com maior creditos **********\n\n\n");

    if(aux!=NULL){

        strcpy(nomeEstudante,aux->nomeEstudante);
    }

    while(aux!=NULL){

        if(aux->disciplina!=NULL){ /// se esse estudante possuir disciplinas

            Disciplina *auxDisciplinas = aux->disciplina;

            while(auxDisciplinas!=NULL){

                maiorEmCreditos += auxDisciplinas->creditos;

                auxDisciplinas = auxDisciplinas->prox;
            }

            if(maior > maiorAux){

                maiorAux = maior;

            }

            maior = maiorEmCreditos;

            if(maiorAux < maior){

                strcpy(nomeEstudante,aux->nomeEstudante);
            }
        }

        aux = aux->prox;
        maiorEmCreditos = 0;
    }

    printf("nome do estudante com maior soma em creditos = %s\n",nomeEstudante);
}
