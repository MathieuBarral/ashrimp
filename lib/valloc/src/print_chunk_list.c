#include "valloc.h"

void print_chunk_list(void)
{
    mem_chunk_t **head = get_list_head();

    for (mem_chunk_t *tmp = *head; tmp; tmp = tmp->next) {
        printf("addr: %p, ptr: %p, size: %ld, is_free: %d, prev: %p, next: %p\n", tmp, tmp->ptr, tmp->size, tmp->is_free, tmp->prev, tmp->next);
    }
    printf("--------------------------------------------\n");
}