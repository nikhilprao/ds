#include <stddef.h>
#include "stack.h"

struct stack {
  void *p;
  struct stack *next;
};

void
s_init(struct stack **s)
{
  *s = NULL;
}

void
s_push(struct stack **s, void *p)
{
    struct stack *n;

    n = malloc(sizeof(*n));
    n->p = p;
    n->next = NULL;

    if (*s)
      n->next = *s;
    *s = n;
}

void *
s_pop(struct stack **s)
{
  void *p;
  
  if (!*s)
    return NULL;
  
  p = (*s)->p;
  *s = (*s)->next;

  return p;
}

bool
s_is_empty(struct stack **s)
{
  return *s == NULL;
}