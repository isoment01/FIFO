#include"fifo.h"
/*
 * make this FIFO encapsulated and hided.
 * */
typedef struct fifo
{
    void*               circular_buffer;//make this FIFO generic.
    int32_t             front;
    int32_t             rear;
    size_t              capacity;
    size_t              data_lenght;

}_fifo;
static _Bool is_full_flag=0;
static _Bool is_buffer_empty(fifo_t fifo)
{
    if((fifo->front == fifo->rear) && (is_full_flag==0))
    return  true;
    else
        return false;
}

static _Bool is_buffer_full(void)
{
    return is_full_flag;
}

static void enqueue(fifo_t fifo, const void* data)
{
    if(is_buffer_full()==true)
    {
        printf("fifo is full\n");
        return;
    }
    else
    {
        memcpy((fifo->circular_buffer+(fifo->rear*fifo->data_lenght)), data, fifo->data_lenght);//Push
        fifo->rear = (fifo->rear+1)%(fifo->capacity);//rear incremented.
        if(fifo->rear==fifo->front)
           is_full_flag= true;
    }
}

static void* dequeue(fifo_t fifo, void * read_buffer)
{
    if(is_buffer_empty(fifo)==true)
    {
        printf("fifo is empty\n");
        return NULL;
    }    
    else
    {
        memcpy(read_buffer, (fifo->circular_buffer+((fifo->front)*fifo->data_lenght)), fifo->data_lenght);//Pop
        fifo->front = (fifo->front+1)%(fifo->capacity);//front incremented.
        is_full_flag= false;
    }
    return read_buffer;
}
/*
 * This function creates a fifo.
 * User must create an object in type of fifo_t before call this function.
 * */
fifo_t open_FIFO()
{
    return (_fifo*)malloc(sizeof(_fifo));
}
/*
 * This function gives allocated memory back to avoid memory leaks.
 * This functions must call when FIFO's works are ended.
 * */
void close_FIFO(fifo_t fifo)
{
    free(fifo->circular_buffer);
    free(fifo);
}
void init_FIFO(fifo_t fifo, size_t data_size, size_t total_capacity)
{
    assert(fifo);
    fifo->capacity= total_capacity;
    fifo->data_lenght= data_size;
    fifo->circular_buffer= malloc(total_capacity*data_size);
    fifo->front=0;
    fifo->rear= 0;
}
void write_FIFO(fifo_t fifo, const void* data)
{
    enqueue(fifo, data);
}
void* read_FIFO(fifo_t fifo, void * read_buffer)
{
    return dequeue(fifo, read_buffer);
}
/*void print_FIFO(fifo_t fifo)
{
    for(size_t i=0; i<fifo->capacity; i++)
    {
        printf("circular_buffer[%llu]= %hu\n", i, *(uint16_t*)(fifo->circular_buffer+(i*fifo->data_lenght)));
    }
}*/
fifo_ptr_size_t get_front(fifo_t fifo)
{
    return fifo->front;
}
fifo_ptr_size_t get_rear(fifo_t fifo)
{
    return fifo->rear;
}
size_t get_capacity(fifo_t fifo)
{
    return fifo->capacity;
}
