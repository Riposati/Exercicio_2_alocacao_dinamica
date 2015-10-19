#ifndef FUNCOES_IMPLEMENTAM_ESTUDANTES_COM_DISCIPLINAS_H_INCLUDED
#define FUNCOES_IMPLEMENTAM_ESTUDANTES_COM_DISCIPLINAS_H_INCLUDED

typedef Disciplina;
typedef Estudante;
Estudante *insereEstudante(Estudante *inicio,char *nomeEstudante,char *ra, char *nomePai,char *nomeMae);
void mostrarAluno(Estudante *ini);
Disciplina *insereDisciplina(Estudante *iniEstudantes,char *nomeEstudante,Disciplina *inicioDisciplinas,char *nomeDisciplina,int periodo, double creditos);
void mostrarEstudantesEDisciplinas(Estudante *inicioAlunos,Disciplina *ini);
void mostrarEstudantesComUmaDisciplina(Estudante *inicioAlunos,Disciplina *ini);
void mostrarEstudantesSemDisciplinas(Estudante *inicioAlunos,Disciplina *ini);
void mostrarEstudantesComMaiorCredito(Estudante *inicioAlunos,Disciplina *ini);

#endif // FUNCOES_IMPLEMENTAM_ESTUDANTES_COM_DISCIPLINAS_H_INCLUDED
