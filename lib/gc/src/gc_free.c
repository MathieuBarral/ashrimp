#include "gc.h"

void gc_free(void *ptr)
{
    gc_t **head = get_gc_head();
    gc_t *tmp = *head;
    gc_t *buff = NULL;

    for (; tmp->next && tmp->next->ptr != ptr; tmp = tmp->next);
    if (tmp->next) {
        buff = tmp->next;
        tmp->next = tmp->next->next;
        my_free(buff->ptr);
        my_free(buff);
    }
}