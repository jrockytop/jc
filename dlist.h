/*
 * Double Linked List
 *
 * File: dlist.h
 *
 * Author: Jason Cox, derived from Plank's dlist
 *
 * Description: This is a library of functions to manipulate a double linked
 *              list.
 *
 */

/*
 * $Log: dlist.h,v $
 * Revision 1.1  1996/02/25  21:39:38  cox
 * Initial revision
 *
 * Revision 1.1  1995/11/13  01:05:07  cox
 * Initial revision
 *
 */

#ifndef DLIST_H
#define DLIST_H

#include <stddef.h>

typedef struct dlist {
    void *item;
    struct dlist *next;
    struct dlist *prev;
} *Dlist;


Dlist dl_create(void);

void dl_insert_a(Dlist, void *);
void dl_insert_b(Dlist, void *);

void dl_delete(Dlist);
void dl_delete_item(Dlist);

void dl_clear(Dlist);
void dl_clear_all(Dlist);

void dl_destroy(Dlist);
void dl_destroy_all(Dlist);

int dl_length(Dlist);

#define dl_last(n) (n->prev)
#define dl_first(n) (n->next)
#define dl_next(n) (n->next)
#define dl_prev(n) (n->prev)
#define dl_empty(n) (n->next == n)
#define dl_nil(n) (n)

#define dl_traverse(ptr, list) \
  for ((ptr) = dl_first(list); (ptr) != dl_nil(list); (ptr) = dl_next(ptr))

#define dl_rtraverse(ptr, list) \
  for ((ptr) = dl_last(list); (ptr) != dl_nil(list); (ptr) = dl_prev(ptr))

#endif
