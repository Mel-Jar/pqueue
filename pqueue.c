//
// Created by Mason Landis on 2/14/22.
//
#include "pqueue.mlandis1.h"
const int r = 1000;
const int n = 100;

int enqueue(PQueueNode **pqueue, int priority, void *data){
    if(pqueue != NULL) {
        PQueueNode *curr = *pqueue;
        PQueueNode *prev = NULL;
        PQueueNode *newRecord = malloc(sizeof(PQueueNode));
        //malloc(sizeof(PQueueNode));
        newRecord->priority = priority;
        newRecord->data = data;
        newRecord->next = NULL;
        if (curr == NULL) {
            *pqueue = (PQueueNode *)newRecord;
            return 0;
        } else {
            while (curr != NULL && priority >= curr->priority) {
                prev = curr;
                curr = curr->next;
            }
            newRecord->next = curr;
            if (prev != NULL)
                prev->next = newRecord;
            else
                *pqueue = newRecord;
        }
        return 0;
    }else{
        return 1;
    }
}
int enqueueRand(PQueueNode **pqueue, int priority){
    if(pqueue != NULL) {
        PQueueNode *curr = *pqueue;
        PQueueNode *prev = NULL;
        PQueueNode *newRecord = malloc(sizeof(PQueueNode));
        //malloc(sizeof(PQueueNode));
        newRecord->priority = priority;
        newRecord->data = NULL;
        newRecord->next = NULL;
        if (curr == NULL) {
            *pqueue = (PQueueNode *)newRecord;
            return 0;
        } else {
            while (curr != NULL && priority <= curr->priority) {
                prev = curr;
                curr = curr->next;
            }
            newRecord->next = curr;
            if (prev != NULL)
                prev->next = newRecord;
            else
                *pqueue = newRecord;
        }
        return 0;
    }else{
        return 1;
    }
}
void *dequeue(PQueueNode **pqueue){
    if(*pqueue != NULL) {
        PQueueNode *curr = *pqueue;
        *pqueue = curr->next;
        Song *song;
        song = (Song *) curr->data;
        free(curr);
        return song;
    }else
        return NULL;
}
void *peek(PQueueNode *pqueue){
    if(pqueue != NULL) {
        PQueueNode *qnode;
        qnode = pqueue;
        return qnode->data;
    }
    else
        return NULL;
}
void printQueue(PQueueNode *pqueue, void (printFunction)(void*)){
    PQueueNode *qnode;

    qnode = pqueue;
    while (qnode != NULL) {
        printf("priority = %d ", qnode->priority);
        if(qnode->data != NULL) {
            printf("data = ");
            printFunction(qnode->data);
        }else
            printf("\n");
        qnode = qnode->next;
    }
}

int getMinPriority(PQueueNode *pqueue){
    if(pqueue != NULL) {
        PQueueNode *qnode;
        qnode = pqueue;
        return qnode->priority;
    }
    else
        return -1;
}
int queueLength(PQueueNode *pqueue){
    PQueueNode *qnode;

    qnode = pqueue;
    int count = 0;
    if(qnode == NULL){
        printf("The List is Empty");
        return 0;
    }else{
        while(qnode != NULL){
            qnode = qnode->next;
            count += 1;
        }
        return count;
    }
}
void printSong(void *data){
    Song *song;
    song = (Song *) data;
   // char str  = *song->artist;
    //printf("%s", str);
    //printf("\n");
    printf("\"%s\" ", song->title);
    printf("(%s)", song->artist);
    printf("\n");
    //printf("%p", song->);
}
int  findPriority(){
    int priority;
    int minPriority;
    PQueueNode *pqueue = NULL;
    for(int i = 0; i < n; i++){
        priority= (int) (drand48() * r);
        //printf("%d\n",  priority);
        enqueueRand(&pqueue, priority);
    }
    minPriority = getMinPriority(pqueue);
    //uncomment in order to print out entire queue's priority
    //printQueue(pqueue, NULL);
    printf("\nMin Priority = %d", minPriority);
    return minPriority;
    //song = createSong("Shape of You", "ED Sheeran");
}

