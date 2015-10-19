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

Estudante *insereEstudante(Estudante *inicio,char *nomeEstudante,char *ra, char *nomePai,char *nomeMae){

    Estudante *auxiliar = (Estudante *)malloc(sizeof(Estudante));

    printf("\n\n********** Insere estudantes **********\n\n\n");

    strcpy(auxiliar->nomeEstudante,nomeEstudante);
    strcpy(auxiliar->RA,ra);
    strcpy(auxiliar->nomePai,nomePai);
    strcpy(auxiliar->nomeMae,nomeMae);
    auxiliar->prox = NULL;
    auxiliar->disciplina = NULL;

    if(inicio==NULL){

        inicio = auxiliar;
    }else{

        Estudante *ultimo = inicio;

        while(ultimo->prox!=NULL){

            ultimo = ultimo->prox;
        }
        ultimo->prox = auxiliar;
    }

    return inicio;
}

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

Disciplina *insereDisciplina(Estudante *iniEstudantes,char *nomeEstudante,Disciplina *inicioDisciplinas,char *nomeDisciplina,int periodo, double creditos){

    Estudante *auxEstudantes = iniEstudantes;

    printf("\n\n********** Insere disciplinas **********\n\n\n");

    while(auxEstudantes!=NULL && strcmp(auxEstudantes->nomeEstudante,nomeEstudante)!=0){

        auxEstudantes = auxEstudantes->prox;
    }

    if(auxEstudantes!=NULL){ /// existe o estudante pra receber a disciplina

        Disciplina *auxiliar = (Disciplina *)malloc(sizeof(Disciplina));

        strcpy(auxiliar->nomeDisciplina,nomeDisciplina);
        auxiliar->periodo = periodo;
        auxiliar->creditos = creditos;
        auxiliar->prox = NULL;

        if(auxEstudantes->disciplina==NULL){

            auxEstudantes->disciplina = auxiliar;
        }else{

            Disciplina *ult = auxEstudantes->disciplina;

            while(ult->prox!=NULL){

                ult = ult->prox;
            }
            ult->prox = auxiliar;
        }

    }else{

        printf("\n\nEstudante %s nao existe\n\n",nomeEstudante);
    }

    return iniEstudantes;
}

void mostrarEstudantesEDisciplinas(Estudante *inicioAlunos,Disciplina *ini){

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

void mostrarEstudantesComUmaDisciplina(Estudante *inicioAlunos,Disciplina *ini){

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

void mostrarEstudantesSemDisciplinas(Estudante *inicioAlunos,Disciplina *ini){

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

void mostrarEstudantesComMaiorCredito(Estudante *inicioAlunos,Disciplina *ini){

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
