/* saru/dlist.c */
#include "saru-dlist.h"
#include <assert.h>
#include <stdlib.h>

/**
 * takes a destroy function pointer that is called on each data element
 * when destroyed, pass in NULL if not using heap-allocated data
 */
void
sdlist_init(struct saru_dlist *dll, void (*destroy)(void *data))
{
    dll->size = 0;
    dll->head = NULL;
    dll->tail = NULL;
    dll->destroy = destroy;
}

void
sdlist_insertbefore(struct saru_dlist *dll, struct node *node,
                                        struct node *new_node)
{
    assert(node && new_node && "Are verified by the caller.");

    new_node->next = node;

    /* check for insert at head */
    if (node->prev == NULL) {
        new_node->prev = NULL;
        dll->head = new_node;
    } else {
       new_node->prev = node->prev;
       node->prev->next = new_node;
    }
    node->prev = new_node;
    dll->size++;
}

void
sdlist_insertafter(struct saru_dlist *dll, struct node *node,
                                       struct node *new_node)
{
    assert(node && new_node && "Are verified by the caller.");
    
    new_node->prev = node;

    /* check for insert at tail */
    if (node->next == NULL) {
        new_node->next = NULL;
        dll->tail = new_node;
    } else {
        new_node->next = node->next;
        node->next->prev = new_node;
    }
    node->next = new_node;
    dll->size++;
}

void
sdlist_inserthead(struct saru_dlist *dll, struct node *node)
{
    /* check for empty list and add node */
    if (dll->head == NULL) {
        dll->head = node;
        dll->tail = node;
        node->prev = node->next = NULL;
    } else {
        sdlist_insertbefore(dll, dll->head, node);
    }
}

void 
sdlist_inserttail(struct saru_dlist *dll, struct node *node)
{
    /* check for empty list and add node */
    if (dll->tail == NULL) {
        dll->tail = node;
        dll->head = node;
        node->prev = node->next = NULL;
    } else {
        sdlist_insertbefore(dll, dll->tail, node);
    }
}

/**
 * removes a node, works with a 1 element list (sets head and tail to NULL)
 */
void
sdlist_remove(struct saru_dlist *dll, struct node *node)
{
    /* first node on list */
    if (node->prev == NULL)
        dll->head = node->next;
    else
        node->prev->next = node->next;

    /* last node on list */
    if (node->next == NULL)
        dll->tail = node->prev;
    else
        node->next->prev = node->prev;
}
