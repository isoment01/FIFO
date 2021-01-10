#include <stdio.h>
#include "fifo.h"

int main(void)
{
    fifo_t my_fifo;
    uint16_t dizi[10];
    uint16_t read_buf=0;
    my_fifo= open_FIFO();
    size_t element_count=5;
    init_FIFO(my_fifo, sizeof (uint16_t),element_count);
    for(size_t i=0; i<element_count; i++)
    {
        dizi[i]= i*element_count;
    }
    printf("Front: %i, Rear: %i\n", get_front(my_fifo), get_rear(my_fifo));
    write_FIFO(my_fifo, &dizi[0]);//01
    printf("Front: %i, Rear: %i\n", get_front(my_fifo), get_rear(my_fifo));
    write_FIFO(my_fifo, &dizi[1]);//02
    printf("Front: %i, Rear: %i\n", get_front(my_fifo), get_rear(my_fifo));
    write_FIFO(my_fifo, &dizi[2]);//03
    printf("Front: %i, Rear: %i\n", get_front(my_fifo), get_rear(my_fifo));
    write_FIFO(my_fifo, &dizi[3]);//04
    printf("Front: %i, Rear: %i\n", get_front(my_fifo), get_rear(my_fifo));
    write_FIFO(my_fifo, &dizi[4]);//05
    printf("Front: %i, Rear: %i\n", get_front(my_fifo), get_rear(my_fifo));
    read_FIFO(my_fifo, &read_buf);
    read_FIFO(my_fifo, &read_buf);
    read_FIFO(my_fifo, &read_buf);
    read_FIFO(my_fifo, &read_buf);
    read_FIFO(my_fifo, &read_buf);
    read_FIFO(my_fifo, &read_buf);
    printf("Front: %i, Rear: %i\n", get_front(my_fifo), get_rear(my_fifo));
    close_FIFO(my_fifo);


}
