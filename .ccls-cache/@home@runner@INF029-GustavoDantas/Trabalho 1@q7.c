#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char X_O(int num){
  if(num == 1)
    return 'X';
  else if (num ==10)
    return 'O';
  else return ' ';
}

void Linha_superior(char p1,char p2,char p3){
  if(p1 == 'X'){
    printf(" \\ / ");
  }else if (p1 == 'O'){
    printf(" === ");
  }else{
    printf("     ");
  }
  
  printf(" | ");

  if(p2 == 'X'){
    printf(" \\ / ");
  }else if (p2 == 'O'){
    printf(" === ");
  }else{
    printf("     ");
  }
  printf(" | ");

  if(p3 == 'X'){
    printf(" \\ / \n");
  }else if (p3 == 'O'){
    printf(" === \n");
  }else{
    printf("     \n");
  }
}

void Linha_central(char p1,char p2,char p3){
  if(p1 == 'X'){
    printf("  X  ");
  }else if (p1 == 'O'){
    printf("|   |");
  }else{
    printf("     ");
  }
  
  printf(" | ");

  if(p2 == 'X'){
    printf("  X  ");
  }else if (p2 == 'O'){
    printf("|   |");
  }else{
    printf("     ");
  }
  printf(" | ");

  if(p3 == 'X'){
    printf("  X  \n");
  }else if (p3 == 'O'){
    printf("|   |\n");
  }else{
    printf("     \n");
  }
}

void Linha_inferior(char p1,char p2,char p3){
  if(p1 == 'X'){
    printf(" / \\ ");
  }else if (p1 == 'O'){
    printf(" === ");
  }else{
    printf("     ");
  }
  
  printf(" | ");

  if(p2 == 'X'){
    printf(" / \\ ");
  }else if (p2 == 'O'){
    printf(" === ");
  }else{
    printf("     ");
  }
  printf(" | ");

  if(p3 == 'X'){
    printf(" / \\ \n");
  }else if (p3 == 'O'){
    printf(" === \n");
  }else{
    printf("     \n");
  }
}

void Print_JDV(int jogo_da_velha[3][3]){
  char p1, p2, p3;
  printf("\n");
  printf("       1       2       3\n");
  for(int icont = 0; icont < 3; icont++){
    p1 = X_O(jogo_da_velha[icont][0]);
    p2 = X_O(jogo_da_velha[icont][1]);
    p3 = X_O(jogo_da_velha[icont][2]);
    printf("     ");
    Linha_superior(p1, p2, p3);
    printf("%c -  ",65+icont);
    Linha_central(p1, p2, p3);
    printf("     ");
    Linha_inferior(p1, p2, p3);
    if(icont<2){
      printf("     ------#-------#------\n");
      
    }
  }
}

void del_bar_N(char string[]){
  int dbcont;
  for(dbcont=0;string[dbcont]!='\0';dbcont++)
    if(string[dbcont]=='\n')
      string[dbcont]='\0';
}

// A função abaixo verifica se a jogada fornecida possui um valor válido(retorna 1) ou não(retorna 0).
int Verificar_Jogada(char jogada[]){
  if(strlen(jogada) != 2){
    return 0;
  }else{
    if((jogada[0] >= 'a' && jogada[0] <= 'c' || 
        jogada[0] >= 'A' && jogada[0] <= 'C') &&
        jogada[1] >= '1' && jogada[1] <= '3'){
      return 1;
      
    }else return 0;
  }
}

// A função abaixo transforma a jogada fornecida em um padrão de [Letramaiuscula][Número], e deve ser utilizada obrigatoriamente somente se a jogada for válida.
void Padrao_Jogada(char jogada[]){
  switch(jogada[0]){
    case 'a':{
      jogada[0] = 'A';
      break;
    }
    case 'b':{
      jogada[0] = 'B';
      break;
    }
    case 'c':{
      jogada[0] = 'C';
      break;
    }
  }
}

//Verifica se a posição na matriz fornecida está vazia.
int Validar_posicao(int Linha, int Coluna, int jogo_da_velha[3][3]){
  if (jogo_da_velha[Linha][Coluna] == 0)
    return 1;
  else return 0;
  
}

int main(){
  int jogo_da_velha[3][3] = {{0}};
  char jogada[5];
  int jogador_da_vez = 1;
  int sair = 0;
  int fim_de_jogo = 0;
  int velha = 0;
  int num_de_jogadas = 0;
  int icont, jcont;
  int Linha;
  int Coluna;

  Print_JDV(jogo_da_velha);
  //1 - Criar as telas de inicio
  while(!fim_de_jogo && !velha){
    num_de_jogadas++;
    
    if(jogador_da_vez == 1){
      printf("\nJogador 1, informe a sua jogada: " );
    }else if (jogador_da_vez == 2)
      printf("\nJogador 2, informe a sua jogada: " );

    //Mantém o jogador no loop até ele fornecer uma jogada válida.
    sair = 0;
    while(!sair){
      fgets(jogada,5, stdin);
      del_bar_N(jogada);
      int verificar = Verificar_Jogada(jogada);
      
      if(verificar == 1){
        Padrao_Jogada(jogada);
        Linha = jogada[0] - 65;
        Coluna = jogada[1] - 49;
        if(Validar_posicao(Linha, Coluna, jogo_da_velha)==1){
          sair = 1;
        }else printf("\nJogada inválida, tente novamente: ");
      }else printf("\nJogada inválida, tente novamente: ");
    }

    //Atribui o valor na matriz(posição no jogo da velha) equivalente ao jogador da vez
  
    if(jogador_da_vez == 1){
      jogo_da_velha[Linha][Coluna] = 1;
    }else{
      jogo_da_velha[Linha][Coluna] = 10;
    }
    Print_JDV(jogo_da_velha);
    //Verifica linhas e colunas do jogo da velha, buscando um vencedor.
    
    int somat, somat_2;
    
    for(icont=0; icont < 3; icont++){
      somat = somat_2 = 0;
      for(jcont= 0; jcont < 3; jcont++){
        somat += jogo_da_velha[icont][jcont];
        somat_2 += jogo_da_velha[jcont][icont];
      }
    
      if(somat == 3 || somat_2 ==3){
        printf("Fim de Jogo! O jogador 1 é o vencedor!!");
        fim_de_jogo = 1;
      }else if (somat == 30 || somat == 30){
        printf("Fim de Jogo! O jogador 2 é o vencedor!!");
        fim_de_jogo = 1;
        
      }
    }
  
    //Verifica diagonais do jogo da velha, buscando um vencedor.
    somat = somat_2 = 0;
  
    for(icont=0, jcont = 2; icont<3; icont++, jcont--){
      somat += jogo_da_velha[icont][icont];
      somat_2 += jogo_da_velha[jcont][icont];
      if(somat == 3 || somat_2 == 3){
        printf("\nFim de Jogo! O jogador 1 é o vencedor!!");
        fim_de_jogo = 1;
      }else if (somat == 30 || somat_2 == 30){
        printf("\nFim de Jogo! O jogador 2 é o vencedor!!");
        fim_de_jogo = 1;
      }
    }

    //Verifica se o Jogo empatou.
  
    if(num_de_jogadas == 9 && fim_de_jogo == 0){
      printf("\nDeu Velha!!");
      velha = 1;
    }

    if(jogador_da_vez == 1){
      jogador_da_vez = 2;
    }else {
      jogador_da_vez = 1;
    }
  }
}