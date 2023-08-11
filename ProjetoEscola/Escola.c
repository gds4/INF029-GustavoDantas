#include <stdio.h>
#include <stdlib.h>
#define Tam_Nome 100
#define Tam_Data 10

typedef struct {
  int Matricula;
  int Nome[Tam_Nome];
  char Sexo;
  int Cpf;
  int DataNasc[Tam_Data];
} Aluno;

typedef struct {
  int Matricula;
  char Nome[Tam_Nome];
  char Sexo;
  char DataNasc[Tam_Data];
  int CPF;
} Professor;

int main(void) {
  int TeladeInicio;
  int InicioCont = 0;
  int MenuInicial;
  int MenuAluno;
  int MenuProfessor;
  int MenuDisciplina;

  printf("----Bem vindo ao Sistema Escolar----\n\n");

  do {
    printf("Para Continuar aperte '1'\n");
    printf("Para Sair aperte '0'\n");

    scanf("%d", &TeladeInicio);

    if (TeladeInicio == 0) {
      printf("Programa Finalizado!");
      return 0;
    } else if (TeladeInicio == 1)
      InicioCont = 1;
    else if (TeladeInicio != 0 && TeladeInicio != 1)
      printf("Comando Desconhecido, por favor escolha uma opção válida:\n\n");
  } while (InicioCont == 0);

  printf("Selecione a opção desejada:\n");
  printf(
      "\n* Para selecionar a opção, pressione o valor referente a mesma:\n\n");

  printf("1 - Cadastrar Aluno\n");
  printf("2 - Cadastrar Professor\n");
  printf("3 - Cadastrar Disciplina\n");
  printf("4 - Relatorios\n");

  scanf("%d", &MenuInicial);

  switch (MenuInicial) {
  case 1:
    printf("\n  1 > Inserir Aluno \n");
    printf("  2 > Excluir Aluno \n");
    printf("  3 > Atualizar Cadastro do Aluno \n");
    scanf("%d", &MenuAluno);

    break;

  case 2:
    printf("\n  1 > Inserir Professor \n");
    printf("  2 > Excluir Professor \n");
    printf("  3 > Atualizar Cadastro do Professor \n");
    scanf("%d", &MenuProfessor);
    break;
  case 3:
    printf("\n  1 > Inserir Disciplina \n");
    printf("  2 > Excluir Disciplina \n");
    printf("  3 > Atualizar Cadastro da Disciplina \n");
    scanf("%d", &MenuDisciplina);
    break;
  case 4:
    printf("\n  1 > Listar Alunos \n");
    printf("  2 > Listar Professores \n");
    printf("  3 > Listar Disciplinas (dados da disciplina sem os alunos) \n");
  case default:
  }
}