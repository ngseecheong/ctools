#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include <stdbool.h>

#define MAXWORD 1024

int main()
{
  FILE *infile;
  infile = fopen("test","r");
  q_t *q=malloc(sizeof(*q));

  char *line = NULL;
  size_t len = 0;
  
  while((getline(&line, &len, infile)) != -1){
    enqueue(line,q);
  }

  print_queue(q);
  printf("Size:%i\n",q->size);
  del_queue(q);
  free(q);
  return 0;
}
