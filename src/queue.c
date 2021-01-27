#include "queue.h"

void initializeQueue(queue *q){
    
    q->length = 0;
    q->first = 0;
    q->last = 0;
}

void enqueue(queue *q, int value){
    
    item *i = (item*) malloc(sizeof(item));
    i->value = value;
    i->next = 0;
    
    if(q->length == 0){
        
        q->first = i;
        q->last = i;
        q->length++;
    }
    else{
        
        item *old_last = q->last;
        old_last->next = i;
        q->last = i;
        q->length++;
    }    
}


int dequeue(queue *q){
    
    if(q->length == 0){
        printf("Empty Stack\n");
        return 0;
    }
    
    item *first = q->first;
    q->first = first->next;
    q->length--;
    
    int value = first->value;
    
    free(first);
    
    return value;    
}


void clear(queue *q){
    
    item *i = q->first;
    
    while(i){
        
        q->first = i->next;
        q->length--;
        free(i);
        i = q->first;
    }
}

void printQueue(queue *q){

    item *i = q->first;
    
    if(q->length == 0){
        printf("Empty Stack\n");
    }
    
    printf("########\n");
        
    while(i){ 
        printf("# %4d #\n", i->value);
        printf("########\n");
        i = i->next;
    }
}

