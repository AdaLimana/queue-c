/* 
 * File:   queue.h
 * Author: adair
 *
 * Created on 26 de Janeiro de 2021, 23:52
 */

#ifndef QUEUE_H
#define QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

    
#include<stdio.h>
#include<stdlib.h>
    
    typedef struct{
        
        int value;
        void *next;
    } item;
    
    typedef struct {
        
        int length;
        item *first;
        item *last;
        
    }queue;
    
    void initializeQueue(queue *q);
    
    void enqueue(queue *q, int value);
    
    int dequeue(queue *q);
    
    void clear(queue *q);
    
    void printQueue(queue *q);    

#ifdef __cplusplus
}
#endif

#endif /* QUEUE_H */

