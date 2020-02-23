#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

LQE *lqe_new(){
	LQE *q = malloc(sizeof(LQE));
	if(q == NULL) printf("Something happend when you malloc new link-list queue, because the LQE is NULL.\n");
	q->head = NULL;
    q->tail = NULL;
	return q;
}

void lqe_free(LQE *q){
    LLE *current = NULL;
    while((q->head)!=NULL){
        current = q->head;
        q->head = q->head->next_ptr;
        free(current);
    }
    // LLE *prev = NULL;
    // while((q->tail)!=NULL){
    //     prev = q->tail;
    //     q->tail = q->tail->next_ptr;
    //     free(prev);
    // }
	free(q);
}

void lqe_insert_head(LQE *q, char *s){
	if(q == NULL){
        printf("Something happend when you isnert a head to LQE, because the LQE is NULL.\n"); 
    }
    else{
        //allocate more space for string s
        size_t len = strlen(s)+1;
        LLE *l= malloc(sizeof(LLE) + len);
        l->data = s;
        l->next_ptr = q->head;
        q->head = l;
    }
}
	

void lqe_insert_tail(LQE *q, char *s){
    if(q == NULL){
        printf("Something happend when you isnert a tail to LQE, because the LQE is NULL.\n"); 
    }
    else{
        //allocate more space for string s
        size_t len = strlen(s)+1;
        LLE *l= malloc(sizeof(LLE) + len);
        l->data = s;
        l->next_ptr = q->tail;
        q->tail = l;

        // LLE *current;
        // current = q->tail;
        // while(current->next_ptr!=NULL)
        // {
        //     current = current->next_ptr;
        // }
        // current->next_ptr=l;    
    }

}

void lqe_remove_head(LQE *q){
    if(q->head->next_ptr!=NULL){
        LLE *current = q->head->next_ptr;
        char *current_s = q->head->next_ptr->data;
        free(q->head);
        free(q->head->data);
        q->head = current;
        q->head->data = current_s;
    }
    else{
        
        q->head->data = NULL;
        q->head = NULL;
    }
    
}

int lqe_size(LQE *q)
{
    size_t size;

    return 0;
}

void lqe_print(LQE *q)
{
    printf(" ------Your LQE pointer address-------");
    printf("\n|  Your LQE      at:%16p  |",q);     
    if(q->head!=NULL){
        printf("\n|  Your LQE head at:%16p  +",q->head); 
        LLE *current = q->head;
        while(current!=NULL){
            printf("---->|  DATA:%10s, NEXT:%16p  |",current->data,current->next_ptr);
            current = current->next_ptr;
        }
        free(current);
    }
    else{
        printf("\n|  Your LQE head at:%16p  |",q->head); 
    }    
    
    if(q->tail!=NULL){
        printf("\n|  Your LQE head at:%16p  +",q->tail); 
        LLE *current = q->tail;
        while(current!=NULL){
            printf("---->|  DATA:%10s, NEXT:%16p  |",current->data,current->next_ptr);
            current = current->next_ptr;
        }
        free(current);
    }
    else{
        printf("\n|  Your LQE tail at:%16p  |",q->tail); 
    }    
    printf("\n -------------------------------------\n");
}