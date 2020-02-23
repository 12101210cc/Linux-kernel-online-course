#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int main(int argc, char *argv)
{
    LQE *my_lqe = lqe_new();
    printf("When you create new LQE\n");
    lqe_print(my_lqe);

    
    lqe_insert_head(my_lqe,"TSMC");
    printf("\nAfter insert 'TSMC' in the head\n");
    lqe_print(my_lqe);

    lqe_insert_head(my_lqe,"Intel");
    printf("\nAfter insert 'Intel' in the head\n");
    lqe_print(my_lqe);

    lqe_insert_tail(my_lqe,"AMD");
    printf("\nAfter insert 'AMD' in the tail\n");
    lqe_print(my_lqe);

    lqe_insert_tail(my_lqe,"Samsung");
    printf("\nAfter insert 'Samsung' in the tail\n");
    lqe_print(my_lqe);

    lqe_remove_head(my_lqe);
    printf("\nAfter remove one element in the head\n");
    lqe_print(my_lqe);
    
    lqe_remove_head(my_lqe);
    printf("\nAfter remove one element in the head\n");
    lqe_print(my_lqe);

    lqe_insert_tail(my_lqe,"fuck~");
    printf("Your LQE tail at:%p\t",my_lqe->tail);
    printf("Your LQE tail (LLE) data:%s\n",my_lqe->tail->data);
    lqe_insert_tail(my_lqe,"Hello there~");
    printf("Your LQE tail at:%p\t",my_lqe->tail);
    printf("Your LQE tail (LLE) data:%s\n",my_lqe->tail->data);
    printf("Your LQE next at:%p\t",my_lqe->tail->next_ptr);
    printf("Your LQE next (LLE) data:%s\n",my_lqe->tail->next_ptr->data);
    printf("q at : %p\n",my_lqe);
    lqe_free(my_lqe);
    printf("q at : %p\n",my_lqe);
    printf("head at:%p\n",my_lqe->head);
    printf("Your LQE tail after free at:%p\t",my_lqe->tail);
    printf("Your LQE tail after free (LLE) data:%s\n",my_lqe->tail->data);
    printf("all done!\n");
}