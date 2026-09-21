/*
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 24/09/2024 para a disciplina CI1001 - Programação 1.
 */

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include "racional.h"

#define TAM 100

/* coloque aqui as funções auxiliares que precisar neste arquivo */

/*Função para preencher o vetor de racionais*/
void preencha_vetor(struct racional vetor[], int *n)
{
    scanf("%d", n);

    long num, den;

    for (int i = 0; i < *n; i++){

        scanf("%ld %ld", &num, &den);
        vetor[i] = cria_r(num, den);

    }

}

/*Imprime o Vetor de números racionais*/
void imprima_vetor(struct racional vetor[], int n){

    printf("VETOR = ");
    
    for (int i = 0; i < n; i++){

        imprime_r(vetor[i]);
        if ( i <= n-2)
            printf(" ");

    }

    printf("\n");

}

/*Eliminar os números inválidos*/
void elimina_invalido(struct racional vetor[], int *n){
    
    int novo_n = 0;

    for ( int i = 0; i < *n; i++){

        if (valido_r(vetor[i])){

            vetor[novo_n] = vetor[i];
            novo_n++;

        }
    }

    *n = novo_n;

}

/* Função para ordenar o vetor de racionais*/
/*Insertion short */
void ordena_vetor(struct racional v[], int n) {
    for (int i = 1; i < n; i++) {
        struct racional chave = v[i];
        int j = i - 1;
        
        while (j >= 0 && compara_r(v[j], chave) > 0) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

/*Soma de todos elementos do vetor*/
struct racional somar( struct racional vetor[], int n){
    
    struct racional soma = cria_r(0, 1);

    for (int i = 0; i < n; i++){
        
        soma_r(soma, vetor[i], &soma);

    }
    
    return soma;
}


/* programa principal */
int main()
{

    int n;
    struct racional vetor[TAM];

    /*Lê os elementos do vetor pelo arquivo de entrada e imprime o vetor*/
    preencha_vetor(vetor, &n);
    imprima_vetor(vetor, n);

    /*Elimina do vetor os racionais inavalidos e imprime eles*/
    elimina_invalido(vetor, &n);   
    imprima_vetor(vetor, n); 

    /*Ordena o vetor e imprime o vetor ordenado*/
    ordena_vetor(vetor, n);    
    imprima_vetor(vetor, n);

    struct racional soma = somar(vetor, n);

    printf("SOMA = ");
    imprime_r(soma);
    printf("\n");





    

    return (0);
}
