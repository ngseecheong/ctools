#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

void enqueue(char *word,q_t *q){
  if(q==NULL){
    fprintf(stderr,"enqueue:queue pointer is NULL\n");
    return;
  }
  if(word==NULL){
    fprintf(stderr,"enqueue:word is NULL\n");
    return;
  }
  char *buf=malloc(sizeof(*word));
  strcpy(buf,word);
  if(q->head==NULL){
    q->head=malloc(sizeof(cell_t));
    q->head->word=buf;
    q->size++;
    q->tail=q->head;
  }else{
    cell_t *temp=malloc(sizeof(cell_t));
    temp->word=buf;
    q->tail->next=temp;
    q->tail=temp;
    q->size++;
  }
}

char *dequeue(q_t *q){
  if(q==NULL){
    fprintf(stderr,"dequeue:queue pointer is NULL\n");
    return NULL;
  }
  if(q->head==NULL){
    return NULL;
  }
  cell_t *temp=q->head;
  q->head=q->head->next;
  q->size--;
  return temp->word;
}
  
void print_queue(q_t *q){
  if(q==NULL){
    fprintf(stderr,"print_queue:queue pointer is NULL\n");
    return;
  }
  cell_t *temp=q->head;
  while(temp!=NULL){
    printf("%s\n",temp->word);
    temp=temp->next;
  }
}

void del_queue(q_t *q){
  if(q==NULL){
    fprintf(stderr,"del_queue:queue pointer is NULL\n");
    return;
  }
  cell_t *temp=NULL;
  while(q->head!=NULL){
    temp=q->head;
    q->head=q->head->next;
    //printf("deleting:%s\n",temp->word);
    free(temp->word);
    free(temp);
  }
}
