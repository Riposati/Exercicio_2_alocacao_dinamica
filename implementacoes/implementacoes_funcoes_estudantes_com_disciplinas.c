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

Disciplina *insereDisciplina(Estudante *iniEstudantes,char *nomeEstudante,char *nomeDisciplina,int periodo, double creditos){

    Estudante *auxEstudantes = iniEstudantes;

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
