#ifndef FUNCOES_IMPLEMENTAM_ESTUDANTES_COM_DISCIPLINAS_H_INCLUDED
#define FUNCOES_IMPLEMENTAM_ESTUDANTES_COM_DISCIPLINAS_H_INCLUDED

typedef Disciplina;
typedef Estudante;
Estudante *insereEstudante(Estudante *inicio,char *nomeEstudante,char *ra, char *nomePai,char *nomeMae);
Disciplina *insereDisciplina(Estudante *iniEstudantes,char *nomeEstudante,char *nomeDisciplina,int periodo, double creditos);

#endif // FUNCOES_IMPLEMENTAM_ESTUDANTES_COM_DISCIPLINAS_H_INCLUDED
