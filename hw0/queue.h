#ifndef LAB0_QUEUE_H
#define LAB0_QUEUE_H

#include <stdbool.h>
#include <stddef.h>

// My link-list
typedef struct lle LLE;
struct lle{
    char *data;
    LLE *next_ptr;
};

// My link-list queue
typedef struct lqe LQE; 
struct lqe{
    LLE *head;
    LLE *tail;
};

// My "new" lqe function
LQE *lqe_new();

// My "free" lqe function
void lqe_free();

// My "insert head" lqe function
void lqe_insert_head();

// My "insert tail" lqe function
void lqe_insert_tail();

// My "remove head" lqe function
void lqe_remove_head();

// My "count size" lqe function
int lqe_size();

// My "reverse" lqe function
void lqe_reverse();

// My "sort" lqe function
void lqe_sort();

void lqe_print();


#endif
