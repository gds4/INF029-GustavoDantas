#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int Qtd;
  int Tam;
}Navio;


void copiar_matriz(int matriz_origem[12][12], int matriz_destino[12][12]) {
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 12; j++) {
      matriz_destino[i][j] = matriz_origem[i][j];
    }
  }
}

int Tam_String(char string[]){
  int comprimento=0;
  for(int icont = 0;string[icont] != '\0';icont++){
    comprimento++;
  }
  return comprimento;
}
//Remove  \n das strings
void del_bar_N(char string[]){
  int dbcont;
  for(dbcont=0;string[dbcont]!='\0';dbcont++)
    if(string[dbcont]=='\n')
      string[dbcont]='\0';
}

void Imprimir_Campo_de_Batalha(int (*matriz)[12],int num){
  
  if(num==1){
    printf("     1  2  3  4  5  6  7  8  9  10\n");
    for(int icont = 1 ; icont < 11; icont++){
      printf("%c - ", icont+64);
      for(int jcont = 1; jcont < 11; jcont++){
        
        if(matriz[icont][jcont] == 0){
          printf("[ ]");
        }else if (matriz[icont][jcont] > 5){
          printf("[N]");
        }else printf("[#]");
        if(jcont == 10){
           printf("\n");
        }
      }
    }
  }else if(num==2){
    printf("     1  2  3  4  5  6  7  8  9  10\n");
    for(int icont = 1 ; icont < 11; icont++){
      printf("%c - ", icont+64);
      for(int jcont = 1; jcont < 11; jcont++){
        
        if(matriz[icont][jcont] == 0 || matriz[icont][jcont] > 5){
          printf("[ ]");
        }else if (matriz[icont][jcont] == 5){
          printf("[X]");
        }else if (matriz[icont][jcont] == 3){
          printf("[O]");
        }else printf("[#]");
        if(jcont == 10){
           printf("\n");
        }
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
  int tam = Tam_String(jogada);
  if(tam != 2 && tam != 3){
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

int Verificar_Fronteira(int Tam_Navio, char direcao, int p1, int p2, int (*matriz)[12]){
  int icont, jcont;
  int valido = -1;
  int verif_tam = 0;
  int verif_tam_2 = 0;

  
  if(direcao == 'V'){
    if (p1 > 0){
      icont = p2-1;
      while(icont != p2+2){
        if(matriz[p1-1][icont] != 0 && matriz[p1-1][icont] != -1){
          valido = 0;
          return valido;
        }
        icont++;
      }
    }
    if(p2 > 0){
      for(icont = p1; icont < (p1 + Tam_Navio) && icont < 12; icont ++){
        verif_tam++;
        if(matriz[icont][p2-1] != 0 && matriz[icont][p2-1] != -1){
          valido = 0;
          return valido;
        }
      }
    }
    if (p1+Tam_Navio <= 10){
      icont = p2-1;
      while(icont != p2+2){
        if(matriz[p1+Tam_Navio][icont] != 0 && matriz[p1+Tam_Navio][icont] != -1){
          valido = 0;
          return valido;
        }
        icont++;
      }
    }
    if(p2 < 11){
      for(icont = p1; icont < (p1 + Tam_Navio) && icont < 12; icont ++){
        verif_tam_2++;
        if(matriz[icont][p2+1] != 0 && matriz[icont][p2+1] != -1){
          valido = 0;
          return valido;
        }
      }
    }
  }else if (direcao == 'H'){
    if (p2 > 0){
      icont = p1-1;
      while(icont != p1+2){
        if(matriz[icont][p2-1] != 0 && matriz[icont][p2-1] != -1){
          valido = 0;
          return valido;
        }
        icont++;
      }
    }
    if(p1 > 0){
      for(icont = p2; icont < (p2 + Tam_Navio) && icont < 12; icont ++){
        verif_tam++;
        if(matriz[p1-1][icont] != 0 && matriz[p1-1][icont] != -1){
          valido = 0;
          return valido;
        }
      }
    }
    if (p2+Tam_Navio <= 10){
      icont = p1-1;
      while(icont != p1+2){
        if(matriz[icont][p2+Tam_Navio] != 0 && matriz[icont][p2+Tam_Navio] != -1){
          valido = 0;
          return valido;
        }
        icont++;
      }
    }
    if(p1 < 11){
      for(icont = p2; icont < (p2 + Tam_Navio) && icont < 12; icont ++){
        verif_tam_2++;
        if(matriz[p1+1][icont] != 0 && matriz[p1+1][icont] != -1){
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

void Navio_Afundado(int p1, int p2, int (*matriz)[12]){
  if(matriz[p1][p2] > 5){
    if(matriz[p1][p2] == 6){
      if (p1 >= 0 && p1 < 12 && p2 >= 0 && p2 < 12) {

        int valor = 5;

        for (int icont = p1 - 1; icont <= p1 + 1; icont++) {
          for (int jcont = p2 - 1; jcont <= p2 + 1; jcont++) {
            if (icont >= 0 && icont < 12 && jcont >= 0 && jcont < 12) {
              if (!(icont == p1 && jcont == p2)) {
                  matriz[icont][jcont] = valor;
              }
            }
          }
        }
      }
    }else{
      int icont, jcont;
      int valido = -1;
      int verif_tam = 0;
      int verif_tam_2 = 0;
      char direcao;
      int Tam_Navio = matriz[p1][p2]/6;
      
      if((matriz[p1+1][p2] == 3 || matriz[p1-1][p2] == 3 )||(matriz[p1+1][p2] > 5 || matriz[p1-1][p2] > 5)){
        direcao = 'V';
      }else if((matriz[p1][p2+1] == 3 || matriz[p1][p2-1] == 3) || (matriz[p1][p2+1] > 5 || matriz[p1][p2-1] > 5)){
        direcao = 'H';
      }
      
      if(direcao == 'V'){
        for(icont = p1-1; matriz[icont][p2] != 5 && matriz[icont][p2] != 0; icont--){
          if(icont==p1){
            icont--;
          }
          if(matriz[icont][p2] == Tam_Navio*6){
            return;
          }
        }
        for(jcont = icont+1; matriz[jcont][p2] != 5 && matriz[jcont][p2] != 0; jcont++){
          if(jcont==p1){
            jcont++;
          }
          if(matriz[jcont][p2] == Tam_Navio*6){
            return;
          }
        }
      }else if (direcao == 'H'){
        for(icont = p2-1; matriz[p1][icont] != 5 && matriz[p1][icont] != 0; icont--){
          if(icont==p2){
            icont--;
          }
          if(matriz[p1][icont] == Tam_Navio*6){
            return;
          }
        }
        for(jcont = icont+1; matriz[p1][jcont] != 5 && matriz[p1][jcont] != 0; jcont++){
          if(jcont==p2){
            jcont++;
          }
          if(matriz[p1][jcont] == Tam_Navio*6){
            return;
          }
        }
      }
      
      if(direcao == 'V'){
        int p_navio = icont+1;
        if (p_navio > 0){
          icont = p2-1;
          while(icont != p2+2){
            if(matriz[p_navio-1][icont] == 0){
              matriz[p_navio-1][icont] = 5;
            }
            icont++;
          }
    
        }
        if(p2 > 0){
          for(icont = p_navio; icont < (p_navio + Tam_Navio) && icont < 12; icont ++){
            verif_tam++;
            if(matriz[icont][p2-1] == 0){
              matriz[icont][p2-1] = 5;
    
            }
          }
    
        }
        if (p_navio+Tam_Navio <= 10){
          icont = p2-1;
          while(icont != p2+2){
            if(matriz[p_navio+Tam_Navio][icont] == 0 ){
              matriz[p_navio+Tam_Navio][icont] = 5;
            }
            icont++;
          }
        }
        if(p2 < 11){
          for(icont = p_navio; icont < (p_navio + Tam_Navio) && icont < 12; icont ++){
            verif_tam_2++;
            if(matriz[icont][p2+1] == 0){
              matriz[icont][p2+1] = 5;
    
            }
          }
    
        }
      }else if (direcao == 'H'){
        int p_navio_2 = icont+1;
        if (p_navio_2 > 0){
          icont = p1-1;
          while(icont != p1+2){
            if(matriz[icont][p_navio_2-1] == 0){
              matriz[icont][p_navio_2-1] = 5;
    
            }
            icont++;
          }
        }
        if(p1 > 0){
          for(icont = p_navio_2; icont < (p_navio_2 + Tam_Navio) && icont < 12; icont ++){
            if(matriz[p1-1][icont] == 0){
              matriz[p1-1][icont] = 5;
            }
          }
        }
        if (p_navio_2+Tam_Navio <= 10){
          icont = p1-1;
          while(icont != p1+2){
            if(matriz[icont][p_navio_2+Tam_Navio] == 0){
              matriz[icont][p_navio_2+Tam_Navio] = 5;
    
            }
            icont++;
          }
        }
        if(p1 < 11){
          for(icont = p_navio_2; icont < (p_navio_2 + Tam_Navio) && icont < 12; icont ++){
            if(matriz[p1+1][icont] == 0){
              matriz[p1+1][icont] = 5;
    
            }
          }
        }
      }
    }
  }
  
}


void Menu_Posicionar_Navio(int Tam_Navio, int (*matriz)[12], char posicao[]){
  int p1;
  int p2;
  int sair = 0;
  char direcao[2];
  printf("\nInforme a direcão do Navio, Vertical(V) ou Horizontal(H): ");
  sair = 0;
  while(!sair){
    fgets(direcao,2,stdin);
    del_bar_N(direcao);
    getchar();
    if (direcao[0] == 'V' || direcao[0] == 'H')
      sair = 1;
    else printf("\nDireção inválida, tente novamente: ");
  }

  if(direcao[0] == 'V'){
    for(int icont = 1; icont < 11; icont++)
      for(int jcont = 11 - Tam_Navio+1; jcont < 11; jcont++)
        if(matriz[jcont][icont] < 6)
          matriz[jcont][icont] = -1;
  }else if(direcao[0] == 'H'){
    for(int icont = 1; icont < 11; icont++)
      for(int jcont = 11 - Tam_Navio+1; jcont < 11; jcont++)
        if(matriz[icont][jcont] < 6)
          matriz[icont][jcont] = -1;
  }
  printf("\n");
  
  printf("\nPosicione o seu Navio no Campo de Batalha!\n");

  Imprimir_Campo_de_Batalha(matriz,1);

  printf("\n [#] = Posição inválida\n");
      
  
  sair = 0;
  while(!sair){
    printf("\n");
    printf("\nDigite a Posição: ");
    fgets(posicao, 10, stdin);
    del_bar_N(posicao);
    getchar();
    
    int verif_jogada = Verificar_Jogada_BN(posicao);
    if(verif_jogada == 1){
      Padrao_Jogada_BN(posicao);
      p1 = posicao[0] - 64;
      p2 = Separar_p2(posicao);
      if(matriz[p1][p2] == 0){  //verificar se a posição ja está vazia.
        if(Verificar_Fronteira(Tam_Navio, direcao[0], p1, p2, matriz) == 1){//verificar se faz fronteira com outro barco.
          if (direcao[0] == 'V'){
            for(int icont = p1; icont< p1+Tam_Navio;icont++)
              matriz[icont][p2] = Tam_Navio*6;
          }else if (direcao[0] == 'H'){
            for(int icont = p2; icont< p2+Tam_Navio;icont++)
              matriz[p1][icont] = Tam_Navio*6;
          }
          sair = 1;
        }else {
          printf("\nJá possui algo na posição!\n");}
        
      }else {
             printf("\nPosição inválida! Tente novamente!\n ");
            }
      
    }else{ printf("Posição inválida! Tente novamente!\n ");
    }
    
  }
  for(int icont = 0; icont < 12; icont++)
    for(int jcont = 0;jcont < 12; jcont++)
      if(matriz[icont][jcont] == -1)
        matriz[icont][jcont] = 0;
  Imprimir_Campo_de_Batalha(matriz,1);
}

int main(){
  char posicao[10];
  int matriz_j1[12][12] = {{0}};
  int matriz_j2[12][12] = {{0}};
  int navio;
  Navio navio_1;
  Navio navio_2;
  Navio navio_3;
  Navio navio_4;
  int pontuacao_j1;
  int pontuacao_j2;  
  int fim_de_jogo = 0;
  int jogador_da_vez= 1;
  //int navio_11[2] = {4,1}, navio2_2[2] = {3,2}, navio_33[2] = {2,3}, navio_44[2] = {1,4}; // {qtd, tamanho}
  int navio_da_vez;
  int sair = 0;
  int inicio = 0;
  int menu;
  for(int icont = 0; icont<2; icont++){
    int matriz[12][12] = {{0}};
    navio_1.Qtd = 4;
    navio_2.Qtd = 3;
    navio_3.Qtd = 2;
    navio_4.Qtd = 1;
  
    navio_1.Tam = 1;
    navio_2.Tam = 2;
    navio_3.Tam = 3;
    navio_4.Tam = 4;
    
    while(!inicio){
      printf("-------BATALHA NAVAL--------\n\n");

      printf("\nPressione 1 para iniciar\n");
      printf("\nPressione 0 para Sair\n");
      menu = VerificacaoValorMenu(0, 1);
      if(menu == 1){
        inicio = 1;
      }else if (menu == 0){
        return 0;
      }
    }
    
    
    pontuacao_j1 = (navio_1.Qtd*navio_1.Tam*1)+(navio_2.Qtd*navio_2.Tam*2)+(navio_3.Qtd*navio_3.Tam*3)+(navio_4.Qtd*navio_4.Tam*4);
    pontuacao_j2 = (navio_1.Qtd*navio_1.Tam*1)+(navio_2.Qtd*navio_2.Tam*2)+(navio_3.Qtd*navio_3.Tam*3)+(navio_4.Qtd*navio_4.Tam*4);
    printf("\n");
    Imprimir_Campo_de_Batalha(matriz, 1);
    while(navio_4.Qtd > 0 || navio_3.Qtd > 0 || navio_2.Qtd > 0 || navio_1.Qtd > 0 ){
      if(jogador_da_vez==1){
        printf("\nJogador 1, posicione seu navio:\n");
      }else if(jogador_da_vez==2){
        printf("\nJogador 2, posicione seu navio:\n");
      }
      printf("\nNavios Disponíveis:\n\n");
      
      Imprimir_Navios(navio_4.Qtd,navio_4.Tam);
      Imprimir_Navios(navio_3.Qtd,navio_3.Tam);
      Imprimir_Navios(navio_2.Qtd,navio_2.Tam);
      Imprimir_Navios(navio_1.Qtd,navio_1.Tam);
      
      printf("\n\nDigite o número do navio que deseja posicionar: ");
      sair = 0;
      while(!sair){
        navio_da_vez = VerificacaoValorMenu(1, 4);
        switch(navio_da_vez){
          case 1:{
            if(navio_1.Qtd > 0){
              Menu_Posicionar_Navio(navio_1.Tam, matriz, posicao);
              navio_1.Qtd--;
              sair = 1;
            }else {
              printf("\nVocê não possui mais navio %d disponíveis, Selecione outro navio: ", navio_1.Tam);
            }
            break;
          }
          case 2:{
            if(navio_2.Qtd > 0){
              Menu_Posicionar_Navio(navio_2.Tam, matriz, posicao);
              navio_2.Qtd--;
              sair = 1;
            } else {
              printf("\nVocê não possui mais navio %d disponíveis, Selecione outro navio: ", navio_2.Tam);
            }
            break;
          }
          case 3:{
            if(navio_3.Qtd > 0){
              Menu_Posicionar_Navio(navio_3.Tam, matriz, posicao);
              navio_3.Qtd--;
              sair = 1;
            } else {
              printf("\nVocê não possui mais navio %d disponíveis, Selecione outro navio: ", navio_3.Tam);
            }
            break;
          }
          case 4:{
            if(navio_4.Qtd > 0){
              Menu_Posicionar_Navio(navio_4.Tam, matriz, posicao);
              navio_4.Qtd--;
              sair = 1;
            } else {
              printf("\nVocê não possui mais navio %d disponíveis, Selecione outro navio: ", navio_4.Tam);
            }
            break;
          }
         
        }//fim do switch
      }
    }
    if (icont == 0){
      copiar_matriz(matriz, matriz_j1);
    }else if (icont == 1)
      copiar_matriz(matriz, matriz_j2);
  }

  while(!fim_de_jogo){

    printf("\n");
    Imprimir_Campo_de_Batalha(matriz_j1, 2);
    printf("\n");
    Imprimir_Campo_de_Batalha(matriz_j2, 2);

    char jogada[10];

    sair = 0;
    if(jogador_da_vez == 1)
      printf("\nJogador 1, informe a jua jogada: ");
    else printf("\nJogador 2, informe a jua jogada: ");
      
    while(!sair){
      fgets(jogada,10,stdin);
      del_bar_N(jogada);

      if(Verificar_Jogada_BN(jogada) == 1){
        Padrao_Jogada_BN(jogada);
        int p1 = jogada[0] - 64;
        int p2 = Separar_p2(jogada);
        if (jogador_da_vez==1){
          if(matriz_j2[p1][p2] != 3 && matriz_j2[p1][p2] != 5 ){
            if(matriz_j2[p1][p2] > 5){
              Navio_Afundado(p1, p2, matriz_j2);
              pontuacao_j2 -= (matriz_j2[p1][p2]/6);
              matriz_j2[p1][p2] = 3;
              jogador_da_vez = 2;
              sair = 1;
            }else if(matriz_j2[p1][p2] < 3){
              matriz_j2[p1][p2] = 5;
              jogador_da_vez = 2;
              sair = 1;
            }
          }else printf("\nPosição inválida! Tente Novamente: ");
        }else{
          if(matriz_j1[p1][p2] != 3 && matriz_j1[p1][p2] != 5 ){
            if(matriz_j1[p1][p2] > 5){
              Navio_Afundado(p1, p2, matriz_j1);
              pontuacao_j1 -= (matriz_j1[p1][p2]/6);
              matriz_j1[p1][p2] = 3;
              jogador_da_vez = 1;
              sair = 1;
            }else if(matriz_j1[p1][p2] < 3){
              matriz_j1[p1][p2] = 5;
              jogador_da_vez = 1;
              sair = 1;
            }
          }else printf("\nPosição inválida! Tente Novamente: ");
        }
      }
    }

    
    if(pontuacao_j1 == 0){
      printf("\n");
      Imprimir_Campo_de_Batalha(matriz_j1, 2);
      printf("\n");
      Imprimir_Campo_de_Batalha(matriz_j2, 2);
      printf("\nO jogador 2 é o vencedor!\n");
      fim_de_jogo = 1;
    }else if(pontuacao_j2 == 0){
      printf("\n");
      Imprimir_Campo_de_Batalha(matriz_j1, 2);
      printf("\n");
      Imprimir_Campo_de_Batalha(matriz_j2, 2);
      printf("\nO jogador 1 é o vencedor!\n");
      fim_de_jogo = 1;
    }
  }
}
