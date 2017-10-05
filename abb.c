/*
 * abb.c
 *
 * Implementações das operações realizadas sobre o TAD ABB 
 *
 * Ciro C. Trindade
 *
 * 22/ago/2017
 */

#include "abb.h"
#include <stdio.h>
#include <stdlib.h>

/* Inicializa a ABB */
void tree_init(arvbin * t)
{
	*t = NULL;
}


/* Insere um novo elemento x na ABB t */
void tree_ins(arvbin * t, tree_info x) 
{
    if (*t == NULL) {
        if ((*t = (arvbin) malloc(sizeof(struct no_arvbin))) == NULL) {
            fprintf(stderr,"Erro de alocação de memória!\n");
            exit(1);
        }
        (*t)->dado = x;
        (*t)->esq = (*t)->dir = NULL;
    }
    else
        if (x < (*t)->dado) tree_ins(&(*t)->esq, x);
        else tree_ins(&(*t)->dir, x);
}

/* Realiza uma busca pelo valor x na ABB t */
arvbin tree_fnd(arvbin t, tree_info x) 
{
    if (t == NULL) 
        return NULL;
    else
        if (x == t->dado) return t;
        else
            if (x < t->dado) return tree_fnd(t->esq, x);
            else return tree_fnd(t->dir, x);
}

/* Retira e devolve o menor elemento da ABB */
arvbin getmin(arvbin * t) 
{   
    if ((*t)->esq == NULL) {
        arvbin p = *t;
        *t = (*t)->dir;
        return p;
    }
    else
        return getmin(&(*t)->esq);
}

/* Remove um elemento x da ABB t. Devolve verdadeiro se a remoção
 * foi bem sucedida ou falso, caso contrário. */
bool tree_rem(arvbin * t, tree_info x) 
{
    if (*t == NULL) return false;
    else {
        if (x == (*t)->dado) {
            arvbin p = *t;
            if ((*t)->esq == NULL)  // a árvore não tem filho esquerdo
                *t = (*t)->dir;  // o filho direito passa a ser a raiz
            else {
                // a árvore não tem filho direito
                if ((*t)->dir == NULL)
                    // o filho esquerdo passa a ser a raiz 
                    *t = (*t)->esq;     
                else  {  // a raiz tem ambos os filhos
                    p = getmin(&(*t)->dir);
                    (*t)->dado = p->dado;
                }
            }
            free(p);
            return true;
        }
        else {
            if (x < (*t)->dado)
                // procura na subárvore esquerda
                return tree_rem(&(*t)->esq, x);  
            else
                // procura na subárvore direita
                return tree_rem(&(*t)->dir, x); 
        }
    }
}

/* Realiza o percurso em­ordem da árvore binária t */
void em_ordem(arvbin t) 
{
    if (t != NULL) {
        em_ordem(t->esq);  // visita a subárvore esquerda
        printf("%d ", t->dado); // processa a raiz
        em_ordem(t->dir);  // visita a subárvore direita
    }
}

/* Realiza o percurso pré­-ordem da árvore binária t */
void pre_ordem(arvbin t)
{
    if (t != NULL) {
        printf("%d ", t->dado); // processa a raiz
        pre_ordem(t->esq); // visita a subárvore esquerda
        pre_ordem(t->dir); // visita a subárvore direita
    }
}

/* Realiza o percurso pós-ordem da árvore binária t */
void pos_ordem(arvbin t) 
{
    if (t != NULL) {
        pos_ordem(t->esq); // visita a subárvore esquerda
        pos_ordem(t->dir); // visita a subárvore direita
        printf("%d ", t->dado); // processa a raiz
    }
}
        

/* Libera todos os nós da árvore binária t */
void tree_kill(arvbin * t) 
{
    if (*t != NULL) {
        tree_kill(&(*t)->esq);
        tree_kill(&(*t)->dir);
        free(*t);
        *t = NULL;
    }
}
