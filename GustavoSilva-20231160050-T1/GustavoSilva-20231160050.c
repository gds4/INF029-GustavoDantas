// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Gustavo Dantas da Silva
//  email: gdantas536@gmail.com  
//  Matrícula: 20231160050
//  Semestre: 2023.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "GustavoSilva-20231160050.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}

int VerificarAnoBissexto(int ano){
   
  if (ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0)) 
    return 1;
  else return 0;
}

int Tam_String(char string[]){
  int comprimento=0;
  for(int icont = 0;string[icont] != '\0';icont++){
    comprimento++;
  }
  return comprimento;
}

int Verificar_Tam_de_Int(int num){
  int num_aux;
  int tam_int = 0;
  if(num == 0){
    return 1;
  }
  for(num_aux = num; num_aux != 0; num_aux/=10){
    tam_int++;
  }
  return tam_int;
}

//função que armazena a data em um inteiro no formato AAAAMMDD para fins de comparação
int Data_padrao_CMP(int dia, int mes, int ano){
  int data_padrao;

  data_padrao = ano;
  data_padrao = (data_padrao*100) + mes;
  data_padrao = (data_padrao* 100) + dia;

  return data_padrao;
  
}

char X_O(int num){
  if(num == 1)
    return 'X';
  else if (num ==10)
    return 'O';
  else return ' ';
}
  
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int icont,jcont,kcont,lcont;
  int Tam_Valido=0;
  DataQuebrada Data;
  int validacao = 0;
  int datavalida = 0;
  
  if(Tam_String(data) >= 6 && Tam_String(data) <= 10){
    Tam_Valido = 1;
    Data = quebraData(data);
  }
    
  //quebrar a string data em strings sDia, sMes, sAno

    
  //DataQuebrada dataQuebrada = quebraData(data);

  if(Data.valido == 1){
    if (Data.iMes == 4 || Data.iMes == 6 || Data.iMes == 9 ||
          Data.iMes == 11){
        if (Data.iDia >= 1 && Data.iDia <= 30){
          datavalida = 1;
        }
    }
    if (Data.iMes == 1 || Data.iMes == 3 || Data.iMes == 5 ||
        Data.iMes == 7 || Data.iMes == 8 || Data.iMes == 10 ||
        Data.iMes == 12){
      if (Data.iDia >= 1 && Data.iDia <= 31){
        datavalida = 1;
      }
    }
    if (Data.iMes == 2){
      if(VerificarAnoBissexto(Data.iAno)==1){
        if (Data.iDia >= 1 && Data.iDia <= 29){
          datavalida = 1;
        }
      }else {
        if (Data.iDia >= 1 && Data.iDia <= 28){
          datavalida = 1;
        }
      }
    }
    if(Data.iMes>12 || Data.iMes<1)
      datavalida = 0;
  }
  

    
  //if (dataQuebrada.valido == 0) return 0;

  //printf("%s\n", data);

  if (datavalida)
      return 1;
  else
      return 0;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[]){

  //calcule os dados e armazene nas três variáveis a seguir
  DiasMesesAnos dma;
  dma.qtdAnos = 0;
  dma.qtdDias = 0;
  dma.qtdMeses = 0;

  DataQuebrada data_inicial;
  DataQuebrada data_final;

  if(q1(datainicial) == 1)
    data_inicial = quebraData(datainicial);

  if(q1(datafinal)==1)
    data_final = quebraData(datafinal);

  if(Verificar_Tam_de_Int(data_inicial.iAno) == 2){
    data_inicial.iAno += 2000;
  }
  if(Verificar_Tam_de_Int(data_final.iAno) == 2){
    data_final.iAno += 2000;
  }
    
  if (q1(datainicial) == 0){
    dma.retorno = 2;
    return dma;
  }else if (q1(datafinal) == 0){
    dma.retorno = 3;
    return dma;
  }else if(Data_padrao_CMP(data_final.iDia, data_final.iMes, data_final.iAno) <    
    Data_padrao_CMP(data_inicial.iDia, data_inicial.iMes, data_inicial.iAno)){
    dma.retorno = 4;
    return dma;
  }
    //ultimo else if acima verifica se a data final não é menor que a data inicial
    
    //calcule a distancia entre as datas

  int array[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int anoinicial = data_inicial.iAno;
  int anofinal = data_final.iAno;
  int ctrl_de_inicio = 0;
  int icont;
  int qtd_dias = 0;
  int qtd_ano_bis = 0;

  //Conta a quantidade de dias totais da data inicial a final

  while(anoinicial <= anofinal){
    if(VerificarAnoBissexto(anoinicial)==1){
      array[1] = 29;
    }else {
      array[1] = 28;
    }
    for(icont = 0; icont < 12;icont++){
      if(ctrl_de_inicio == 0){

        if(anoinicial == anofinal && data_inicial.iMes == data_final.iMes){
            qtd_dias = data_final.iDia - data_inicial.iDia;
            break;
        }
        qtd_dias = array[data_inicial.iMes-1] - data_inicial.iDia;
        icont = data_inicial.iMes;
        ctrl_de_inicio = 1;
      }
      
      if(anoinicial == anofinal && icont == data_final.iMes-1){
        qtd_dias += data_final.iDia;
        break;
      }else {
        qtd_dias += array[icont];
      }
    }
    anoinicial++;
  }

  anoinicial = data_inicial.iAno;
  anofinal = data_final.iAno;
  
  int ano_atual = anoinicial;
  int qtd_dias_aux;
  int ctrl_mes = data_inicial.iMes-1;

  qtd_dias_aux = qtd_dias;

    
    
  // após contar os dias vou decrementando a variavel qtd_dias_aux até chegar a zero
  
  for(icont = ctrl_mes; qtd_dias_aux >= array[icont]; icont++){
    
    if(VerificarAnoBissexto(ano_atual) == 1){
      array[1] = 29;
    }else {
      array[1] = 28;
    } 
    
    qtd_dias_aux -= array[icont];
    dma.qtdMeses++;
    
    if(icont == 11){
      ano_atual++;
      icont = -1;//o valor é -1 porque será incrementado no final do loop para 0
    }
    
    if(dma.qtdMeses == 12){
      dma.qtdAnos++;
      dma.qtdMeses = 0;
    }
  }
  
  dma.qtdDias = qtd_dias_aux;
    
  //se tudo der certo
  dma.retorno = 1;
  return dma;
  
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{   
    
  int qtdOcorrencias = 0;
  int icont;
  if(isCaseSensitive == 1){
    for(icont = 0; texto[icont] != '\0'; icont++){
      if(texto[icont] == c){
        qtdOcorrencias++;
      }
    }
  }else{
      
    if(c >= 'A' && c <= 'Z'){
      for(icont = 0; texto[icont] != '\0'; icont++){
        if(texto[icont] >= 'a' && texto[icont] <= 'z'){
          if(texto[icont]-32 == c){
            qtdOcorrencias++;
          }
        }else {
          if(texto[icont] == c){
            qtdOcorrencias++;
          }
        }
      }
    }else if(c >= 'a' && c <= 'z'){
      for(icont = 0; texto[icont] != '\0'; icont++){
        if(texto[icont] >= 'A' && texto[icont] <= 'Z'){
          if(texto[icont]+32 == c){
            qtdOcorrencias++;
          }
        }else {
          if(texto[icont] == c){
            qtdOcorrencias++;
          }
        }
      }
    }else {
      if(texto[icont] == c){
            qtdOcorrencias++;
      }
    }
  }
  return qtdOcorrencias;
}


/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){
  int qtdOcorrencias = 0;
  int hcont, icont,jcont,kcont;
  int p1,p2=0;
  int ctrl;
  int char_espec = 0;
  int char_busca = 0;

  hcont=0;

  
  for(int lcont=0;strBusca[lcont]!= '\0';lcont++){
    if(strBusca[lcont] == -61){
      char_busca++;
    }
  }
  
  for(icont=0; strTexto[icont] != '\0'; icont++){
    jcont=0;
    ctrl = 0;
    if(strTexto[icont] == strBusca[jcont]){
      p1 = icont+1-char_espec;
      
    
      for(jcont=0, kcont = icont; strBusca[jcont] != '\0' && strTexto[kcont] != '\0'; jcont++, kcont++){
        if(strTexto[kcont]== -61){
          char_espec++;
        }
        if(strTexto[kcont] == strBusca[jcont]){
          ctrl++;
        }else {
          break;
        }
      }
      
      if(ctrl == Tam_String(strBusca)){
        p2 = kcont - char_espec;
        posicoes[hcont] = p1;
        posicoes[hcont+1] = p2;
        hcont+=2;
        qtdOcorrencias++;
      }
      
      icont += kcont - icont;
    }
    if(strTexto[icont]== -61){
        char_espec++;
      }
  }
  return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{ 
  int inicio = 0;
  int multi = 1;
  int num2 = 0;
  int num_aux = num;
  
  while(num_aux>0){
    if(num2!=0 && inicio==1){
      num2 = (num2*multi) + ((num_aux % 10)); 
      num_aux/=10;
      
    }else {
        num2 = (num_aux % 10);
        multi=10;
        num_aux/=10;
        inicio=1;
    }
  }
    num=num2;
    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */
//{2345} 34
int q6(int numerobase, int numerobusca)
{   
  int base = numerobase;
  int busca = numerobusca;
  int resto_base;
  int resto_busca;
  int tam_cont=0;
  int validacao = 0;
  
  int qtdOcorrencias = 0;

  //divide o numero base por 10 pegando o resto e vai comparando com o numerobusca de traz pra frente
    while (base!=0){
      resto_base = base % 10;
      resto_busca = busca % 10;

      if(resto_base==resto_busca){
        tam_cont++;
        busca /= 10;
        validacao=1;
      }else {
        validacao=0;
      }
      
      if(Verificar_Tam_de_Int(numerobusca) == tam_cont && validacao==1){
        qtdOcorrencias++;
        tam_cont = 0;
      }else if(validacao == 0 && Verificar_Tam_de_Int(busca) != Verificar_Tam_de_Int(numerobusca)){
        busca = numerobusca;
        tam_cont = 0;
      }else if (busca == 0 && numerobusca != 0){
        busca=numerobusca;
      }
      
      base /= 10;
    }
    
  
    return qtdOcorrencias;
}