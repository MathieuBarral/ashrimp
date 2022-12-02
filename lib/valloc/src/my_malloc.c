#include "valloc.h"
#include "utils.h"

mem_chunk_t **get_list_head(void)
{
    static mem_chunk_t *head = NULL;

    return (&head);
}

mem_chunk_t *alloc_chunk(mem_chunk_t **head, size_t size)
{
    mem_chunk_t *tmp = *head;
    mem_chunk_t *new_chunk = sbrk(0);
    void *p = sbrk(size + sizeof(mem_chunk_t));

    if (size <= 0)
        return (NULL);
    if (p != (void *) -1) {
        new_chunk->ptr = (void *)(new_chunk + 1);
        new_chunk->size = size;
        new_chunk->is_free = 0;
        new_chunk->prev = NULL;
        new_chunk->next = NULL;
        if (!(*head))
            *head = new_chunk;
        else {
            for (; tmp->next; tmp = tmp->next);
            new_chunk->prev = tmp;
            tmp->next = new_chunk;
        }
        return (new_chunk);
    }
    return (NULL);
}

void split_chunk(mem_chunk_t *chunk, size_t size)
{
    mem_chunk_t *new_chunk = chunk->ptr + size;

    new_chunk->size = chunk->size - size - sizeof(mem_chunk_t);
    new_chunk->is_free = 1;
    new_chunk->ptr = (void *)(new_chunk + 1);
    new_chunk->next = chunk->next;
    new_chunk->prev = chunk;
    if (chunk->next)
        chunk->next->prev = new_chunk;
    chunk->size = size;
    chunk->is_free = 0;
    chunk->next = new_chunk;
}

mem_chunk_t *check_free_chunk(mem_chunk_t **head, size_t size)
{
    mem_chunk_t *tmp = *head;

    for (; tmp && !(tmp->is_free && tmp->size >= size); tmp = tmp->next);
    return (tmp);
}

void *my_malloc(size_t size)
{
    mem_chunk_t **head = get_list_head();
    mem_chunk_t *tmp = NULL;

    if (size <= 0)
        return (NULL);
    tmp = check_free_chunk(head, size);
    if (tmp) {
        if (tmp->size > (size + sizeof(mem_chunk_t))) {
            split_chunk(tmp, size);
            return (tmp + 1);
        } else if (tmp->size == size) {
            tmp->is_free = 0;
            return (tmp + 1);
        }
    }
    tmp = alloc_chunk(head, size);
    if (!tmp)
        return (NULL);
    return (tmp + 1);
}