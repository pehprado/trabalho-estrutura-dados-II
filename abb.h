/* 
 * abb.h
 *
 * Definição do TAD Árvore Binária de Busca (ABB) e protótipo
 * de suas operações.
 *
 * Ciro C. Trindade
 *
 * 22/ago/2017
 */

#ifndef _ABB_H
#define _ABB_H

#include <stdbool.h>
 
typedef int tree_info;
typedef struct no_arvbin * arvbin;
struct no_arvbin {
    arvbin esq;
    tree_info dado;
    arvbin dir;
};

/* Inicializa a ABB */
void tree_init(arvbin *);

/* Insere um novo elemento na ABB */
void tree_ins(arvbin *, tree_info);

/* Realiza uma busca na ABB */
arvbin tree_fnd(arvbin, tree_info);

/* Remove um elemento da ABB. Devolve verdadeiro se a remoção
 * foi bem sucedida ou falso, caso contrário. */
bool tree_rem(arvbin *, tree_info);

/* Realiza o percurso em­ordem da árvore binária */
void em_ordem(arvbin);

/* Realiza o percurso pré­ordem da árvore binária */
void pre_ordem(arvbin);

/* Realiza o percurso pós­ordem da árvore binária */
void pos_ordem(arvbin); 

/* Libera todos os nós da árvore binária */
void tree_kill(arvbin *);

#endif
