#ifndef SARUDLIST_H
#define SARUDLIST_H

/* datatypes */
typedef struct node {
    struct node *next;
    struct node *prev;
    void *data;
} SDNode;

typedef struct saru_dlist {
    int size;
    struct node *head;
    struct node *tail;
    void (*destroy)(void *data);
} SDList;

/* public interface */
void sdlist_init(struct saru_dlist *dll, void (*destroy)(void *data));
void sdlist_destroy(struct saru_dlist *dll);
struct node *sdlist_next(struct node *node);

#define sdlist_size(list) (list.size)
#define sdlist_begin(list) list.head
#define sdlist_tail(list) (list.tail)

#define SDLIST_INIT(list, destroy) \
    struct saru_dlist list; \
    sdlist_init(&list, destroy)

#define sdlist_to_node(item) \
    _sdlist_to_node((void *)&item)

#define sdlist_pushback(list, item) \
    _sdlist_pushback(&list, _sdlist_to_node((void *)&item))

#define sdlist_pushfront(list, item) \
    _sdlist_pushfront(&list, _sdlist_to_node((void *)&item))

#define sdlist_at(type, itr) (type *)itr->data

/* private functions */
struct node *_sdlist_to_node(void *data);
int _sdlist_pushfront(struct saru_dlist *dll, struct node *node);
int _sdlist_pushback(struct saru_dlist *dll, struct node *node);
int _sdlist_insertafter(struct saru_dlist *dll, struct node *node, 
                                                struct node *new_node);
int _sdlist_insertbefore(struct saru_dlist *dll, struct node *node,
                                                 struct node *new_node);
int _sdlist_inserthead(struct saru_dlist *dll, struct node *node);
int _sdlist_inserttail(struct saru_dlist *dll, struct node *node);

void _sdlist_remove(struct saru_dlist *dll, struct node *node);

#endif

