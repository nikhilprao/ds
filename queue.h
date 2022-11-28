#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

struct queue;

void q_init(struct queue **s);

void q_push(struct queue **s, void *p);

void *q_pop(struct queue **s);

bool q_is_empty(struct queue **s);

void q_debug(struct queue **q);

#endif