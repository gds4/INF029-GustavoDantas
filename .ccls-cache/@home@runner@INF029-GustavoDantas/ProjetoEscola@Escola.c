#include <stdio.h>
#include <stdlib.h>
#define Tam 10

typedef struct{
  int Matricula;
  int Nome;
  char Sexo;
  int Cpf;
  int DataDeNasc;
}Aluno;

int main(void){
  int TeladeInicio;
  int InicioCont = 0;

  printf("----Bem vindo ao Sistema Escolar----\n");
  
  Do
  {
    printf("Para Continuar aperte '1'\n");
    printf("Para Sair aperte '0'\n");

    scanf("%d",&TeladeInicio);
     
    if(TeladeInicio==0)
    {
      printf("Programa Finalizado!");
      return 0;
    }
    else if(TeladeInicio==1)
      InicioCont=1;
    else if(TeladeInicio!=0 && TeladeInicio!=1)
      printf("Comando Desconhecido, por favor escolha uma opção válida:\n");
  }while(InicioCont==0)
  
}