#include "valloc.h"

void cat_next_chunk(mem_chunk_t *chunk)
{
    if (chunk->next && chunk->next->is_free) {
        chunk->size += chunk->next->size + sizeof(mem_chunk_t);
        chunk->next = chunk->next->next;
        if (chunk->next)
            chunk->next->prev = chunk;
    }
}

void cat_prev_chunk(mem_chunk_t *chunk)
{
    if (chunk->prev && chunk->prev->is_free) {
        chunk->prev->size += chunk->size + sizeof(mem_chunk_t);
        chunk->prev->next = chunk->next;
        if (chunk->next)
            chunk->next->prev = chunk->prev;
    }
}

void free_last_chunk(mem_chunk_t *chunk)
{
    mem_chunk_t **head = get_list_head();

    if (!chunk->prev)
        *head = NULL;
    else
        chunk->prev->next = NULL;
    sbrk((chunk->size + sizeof(mem_chunk_t)) * -1);
}

mem_chunk_t *find_chunk(void *ptr)
{
    mem_chunk_t **head = get_list_head();
    mem_chunk_t *tmp = *head;

    for (; tmp && tmp->ptr != ptr; tmp = tmp->next);
    return(tmp);
}

void my_free(void *ptr)
{
    mem_chunk_t *chunk = find_chunk(ptr);

    if(!chunk)
        return;
    if (!ptr)
        return;
    if (chunk->is_free)
        return;
    chunk->is_free = 1;
    if (chunk->next && chunk->next->is_free)
        cat_next_chunk(chunk);
    if (chunk->prev && chunk->prev->is_free)
        cat_prev_chunk(chunk);
    if (!chunk->next)
        free_last_chunk(chunk);
}