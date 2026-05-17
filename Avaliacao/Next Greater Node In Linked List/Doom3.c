#include <stdio.h>
#include <stdlib.h>

// Structs recebem sufixo "_t"
struct listNode_t {
    int                 val;
    struct listNode_t * next;
};

/*
====================
NextLargerNodes
Percorre a lista encadeada e retorna um array com o proximo maior valor.
====================
*/
int * NextLargerNodes ( struct listNode_t * head, int * returnSize ) {
    int                 tam = 0;
    struct listNode_t * aux = head;
    int * resp;
    int * valores;
    int                 i;
    int                 j;

    while ( aux != NULL ) {
        tam++;
        aux = aux->next;
    }

    resp = (int *)malloc( sizeof( int ) * tam );
    // Corrigido: Substituindo o VLA por alocacao dinamica padrao
    valores = (int *)malloc( sizeof( int ) * tam ); 

    aux = head;
    i = 0;
    
    while ( aux != NULL ) {
        valores[ i ] = aux->val;
        aux = aux->next;
        i++;
    }

    for ( i = 0; i < tam; i++ ) {
        resp[ i ] = 0;

        for ( j = i + 1; j < tam; j++ ) {
            if ( valores[ j ] > valores[ i ] ) {
                resp[ i ] = valores[ j ];
                break;
            }
        }
    }

    // Corrigido: Desreferenciando o ponteiro para alterar o valor original
    *returnSize = tam; 

    free( valores );

    return resp;
}

/*
====================
Main
Ponto de entrada para testar a logica.
====================
*/
int main ( void ) {
    struct listNode_t   a;
    struct listNode_t   b;
    struct listNode_t   c;
    int                 tamanho;
    int * r;
    int                 i;

    a.val = 2;
    b.val = 1;
    c.val = 5;

    a.next = &b;
    b.next = &c;
    c.next = NULL;

    r = NextLargerNodes( &a, &tamanho );

    for ( i = 0; i < tamanho; i++ ) {
        printf( "%d ", r[ i ] );
    }

    // Corrigido: Liberando a memoria retornada pela funcao
    free( r ); 

    return 0;
}