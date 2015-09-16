#ifndef QUEUE_H
#define QUEUE_H

typedef struct cell{
  char *word;
  struct cell *next;
}cell_t;

typedef struct queue{
  cell_t *head;
  cell_t *tail;
  int size;
}q_t;

void enqueue(char *,q_t *q);
char *dequeue(q_t *q);
void print_queue(q_t *q);
void del_queue(q_t *q);

#endif
