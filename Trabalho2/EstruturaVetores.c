#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TAM 10

#include "EstruturaVetores.h"

vet_P vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{

    int retorno = 0;
    vet_AUX* ponteiroAUX;
    
    
    if(tamanho < 0){
        tamanho = 0;
    }
    
    ponteiroAUX = malloc(tamanho* sizeof(vet_AUX));
    
    if(vetorPrincipal[posicao-1].head != NULL){
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    }else if(posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;
    }else if(tamanho < 1){
        retorno = TAMANHO_INVALIDO;
    }else if(ponteiroAUX == NULL){
        retorno = SEM_ESPACO_DE_MEMORIA;
    }else{ 
        // deu tudo certo, crie

        head *head_aux = malloc(sizeof(head));
        head_aux->prim = ponteiroAUX;
        head_aux->qtd = tamanho;
        head_aux->qtd_atual = 0;
        vetorPrincipal[posicao-1].head = head_aux;
        inicializarVetorAux(ponteiroAUX, tamanho);
        retorno = SUCESSO;
    }
    
    if(retorno != SUCESSO && retorno != SEM_ESPACO_DE_MEMORIA){
        free(ponteiroAUX);
    }
    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;
    int i = 0;
    
    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        posicao_invalida = 1;
    }
    if (posicao_invalida)
        retorno = POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        if(vetorPrincipal[posicao-1].head != NULL){
            existeEstruturaAuxiliar = 1;
        }
        if (existeEstruturaAuxiliar)
        {
            vet_AUX *aux = vetorPrincipal[posicao-1].head->prim;
            int qtd = vetorPrincipal[posicao-1].head->qtd;
            
            while(i < qtd){
                if(aux[i].cheio == 0){
                    temEspaco = 1;
                    break;
                }else{
                    i++; 
                }
            }
            if (temEspaco)
            {
                aux[i].chave = valor;
                aux[i].cheio = 1;
                vetorPrincipal[posicao-1].head->qtd_atual++;
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = 0;
    int i;
    int qtd_atual_aux;
    vet_AUX *aux = NULL;
    
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        retorno = POSICAO_INVALIDA;
    }else if (vetorPrincipal[posicao - 1].head == NULL){
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else{
        
        aux = vetorPrincipal[posicao - 1].head->prim;
        qtd_atual_aux = vetorPrincipal[posicao - 1].head->qtd_atual;
        
        if(qtd_atual_aux == 0){
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
        }else{
                
            aux[qtd_atual_aux - 1].cheio = 0;
            vetorPrincipal[posicao - 1].head->qtd_atual--;
            retorno = SUCESSO; 
        }
  
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno;
    int i , j;
    int qtd_atual_aux;
    int qtd_aux;
    int encontrou = 0;
    vet_AUX *aux = NULL;
    
    
        if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){
            retorno = POSICAO_INVALIDA;
        }else if (vetorPrincipal[posicao - 1].head == NULL){
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }else{

            aux = vetorPrincipal[posicao - 1].head->prim;
            qtd_atual_aux = vetorPrincipal[posicao - 1].head->qtd_atual;
            qtd_aux = vetorPrincipal[posicao - 1].head->qtd;
            
            if(qtd_atual_aux == 0){
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            }else{
                
                for(i = 0 ; i < qtd_aux; i++){
                    if(aux[i].chave == valor){
                        encontrou = 1;
                        
                        if(i == qtd_aux - 1 || i == qtd_atual_aux - 1){
                            aux[i].cheio = 0;
                            vetorPrincipal[posicao - 1].head->qtd_atual--;
                        }else{
                            j = i;
                            while(aux[j].chave == 1 && j <= qtd_aux - 2){
                                aux[j].chave = aux[j + 1].chave;
                                aux[j].cheio = aux[j + 1].cheio;
                                j++;
                            }
                            aux[j].cheio = 0;
                            vetorPrincipal[posicao - 1].head->qtd_atual--;
                        }
                        
                    }
                }
                if(encontrou == 0){
                    retorno = NUMERO_INEXISTENTE;
                }else{
                    retorno = SUCESSO;
                }
                
            }
    }
        
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0;
    vet_AUX *aux;
    
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        retorno = POSICAO_INVALIDA;
    }else if (vetorPrincipal[posicao - 1].head == NULL){
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else{
        aux = vetorPrincipal[posicao-1].head->prim;
        for(int i = 0 ; i < vetorPrincipal[posicao-1].head->qtd_atual ; i++){
            vetorAux[i] = aux[i].chave;
        }
        retorno = SUCESSO;
    }
    

    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0;
    
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        retorno = POSICAO_INVALIDA;
    }else if (vetorPrincipal[posicao - 1].head == NULL){
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else{
        int verif = getDadosEstruturaAuxiliar(posicao, vetorAux);
        
        
        if(verif == SUCESSO){
            InsertionSort(vetorAux, vetorPrincipal[posicao - 1].head->qtd_atual);
            retorno = SUCESSO;
        }
    }
    

    
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0;
    int estruturas_vazias = 1;
    int posicao_VP, posicao_VAux, posica_vetAux = 0;
    vet_AUX *aux;
    int qtd_atual_aux;
    
    for(posicao_VP = 0 ; posicao_VP < TAM ; posicao_VP++){
        if(vetorPrincipal[posicao_VP].head != NULL){
            if(vetorPrincipal[posicao_VP].head->qtd_atual != 0){
                estruturas_vazias = 0;
                aux = vetorPrincipal[posicao_VP].head->prim;
                qtd_atual_aux = vetorPrincipal[posicao_VP].head->qtd_atual;
                
                for(posicao_VAux = 0 ; posicao_VAux < qtd_atual_aux ; posicao_VAux++){
                    vetorAux[posica_vetAux] = aux[posicao_VAux].chave;
                    posica_vetAux++;
                }
                retorno = SUCESSO;
            }
        }
    }
    if(estruturas_vazias == 1){
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0;
    int verif = getDadosDeTodasEstruturasAuxiliares(vetorAux);
    int posicao_VP;
    int cont_tam = 0;
    vet_AUX * aux = NULL;

    
    if(verif == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS){
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }else{

        for(posicao_VP = 0 ; posicao_VP < TAM ; posicao_VP++){
            if(vetorPrincipal[posicao_VP].head != NULL){
                cont_tam += vetorPrincipal[posicao_VP].head->qtd_atual;
            }
        }
        InsertionSort(vetorAux, cont_tam);

        retorno = SUCESSO;
    }
    
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{   
    
    int retorno = 0;
    int tamanho_modif;
    vet_AUX *aux = NULL;
    
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        retorno = POSICAO_INVALIDA;
    }else if (vetorPrincipal[posicao - 1].head == NULL){
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else if (vetorPrincipal[posicao-1].head->qtd + novoTamanho < 1){
        retorno = NOVO_TAMANHO_INVALIDO;
    }else{
        tamanho_modif = vetorPrincipal[posicao-1].head->qtd + novoTamanho;
        
        vetorPrincipal[posicao-1].head->prim = realloc(vetorPrincipal[posicao-1].head->prim, (tamanho_modif)*sizeof(vet_AUX));
        
        if(tamanho_modif > vetorPrincipal[posicao-1].head->qtd){
            aux = vetorPrincipal[posicao-1].head->prim;
            for(int i = vetorPrincipal[posicao-1].head->qtd ; i < tamanho_modif ; i++){
                aux[i].cheio = 0;
            }
        }
        
        vetorPrincipal[posicao-1].head->qtd = tamanho_modif;

        if(vetorPrincipal[posicao-1].head->qtd_atual > vetorPrincipal[posicao-1].head->qtd){
            vetorPrincipal[posicao-1].head->qtd_atual = vetorPrincipal[posicao-1].head->qtd;
        }
        if(vetorPrincipal[posicao-1].head->prim == NULL){
            retorno = SEM_ESPACO_DE_MEMORIA;
        }else{
            retorno = SUCESSO;
        }
    }
    
    
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    int retorno = 0;
    
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        retorno = POSICAO_INVALIDA;
    }else if (vetorPrincipal[posicao - 1].head == NULL){
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else if (vetorPrincipal[posicao-1].head->qtd_atual == 0){
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }else{
        
        int qtd_atual_aux = vetorPrincipal[posicao-1].head->qtd_atual;
        retorno = qtd_atual_aux;
    }
    

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    No *head = NULL;
    No *aux_1 = NULL;
    No *aux_2 = NULL;
    
    int n = getQuantidadeElementosVetorPrincipal();
    
    if(n > 0){
        int vetor[n];
        getDadosDeTodasEstruturasAuxiliares(vetor);
        for(int i = 0 ; i < n ; i++){
            if(i == 0){
                head = malloc(sizeof(No));

                if(head != NULL){
                    head->conteudo = vetor[i];
                    head->prox = NULL;
                    aux_1 = head;
                }
                
            }else{
                aux_2 = malloc(sizeof(No));

                if(aux_2 != NULL){
                    aux_2->conteudo = vetor[i];
                    aux_1->prox = aux_2;
                    aux_1 = aux_2;
                }
            }
        }
        return head;
        
    }else{
        return NULL;
    }
    
    
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{

    No *aux = inicio;
    int posicao = 0;
    
    while (aux != NULL){
        vetorAux[posicao] = aux->conteudo;
        aux = aux->prox;
        posicao++;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    No *aux = *inicio;
    No *aux_2 = NULL;
    int posicao = 0;

    while (aux != NULL){
        *inicio = aux->prox;
        free(aux);
        aux = *inicio;
    }
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    for(int i = 0 ; i < TAM ; i++){
        if(i == 9){
            vetorPrincipal[i].head = NULL;
        }
    }
    
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    vet_AUX *aux_1;
    vet_AUX *aux_2;

    
    for(int i = 0 ; i < TAM ; i++){
        if(vetorPrincipal[i].head != NULL){
            aux_1 = vetorPrincipal[i].head->prim;
            for (i = 0 ; i < vetorPrincipal[i].head->qtd ; i++){
                aux_2 = aux_1 + 1;
                free(aux_1);
                aux_1 = aux_2;

            }
            
        }
        free(vetorPrincipal[i].head);
            
    }
}

void inicializarVetorAux(vet_AUX *V , int tamanho){
    for(int i = 0 ; i < tamanho ; i++){
            V[i].cheio = 0;
    }
}

void InsertionSort(int *V,int n){
  int icont,jcont,aux;
  for(icont=0;icont<n-1;icont++){
    for(jcont=icont+1;jcont>0;jcont--){
      if(V[jcont-1]>V[jcont]){
        aux=V[jcont];
        V[jcont] = V[jcont-1];
        V[jcont-1] = aux;
      }
    }
  }
}
    
int getQuantidadeElementosVetorPrincipal(){
    int cont_tam = 0;
    int posicao_VP;

    for(posicao_VP = 0 ; posicao_VP < TAM ; posicao_VP++){
        if(vetorPrincipal[posicao_VP].head != NULL){
            cont_tam += vetorPrincipal[posicao_VP].head->qtd_atual;
        }
    }
    return cont_tam;
}