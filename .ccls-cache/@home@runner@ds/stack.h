#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>

struct stack;

void s_init(struct stack **s);

void s_push(struct stack **s, void *p);

void *s_pop(struct stack **s);

bool s_is_empty(struct stack **s);

#endif