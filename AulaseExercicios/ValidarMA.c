#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_data 15



void RemoverBarraN(char string[]);
int ValidarData(const char string_data[]);
int VerificarAnoBissexto(int ano);

int main(){
  int num = -1;
  char string_data[TAM_data];

  fgets(string_data,TAM_data,stdin);
  RemoverBarraN(string_data);

  num = ValidarData(string_data);
  
  printf("%d", num);
  
}


int ValidarData(const char string_data[]){
  char Dia[3];
  char Mes[3];
  char Ano[5];
  int icont,jcont,kcont,lcont;
  int ctrl = 0;
  int Tam_Valido=0;
  int int_aux_dia;
  int int_aux_mes;
  int int_aux_ano;
  int validacao = 0;
  int tam_string=0;
  
  for(icont=0;string_data[icont]!= '\0';icont++){
    tam_string++;
  }
  
  if(tam_string >= 6 && tam_string <= 10)
    Tam_Valido = 1;

  if (Tam_Valido == 1) {
    for (jcont = 0; string_data[jcont]!= '/'; jcont++){
      Dia[jcont] = string_data[jcont];}
    Dia[jcont] = '\0';
    int_aux_dia = atoi(Dia);

    for (kcont = jcont+1; string_data[kcont] != '/'; kcont++){
      Mes[kcont-(jcont+1)] = string_data[kcont];}
    Mes[kcont-(jcont+1)] = '\0';
    int_aux_mes = atoi(Mes);
  
    for (lcont= kcont+1; string_data[lcont] != '\0'; lcont++){
      Ano[lcont-(kcont+1)] = string_data[lcont];}
    Ano[lcont-(kcont+1)] = '\0';
    int_aux_ano = atoi(Ano);
  
    if (int_aux_mes == 4 || int_aux_mes == 6 || int_aux_mes == 9 ||
        int_aux_mes == 11){
      if (int_aux_dia >= 1 && int_aux_dia <= 30){
        validacao = 1;
      }
    }
    if (int_aux_mes == 1 || int_aux_mes == 3 || int_aux_mes == 5 ||
        int_aux_mes == 7 || int_aux_mes == 8 || int_aux_mes == 10 ||
        int_aux_mes == 12){
      if (int_aux_dia >= 1 && int_aux_dia <= 31){
        validacao = 1;
      }
    }
    if (int_aux_mes == 2){
      if(VerificarAnoBissexto(int_aux_ano)==1){
        if (int_aux_dia >= 1 && int_aux_dia <= 29){
          validacao = 1;
        }
      }else if (VerificarAnoBissexto(int_aux_ano)==0){
        if (int_aux_dia >= 1 && int_aux_dia <= 28){
          validacao = 1;
        }
      }
    }
  }

  if (validacao == 1) {
    return 0;
  } else
    return 1;
}

void RemoverBarraN(char string[]) {
  int Rbcont;
  for (Rbcont = 0; string[Rbcont] != '\0'; Rbcont++)
    if (string[Rbcont] == '\n')
      string[Rbcont] = '\0';
}

int VerificarAnoBissexto(int ano){
   
  if (ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0)) 
    return 1;
  else return 0;
}