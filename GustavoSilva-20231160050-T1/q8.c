#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Remove  \n das strings
void del_bar_N(char string[]){
  int dbcont;
  for(dbcont=0;string[dbcont]!='\0';dbcont++)
    if(string[dbcont]=='\n')
      string[dbcont]='\0';
}

void Imprimir_Campo_de_Batalha(int (*matriz)[10]){
  printf("     1  2  3  4  5  6  7  8  9  10\n");
  for(int icont = 0 ; icont < 10; icont++){
    printf("%c - ", icont+65);
    for(int jcont = 0; jcont < 10; jcont++){
      
      if(matriz[icont][jcont] == 0){
        printf("[ ]");
      }else if (matriz[icont][jcont] == 5){
        printf("[X]");
      }else if (matriz[icont][jcont] > 5){
        printf("[N]");
      }else printf("[#]");
      if(jcont == 9){
         printf("\n");
      }
    }
  }
}

void Imprimir_Navios(int qtd_navios, int tam_navio){
  int qtd_aux = qtd_navios;
  printf("Navio %d: ", tam_navio);
  for(int jcont = qtd_aux; jcont > 0; jcont--){
    printf(" <");
    for(int icont = 0; icont < tam_navio; icont++)
      printf("%s", "𖨉");
    printf(" ");
  }
  printf("\n");
}

int VerificacaoValorMenu(int num1, int num2) {
  int icont;
  int valido = -1;
  int verificado = -1;
  
  char str_verif[100];
  while (valido != 0) {
    fgets(str_verif, 100, stdin);
    del_bar_N(str_verif);
    int comprimento = strlen(str_verif);
    int validacao = 0;
    
    if (comprimento == 1 || comprimento == 2) {
      for (icont = 0; icont < comprimento; icont++)
        if (str_verif[icont] >= '0' && str_verif[icont] <= '9') {
          validacao++;

        } else
          validacao--;

      if (validacao == comprimento) {
        verificado = atoi(str_verif);

        if (verificado >= num1 && verificado <= num2) {
          valido = 0;
        } else
          printf("\nComando Inválido! Tente Novamente\n");
      } else
        printf("\nComando Inválido! Tente Novamente\n");
    } else
      printf("\nComando Inválido! Tente Novamente\n");
  }

  return verificado;
}

int Verificar_Jogada_BN(char jogada[]){
  if(strlen(jogada) != 2 && strlen(jogada) != 3){
    return 0;
  }else{
    if((jogada[0] >= 'a' && jogada[0] <= 'j' || 
        jogada[0] >= 'A' && jogada[0] <= 'J') &&
        (jogada[1] >= '1' && jogada[1] <= '9' && jogada[2]== '\0')|| 
      (jogada[1] == '1' && jogada[2]== '0')){
      return 1;
      
    }else return 0;
  }
}


void Padrao_Jogada_BN(char jogada[]){
  if(jogada[0]>= 'a' && jogada[0]<='j')
    jogada[0] += -32;
}

int Separar_p2(char posicao[]){
  char p2[4];
  int p2_int;
  int icont;
  for(icont = 1; posicao[icont] != '\0'; icont++){
    p2[icont-1] = posicao[icont];
  }
  p2[icont-1] = '\0';

  p2_int = atoi(p2);
  return p2_int;
}

int Verificar_Fronteira(int Tam_Navio, char direcao, int p1, int p2, int (*matriz)[10]){
  int icont, jcont;
  int valido = -1;
  int verif_tam = 0;
  int verif_tam_2 = 0;
  
  if(direcao == 'V'){
    if (p1 > 0){
      icont = p2-1;
      while(icont != p2+2){
        if(matriz[p1-1][icont] != 0){
          valido = 0;
          return valido;
        }
        icont++;
      }
    }
    if(p2 > 0){
      for(icont = p1; icont < (p1 + Tam_Navio) && icont < 10; icont ++){
        verif_tam++;
        if(matriz[icont][p2-1] != 0){
          valido = 0;
          return valido;
        }
      }
    }
    if (p1+Tam_Navio <= 9){
      icont = p2-1;
      while(icont != p2+2){
        if(matriz[p1+Tam_Navio][icont] != 0){
          valido = 0;
          return valido;
        }
        icont++;
      }
    }
    if(p2 < 9){
      for(icont = p1; icont < (p1 + Tam_Navio) && icont < 10; icont ++){
        verif_tam_2++;
        if(matriz[icont][p2+1] != 0){
          valido = 0;
          return valido;
        }
      }
    }
  }else if (direcao == 'H'){
    if (p2 > 0){
      icont = p1-1;
      while(icont != p1+2){
        if(matriz[icont][p2-1] != 0){
          valido = 0;
          return valido;
        }
        icont++;
      }
    }
    if(p1 > 0){
      for(icont = p2; icont < (p2 + Tam_Navio) && icont < 10; icont ++){
        verif_tam++;
        if(matriz[p1-1][icont] != 0){
          valido = 0;
          return valido;
        }
      }
    }
    if (p2+Tam_Navio <= 9){
      icont = p1-1;
      while(icont != p1+2){
        if(matriz[icont][p2+Tam_Navio] != 0){
          valido = 0;
          return valido;
        }
        icont++;
      }
    }
    if(p1 < 9){
      for(icont = p2; icont < (p2 + Tam_Navio) && icont < 10; icont ++){
        verif_tam_2++;
        if(matriz[p1+1][icont] != 0){
          valido = 0;
          return valido;
        }
      }
    }
  }
  if(valido == -1 && verif_tam == Tam_Navio && verif_tam_2 == Tam_Navio)
    return valido = 1;
  else return valido = 0;
}


void Menu_Posicionar_Navio(int Tam_Navio, int (*matriz)[10]){
  char posicao[4];
  int p1;
  int p2;
  int sair = 0;
  char direcao[2];
  printf("\nInforme a direcão do Navio, Vertical(V) ou Horizontal(H): ");
  sair = 0;
  while(!sair){
    fgets(direcao,2,stdin);
    if (direcao[0] == 'V' || direcao[0] == 'H')
      sair = 1;
    else printf("\nDireção inválida, tente novamente: ");
  }

  if(direcao[0] == 'V'){
    for(int icont = 0; icont < 10; icont++)
      for(int jcont = 10 - Tam_Navio+1; jcont < 10; jcont++)
        matriz[jcont][icont] = -1;
  }else if(direcao[0] == 'H'){
    for(int icont = 0; icont < 10; icont++)
      for(int jcont = 10 - Tam_Navio+1; jcont < 10; jcont++)
        matriz[icont][jcont] = -1;
  }
  
  
  printf("\nPosicione o seu Navio no Campo de Batalha!\n");

  Imprimir_Campo_de_Batalha(matriz);
      
  printf("\nDigite a Posição: ");
  sair = 0;
  while(!sair){
    fgets(posicao, 4, stdin);
    del_bar_N(posicao);
    printf("\n");
    puts(posicao);
    printf("\n");
    
    if(Verificar_Jogada_BN(posicao) == 1){
      Padrao_Jogada_BN(posicao);
      p1 = posicao[0] - 65;
      p2 = Separar_p2(posicao) - 1;
      
      if(matriz[p1][p2] == 0){  //verificar se a posição ja está vazia.
        
        if(Verificar_Fronteira(Tam_Navio, direcao[0], p1, p2, matriz) == 1){//verificar se faz fronteira com outro barco.
          if (direcao[0] == 'V'){
            for(int icont = p1; icont< p1+Tam_Navio;icont++)
              matriz[icont][p2] = Tam_Navio*6;
          }else printf("\nPosição inválida1! Tente novamente: ");
          sair = 1;
        }
      }else {printf("\n%d - %d - %d\n", matriz[p1][p2],p1,p2);
             printf("\nPosição inválida2! Tente novamente: ");
            }
      
    }else printf("\nPosição inválida3! Tente novamente: ");
  }
  for(int icont = 0; icont < 10; icont++)
    for(int jcont = 0;jcont < 10; jcont++)
      if(matriz[icont][jcont] == -1)
        matriz[icont][jcont] = 0;
}

int main(){
  int matriz[10][10] = {{0}};
  int navio;
  int navio_1[2] = {4,1}, navio_2[2] = {3,2}, navio_3[2] = {2,3}, navio_4[2] = {1,4}; // {qtd, tamanho}
  int navio_da_vez;
  int sair = 0;
  char posicao[4];
  
  

  
  
  
  
  while(navio_4[0] > 0 || navio_3[0] > 0 || navio_2[0] > 0 || navio_1[0] > 0 ){
    
    printf("Navios Disponíveis:\n\n");
    
    Imprimir_Navios(navio_4[0],navio_4[1]);
    Imprimir_Navios(navio_3[0],navio_3[1]);
    Imprimir_Navios(navio_2[0],navio_2[1]);
    Imprimir_Navios(navio_1[0],navio_1[1]);
    
    printf("\n\nDigite o número do navio que deseja posicionar: ");
    sair = 0;
    while(!sair){
      navio_da_vez = VerificacaoValorMenu(1, 4);
      getchar();
      switch(navio_da_vez){
        case 1:{
          if(navio_1[0] > 0){
            Menu_Posicionar_Navio(navio_1[1], matriz);
            navio_1[0]--;
            sair = 1;
          }else {
            printf("\nVocê não possui mais navio %d disponíveis, Selecione outro navio: ", navio_1[1]);
          }
          break;
        }
        case 2:{
          if(navio_2[0] > 0){
            Menu_Posicionar_Navio(navio_2[1], matriz);
            navio_2[0]--;
            sair = 1;
          } else {
            printf("\nVocê não possui mais navio %d disponíveis, Selecione outro navio: ", navio_2[1]);
          }
          break;
        }
        case 3:{
          if(navio_3[0] > 0){
            Menu_Posicionar_Navio(navio_3[1], matriz);
            navio_3[0]--;
            sair = 1;
          } else {
            printf("\nVocê não possui mais navio %d disponíveis, Selecione outro navio: ", navio_3[1]);
          }
          break;
        }
        case 4:{
          if(navio_4[0] > 0){
            Menu_Posicionar_Navio(navio_4[1], matriz);
            navio_4[0]--;
            sair = 1;
          } else {
            printf("\nVocê não possui mais navio %d disponíveis, Selecione outro navio: ", navio_4[1]);
          }
          break;
        }
       
      }//fim do switch
      Imprimir_Campo_de_Batalha(matriz);
    }
    

  }
  

  
  
}