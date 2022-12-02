#ifndef VALLOC_H
    #define VALLOC_H

    #include <unistd.h>
    #include <stdio.h>
    #include <sys/types.h>

    // Memory chunk list template structure
    typedef struct mem_chunk_s{
        void *ptr;
        size_t size;
        int is_free;
        struct mem_chunk_s *prev;
        struct mem_chunk_s *next;
    } mem_chunk_t;

    /**
     * @brief Allocate memory of given size
     *
     * @param size Size of memory zone to allocate
     *
     * @return New memory zone pointer
     */
    void *my_malloc(size_t size);

    /**
     * @brief Free given memory zone
     *
     * @param ptr Pointer of desired memory zone to free
     */
    void my_free(void *ptr);

    /**
     * @brief Get the memory list head
     *
     * @return Memory list head double pointer
     */
    mem_chunk_t **get_list_head(void);

    /**
     * @brief Print memory current status
     */
    void print_chunk_list(void);

#endif