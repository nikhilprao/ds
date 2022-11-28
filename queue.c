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
  struct queue *tq = *q;
  struct queue *n;

  n = malloc(sizeof(*n));

  n->p = p;
  n->next = NULL;
  n->last = NULL;
  
  if (tq) {
    tq->last->next = n;
    tq->last = n;
  } else {
    *q = n;
    (*q)->last = n;
  }
}

void *q_pop(struct queue **q)
{
  struct queue *tq = *q;
  void *p, *t;

  p = tq->p;
  if (tq->next)
    tq->next->last = tq->last;
  
  t = tq;
  *q = tq->next;
  
  free(t);
  return p;
}

bool q_is_empty(struct queue **q)
{
  return *q == NULL;
}