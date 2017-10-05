#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

void make_tree(arvbin * t, int n, int in_i, int in[], int pos_i, int pos[]);
int get_index(int arr[], int comeco, int fim, int valor);

int main()
{
    arvbin t;
    tree_init(&t);
    int n, i;
    scanf("%d", &n);

    //int emOrdem[n], posOrdem[n];

    int emOrdem[] = {5,4,20,9,8,10,18,15};
    int posOrdem[] = {4,5,9,20,18,10,15,8};

    //for (i = 0; i < n; i++)
      //  scanf("%d", &emOrdem[i]);

    //for (i = 0; i < n; i++)
      //  scanf("%d", &posOrdem[i]);

     make_tree(&t, n-1, 0, emOrdem, 0, posOrdem);

    //int indice;

    //indice = get_index(emOrdem, 0, 7, 8);

    pre_ordem(t);

    return 0;
}

void make_tree(arvbin * t, int n, int in_i, int in[], int pos_i, int pos[]) {

    /*if (pos_i == 0) {
        (*t)->dado = pos[pos_i];
        (*t)->esq = (*t)->dir = NULL;
    }
    else {
        (*t)->dado = pos[pos_i];
        int indice = get_index(in, in_i, pos_i, pos[pos_i]);
        make_tree(&t->esq, indice, 0, in, 0, pos);
        make_tree(&t->dir, )
    }*/
    int dado = pos[n];
    tree_ins(&(*t), pos[n]);
    int indexIn = get_index(in, in_i, n, pos[n]);

    if (indexIn > 0)
        make_tree(&(*t)->esq, indexIn-1, 0, in, 0, pos);
    if (indexIn < n)
        make_tree(&(*t)->dir, n-1, indexIn, in, indexIn, pos);
}

int get_index(int arr[], int comeco, int fim, int valor) {
    int i = 0;

    while ((i<=fim) && (arr[i] != valor)) i++;
    return i <= fim ? i : fim;
}
