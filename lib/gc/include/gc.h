#ifndef GC_H
    #define GC_H

    #include <stdlib.h>

    #include "valloc.h"

    // Garbage collector list template structure
    typedef struct gc_s {
        void *ptr;
        struct gc_s *next;
    } gc_t;

    /**
     * @brief Get the garbage collector list head
     *
     * @return Garbage collector list head double pointer
     */
    gc_t **get_gc_head(void);

    /**
     * @brief Allocate memory of given size and put pointer in garbage collector list
     *
     * @param size Size of memory zone to allocate
     *
     * @return New memory zone pointer
     */
    void *gc_malloc(size_t size);

    /**
     * @brief Free given memory zone
     *
     * @param ptr Pointer of desired memory zone to free
     */
    void gc_free(void *ptr);

#endif