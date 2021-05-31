/* saru/dlist.c */
#include "saru-dlist.h"
#include <assert.h>
#include <stdlib.h>

void
sdll_init(struct saru_dll *dll)
{
    dll->size = 0;
    dll->head = NULL;
    dll->tail = NULL;
}

void
sdll_insertbefore(struct saru_dll *dll, struct node *node,
                                        struct node *new)
{
    assert(node && new && "Are verified by the caller.");

    new->next = node;

    /* check for insert at head */
    if (node->prev == NULL) {
        new->prev = NULL;
        dll->head = new;
    } else {
       new->prev = node->prev;
       node->prev->next = new;
    }
    node->prev = new;
    dll->size++;
}

void
sdll_insertafter(struct saru_dll *dll, struct node *node,
                                       struct node *new)
{
    assert(node && new && "Are verified by the caller.");
    
    new->prev = node;

    /* check for insert at tail */
    if (node->next == NULL) {
        new->next = NULL;
        dll->tail = new;
    } else {
        new->next = node->next;
        node->next->prev = new;
    }
    node->next = new;
    dll->size++;
}

void
sdll_inserthead(struct saru_dll *dll, struct node *node)
{
    /* check for empty list and add node */
    if (dll->head == NULL) {
        dll->head = node;
        dll->tail = node;
        node->prev = node->next = NULL;
    } else {
        sdll_insertbefore(dll, dll->head, node);
    }
}

void 
sdll_inserttail(struct saru_dll *dll, struct node *node)
{
    /* check for empty list and add node */
    if (dll->tail == NULL) {
        dll->tail = node;
        dll->head = node;
        node->prev = node->next = NULL;
    } else {
        sdll_insertbefore(dll, dll->tail, node);
    }
}
