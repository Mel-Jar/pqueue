//
// Created by Mason Landis on 2/14/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_NAME_LENGTH 64

typedef struct {
    char title[MAX_NAME_LENGTH];
    char artist[MAX_NAME_LENGTH];
} Song;
typedef struct PQueueStruct {
    int priority;
    void *data;
    struct PQueueStruct *next;
} PQueueNode;
int enqueue(PQueueNode **pqueue, int priority, void *data);
int enqueueRand(PQueueNode **pqueue, int priority);
void *dequeue(PQueueNode **pqueue);
void *peek(PQueueNode *pqueue);
void printQueue(PQueueNode *pqueue, void (printFunction)(void*));
int getMinPriority(PQueueNode *pqueue);
int queueLength(PQueueNode *pqueue);
void printSong(void *data);
int  findPriority();
