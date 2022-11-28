#include <stdio.h>
#include "stack.h"

int main(void) {
  int v[] = { 1, 2, 3};
  int i;
  struct stack *s;
  struct queue *q;
  
  printf("Hello World\n");

  s_init(&s);
  q_init(&q);
  
  for (i = 0; i < sizeof(v)/sizeof(v[0]); i++) {
    s_push(&s, &v[i]);
    q_push(&q, &v[i]);
  }

  while (!s_is_empty(&s)) {
    int *p = s_pop(&s);
    printf("%d\n", *p);
  }

  while (!q_is_empty(&q)) {
    int *p = q_pop(&q);
    printf("%d\n", *p);
  }
  
  return 0;
}