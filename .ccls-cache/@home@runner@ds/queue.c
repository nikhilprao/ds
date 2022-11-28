#include <stdlib.h>
#include "queue.h"

struct queue {
  struct queue *next;
  struct queue *last;
  void *p;
};

void q_init(struct queue **q)
{
  *q = NULL;
}

void q_push(struct queue **q, void *p)
{
  struct queue *n;

  n = malloc(sizeof(*n));

  n->p = p;
  n->next = NULL;
  n->last = NULL;
  
  if (*q) {
    (*q)->last->next = n;
    (*q)->last = n;
  } else {
    *q = n;
    (*q)->last = n;
  }
}

void *q_pop(struct queue **q)
{
  void *p, *t;

  p = (*q)->p;
  if ((*q)->next)
    (*q)->next->last = (*q)->last;
  
  t = *q;
  *q = (*q)->next;
  
  free(t);
}

bool q_is_empty(struct queue **q)
{
  return *q == NULL;
}