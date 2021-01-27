/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: adair
 *
 * Created on 27 de Janeiro de 2021, 00:45
 */

#ifdef _WIN32
#include <conio.h>
#else
#define clrscr() printf("\e[1;1H\e[2J")
#endif

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void menu(queue *q);

int main(int argc, char** argv) {

    queue q;
    
    initializeQueue(&q);
    
    menu(&q);
    
    clear(&q);
        
    return 0;
}

void menu(queue *q){
    
    clrscr();
    printf("#############################################\n");
    printf("#                                           #\n");
    printf("# (1) TO ADD ITEM TO THE QUEUE, TYPE 1      #\n");
    printf("# (2) TO REMOVE ITEM FROM THE QUEUE, TYPE 2 #\n");
    printf("# (3) TO PRINT QUEUE ITEMS, TYPE 3          #\n");
    printf("# (4) TO EMPTY THE QUEUE, TYPE 4            #\n");
    printf("# (5) TO CLOSE APP, TYPE 5                  #\n");
    printf("#                                           #\n");
    printf("#############################################\n");
    
    int command = 0;
    
    scanf("%d", &command);
    
    if(command == 1){
        
        int value = 0;
        printf("TYPE A INTEGER NUMBER TO ADD TO THE QUEUE\n");
        scanf("%d", &value);
        enqueue(q, value);        
    }
    else if(command == 2){
        dequeue(q);
    }
    else if(command == 3){
        printQueue(q);
        printf("PRESS [ENTER] KEY TO CONTINUE");
        while(getchar()!='\n');
        getchar();
    }
    else if(command == 4){
        clear(q);
    }
    else if(command == 5){
        return;
    }
    else{
        printf("Command not found \n");
    }
    menu(q);
}
