#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

void make_tree(arvbin *t, int in_i, int in_f, int in[], int pos_i, int pos_f, int pos[]);
int get_index(int arr[], int comeco, int fim, int valor);

int main()
{
    arvbin t;
    tree_init(&t);
    int n, i;
    scanf("%d", &n);

    int emOrdem[n], posOrdem[n];

    for (i = 0; i < n; i++)
       scanf("%d", &emOrdem[i]);

    for (i = 0; i < n; i++)
       scanf("%d", &posOrdem[i]);

    make_tree(&t, 0, n-1, emOrdem, 0, n-1, posOrdem);

    pre_ordem(t);

    return 0;
}

void make_tree(arvbin *t, int in_i, int in_f, int in[], int pos_i, int pos_f, int pos[]) {
    
    if ((in_i > in_f) || (pos_i > pos_f)) return;

    int dado = pos[pos_f];
    tree_ins(&(*t), dado);

    int indexIn = get_index(in, in_i, in_f, pos[pos_f]);

    // Pegando o tamanho das próximas subárvores
    int tamEsq = indexIn - in_i;
    int tamDir = in_f - indexIn;

    // Ajustando os valores das posições inicial e final da em-Ordem e pós-Ordem
    int ini_emOrder = indexIn+1;
    int fim_emOrder = in_f;
    int ini_posOrder = pos_f-tamDir;
    int fim_posOrder = pos_f-1;

    // Chamada recursiva pra subárvores direita com os novos valores
    make_tree(&(*t)->dir, ini_emOrder, fim_emOrder, in, ini_posOrder, fim_posOrder, pos);

    // Ajustando os valores das posições inicial e final da em-Ordem e pós-Ordem
    ini_emOrder = in_i;
    fim_emOrder = indexIn - 1;
    ini_posOrder = pos_f-tamDir-tamEsq;
    fim_posOrder = pos_f-tamDir-1;

    // Chamada recursiva pra subárvores esquerda com os novos valores
    make_tree(&(*t)->esq, ini_emOrder, fim_emOrder, in, ini_posOrder, fim_posOrder, pos);
}

int get_index(int arr[], int comeco, int fim, int valor) {
    int i = comeco;

    while ((i<=fim) && (arr[i] != valor)) i++;
    return i;
}