#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int* nextLargerNodes(struct ListNode* head, int* returnSize) {

    int tam = 0;
    struct ListNode *aux = head;

    while(aux != NULL){
        tam++;
        aux = aux->next;
    }

    int *resp = malloc(sizeof(int) * tam);
    int valores[tam];

    aux = head;
    int i = 0;
    
    
    while(aux != NULL){
        valores[i] = aux->val;
        aux = aux->next;
        i++;
    }

    
    for(i = 0; i < tam; i++){

        resp[i] = 0;

        int j;
        for(j = i + 1; j < tam; j++){

            if(valores[j] > valores[i]){
                resp[i] = valores[j];
                break;
            }

        }

    }

    returnSize = tam;

    return resp;
}

int main(){

    struct ListNode a;
    struct ListNode b;
    struct ListNode c;

    a.val = 2;
    b.val = 1;
    c.val = 5;

    a.next = &b;
    b.next = &c;
    c.next = NULL;

    int tamanho;

    int *r = nextLargerNodes(&a, &tamanho);

    int i;
    for(i = 0; i < tamanho; i++){
        printf("%d ", r[i]);
    }

    return 0;
}