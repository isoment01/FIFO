#ifndef FIFO_H
#define FIFO_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
/*
 * Generic FIFO in C.
 * Dynamic Allocated Circular Buffer.
 * */
/*
 * Users may scale head and tail pointers size if need.
 * NOTE: pointer types must be signed.(For ex.:int8,16,32 etc.)
 * */
typedef int32_t fifo_ptr_size_t;
/*
 * default  pointer size is int32_t.
 * */
typedef struct fifo* fifo_t;
fifo_t          open_FIFO(void);
void            init_FIFO(fifo_t fifo, size_t data_size, size_t total_capacity);
void            write_FIFO(fifo_t fifo, const void* data);
void*           read_FIFO(fifo_t fifo, void * read_buffer);
int32_t         get_front(fifo_t fifo);
int32_t         get_rear(fifo_t fifo);
size_t          get_capacity(fifo_t fifo);
void            close_FIFO(fifo_t fifo);
#endif // FIFO_H
