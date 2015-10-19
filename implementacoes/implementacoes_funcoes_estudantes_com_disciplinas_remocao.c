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

Estudante *removerTodasDisciplinas(Estudante *ini){

    Estudante *auxiliador = ini;
    Disciplina *auxiliadorDisciplinas=NULL;
    Disciplina *auxiliadorDisciplinasAtras=NULL;

    while(auxiliador!=NULL){

        if(auxiliador->disciplina!=NULL){

            auxiliadorDisciplinas = auxiliador->disciplina; /// mesma coisa de dizer, aux = ini

            while(auxiliadorDisciplinas!=NULL){

                auxiliadorDisciplinasAtras = auxiliadorDisciplinas;

                auxiliadorDisciplinas = auxiliadorDisciplinas->prox;

                auxiliador->disciplina = auxiliadorDisciplinas;

                free(auxiliadorDisciplinasAtras);
            }
        }

        auxiliador = auxiliador->prox;
    }

    return ini;
}

Estudante *removerTodosAlunos(Estudante *ini){

    Estudante *auxiliador = ini;
    Estudante *auxiliadorDeTraz = NULL;

    ini = removerTodasDisciplinas(ini);

    while(auxiliador!=NULL){

        auxiliadorDeTraz = ini;
        ini = auxiliador->prox;
        auxiliador = ini;
        free(auxiliadorDeTraz);
    }

    return ini;
}

Estudante *removeTudo(Estudante *ini){
    ini = removerTodosAlunos(ini);
    return ini;
}
