/* saru/dlist.c */
#include <assert.h>
#include <stdlib.h>
#include "saru-dlist.h"

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

struct node *
sdlist_next(struct node *node)
{
    return node->next;
}

/**
 * destroys the entire list, calling the destroy function
 * on each element if it was passed into the init function
 */
void 
sdlist_destroy(struct saru_dlist *dll)
{
    struct node *curr = dll->tail;
    struct node *temp = NULL;
    for (;curr != NULL; curr = temp->prev) {
        temp = curr;
        _sdlist_remove(dll, curr);
    }
}

/**
 * allocates and returns a new node with the passed-in data
 * caller should check for NULL pointer
 */
struct node *
_sdlist_to_node(void *data)
{
    assert(data && "Is verified by the caller.");
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node) {
        new_node->data = data;
        new_node->next = new_node->prev = NULL;
    }
    return new_node;
}

/**
 * appends a node to the tail of the list
 * returns 0 on success, -1 otherwise
 */
int
_sdlist_pushback(struct saru_dlist *dll, struct node *node)
{
    return _sdlist_inserttail(dll, node);   
}

/**
 * appends a node to the head of the list
 * returns 0 on success, -1 otherwise
 */
int
_sdlist_pushfront(struct saru_dlist *dll, struct node *node)
{
    return _sdlist_inserthead(dll, node);   
}

int
_sdlist_insertbefore(struct saru_dlist *dll, struct node *node,
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
    return 1;
}

int
_sdlist_insertafter(struct saru_dlist *dll, struct node *node,
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
    return 1;
}

/* the passed in node becomes the new head */
int
_sdlist_inserthead(struct saru_dlist *dll, struct node *node)
{
    /* check for empty list and add node */
    if (dll->head == NULL) {
        dll->head = node;
        dll->tail = node;
        node->prev = node->next = NULL;
    } else {
        return _sdlist_insertbefore(dll, dll->head, node);
    }
    return 0;
}

/* the passed in node becomes the new tail */
int
_sdlist_inserttail(struct saru_dlist *dll, struct node *node)
{
    /* check for empty list and add node */
    if (dll->tail == NULL) {
        dll->tail = node;
        dll->head = node;
        node->prev = node->next = NULL;
    } else {
        return _sdlist_insertafter(dll, dll->tail, node);
    }
    return 0;
}

/**
 * removes a node, works with a 1 element list (sets head and tail to NULL)
 */
void
_sdlist_remove(struct saru_dlist *dll, struct node *node)
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

    if (dll->destroy)
        dll->destroy(node->data);
    free(node);
    node = NULL;
    dll->size--;
}

