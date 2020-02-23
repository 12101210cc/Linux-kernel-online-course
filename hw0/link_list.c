#include <stdio.h>
#include <stdlib.h>

// typedef int km_per_hour ;
// typedef int points ;
// km_per_hour current_speed ;  //"km_per_hour" is synonymous with "int" here,
// points high_score ;          //and thus, the compiler treats our new variables as integers.
// 在例子的最末處加入一行語句：
// typedef struct var newtype;
// 現在要建立類型 var 的變數時，程式碼可以寫為：
// newtype a;

typedef struct node Node;

struct node{
    int data;
    struct node *next_ptr;
};

int main(int argc, char *argv[])
{
    Node a,b,c;
    Node *ptr = &a;

    a.data = 12;
    a.next_ptr = &b;
    b.data = 30;
    b.next_ptr = &c;
    c.data = 66;
    c.next_ptr = NULL;

    while(ptr!=NULL)
    {
        printf("address=%p, ",ptr);
        printf("data=%d, ", ptr->data);
        printf("next_ptr=%p\n",ptr->next_ptr);
        ptr = ptr->next_ptr;
    }
    return 0;
}