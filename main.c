#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int main()
{
  char *line = NULL;
  size_t size;
  q_t *q=malloc(sizeof(*q));
  char *buf;
  int count =0;
  
  while (getline(&line, &size, stdin) != -1) {
    buf=malloc(sizeof(*line));
    strcpy(buf,line);
    enqueue(buf,q);
    count++;
    printf("%i",q->size);
  }
  printf("%s\n",dequeue(q));
  del_queue(q);
}
