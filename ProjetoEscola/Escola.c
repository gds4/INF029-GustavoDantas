#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Tam_Nome 101
#define Tam_Data 11
#define QTD_Alunos 5

int TelaInicial();
int MenuPrincipal();
int MenudeAlunos();
int MenudeProfessores();
int MenudeDisciplina();
int MenuRelatorios();

typedef struct {
  int Matricula;
  char Nome[Tam_Nome];
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
  int MenuRelatorio;
  Aluno ListaDeAlunos[QTD_Alunos];
  int qtd_alunos_cadastrados=0;

  printf("----Bem vindo ao Sistema Escolar----\n\n");

  do {
    TeladeInicio = TelaInicial();
    
 
    if (TeladeInicio == 0) {
      printf("Programa Finalizado!");
      return 0;
    } else if (TeladeInicio == 1)
      InicioCont = 1;
    else if (TeladeInicio != 0 && TeladeInicio != 1)
      printf("Comando Desconhecido, por favor escolha uma opção válida:\n\n");
  } while (InicioCont == 0);
    
  MenuInicial = MenuPrincipal();
    
  switch (MenuInicial) {
    case 1:
      MenuAluno = MenudeAlunos();
      
      switch (MenuAluno)
        
        case 1:
          printf("Insira o nome do aluno:\n");
          fgets(ListaDeAlunos[qtd_alunos_cadastrados].Nome,Tam_Nome,stdin);
          printf("Insira a Matrícula\n");
          scanf("%d", &ListaDeAlunos[qtd_alunos_cadastrados].Matricula);
          printf("Insira o sexo do aluno: M/F");
          scanf("%c", &ListaDeAlunos[qtd_alunos_cadastrados].Sexo);
          printf("Insira o cpf do aluno:\n**apenas números**");
          scanf("%d", &ListaDeAlunos[qtd_alunos_cadastrados].Cpf);
          printf("Insira a data de nascimento do aluno:");
          
          break;
      break;
  
    case 2:
      
      MenuProfessor = MenudeProfessores();
      break;
      
    case 3:
      
      MenuDisciplina = MenudeDisciplina();
      break;
      
    case 4:
      
      MenuRelatorio = MenuRelatorios();
    
    default:
      
      printf("Valor Inválido");
      break;
    
  }
}

//Funções--Menus

int TelaInicial(){
  int TeladeInicio;
  
  printf("Para Continuar aperte '1'\n");
  printf("Para Sair aperte '0'\n");
  scanf("%d", &TeladeInicio);
  
  return TeladeInicio;
}

int MenuPrincipal(){
  int MenuInicial;
  
  printf("Selecione a opção desejada:\n");
  printf("\n* Para selecionar a opção, pressione o valor referente a mesma:\n\n");
  printf("1 - Cadastrar Aluno\n");
  printf("2 - Cadastrar Professor\n");
  printf("3 - Cadastrar Disciplina\n");
  printf("4 - Relatorios\n");
  scanf("%d", &MenuInicial);

  return MenuInicial;
  
}

int MenudeAlunos(){
  int MenuAluno;
  printf("\n  1 > Inserir Aluno \n");
  printf("  2 > Excluir Aluno \n");
  printf("  3 > Atualizar Cadastro do Aluno \n");
  scanf("%d", &MenuAluno);

  return MenuAluno;
}

int MenudeProfessores(){
  int MenuProfessor;
  
  printf("\n  1 > Inserir Professor \n");
  printf("  2 > Excluir Professor \n");
  printf("  3 > Atualizar Cadastro do Professor \n");
  scanf("%d", &MenuProfessor);

  return MenuProfessor;
}

int MenudeDisciplina(){
  int MenuDisciplina;
  printf("\n  1 > Inserir Disciplina \n");
  printf("  2 > Excluir Disciplina \n");
  printf("  3 > Atualizar Cadastro da Disciplina \n");
  scanf("%d", &MenuDisciplina);

  return MenuDisciplina;
}

int MenuRelatorios(){
  int MenuRelatorio;
  printf("\n  1 > Listar Alunos \n");
  printf("  2 > Listar Professores \n");
  printf("  3 > Listar Disciplinas (dados da disciplina sem os alunos) \n");
  
  scanf("%d", &MenuRelatorio);

  return MenuRelatorio;
}