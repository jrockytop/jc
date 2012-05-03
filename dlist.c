/*
 * Double Linked List
 *
 * File: dlist.c
 *
 * Author: Jason Cox, derived from Plank's dlist
 *
 * Description: This is a library of functions to manipulate a double linked
 *              list.
 *
 */

/*
 * $Log: dlist.c,v $
 * Revision 1.1  1996/02/25  21:38:57  cox
 * Initial revision
 *
 * Revision 1.2  1995/11/20  01:36:25  cox
 * Fixed the dl_insert_a(), dl_insert_b() mixup.
 *
 * Revision 1.1  1995/11/13  01:02:59  cox
 * Initial revision
 *
 */

#include "dlist.h"
#include <stdlib.h>

static char rcsid[] = "$Id: dlist.c,v 1.1 1996/02/25 21:38:57 cox Exp $";

/*
 * dl_create
 *
 * Description: Create a Dlist sentinel node and return it.
 *
 */
Dlist dl_create(void)
{
    Dlist
	l;

    l = (Dlist) malloc(sizeof(struct dlist));

    l->item = NULL;
    l->next = l->prev = l;

    return l;
}


/*
 * dl_insert_b
 *
 * Description: Insert an item before the given Dlist node.
 *
 */
void dl_insert_b(Dlist l, void *item)
{
    Dlist
	node;

    node = (Dlist) malloc(sizeof(struct dlist));

    node->item = item;
    node->next = l;
    node->prev = l->prev;
    l->prev->next = node;
    l->prev = node;
}


/*
 * dl_insert_a
 *
 * Description: Insert an item after the given Dlist node.
 *
 */
void dl_insert_a(Dlist l, void *item)
{
    Dlist
	node;

    node = (Dlist) malloc(sizeof(struct dlist));

    node->item = item;
    node->next = l->next;
    node->prev = l;
    l->next->prev = node;
    l->next = node;
}


/*
 * dl_delete
 *
 * Description: Deletes and frees a Dlist node from a Dlist.
 *
 */
void dl_delete(Dlist node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
}


/*
 * dl_delete_item
 *
 * Description: Deletes and frees a Dlist node from a Dlist and also
 *              frees the item in the node too.
 *
 */
void dl_delete_item(Dlist node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node->item);
    free(node);
}


/*
 * dl_clear
 *
 * Description: Deletes and frees all nodes in the given Dlist except the
 *              sentinel node.  The Dlist will be empty and can be reused.
 *
 */
void dl_clear(Dlist l)
{
    Dlist
	tmp = l->next,
	next;
    
    while (tmp != l) {
	next = tmp->next;
	free(tmp);
	tmp = next;
    }
    l->next = l->prev = l;
}


/*
 * dl_clear_all
 *
 * Description: This function is like the dl_clear function except that
 *              it also calls free on all of the items in the list too.
 *
 */
void dl_clear_all(Dlist l)
{
    Dlist
	tmp = l->next,
	next;
    
    while (tmp != l) {
	next = tmp->next;
	free(tmp->item);
	free(tmp);
	tmp = next;
    }
    l->next = l->prev = l;
}


/*
 * dl_destroy
 *
 * Description: Deletes and frees all nodes in the given Dlist except the
 *              sentinel node.  The Dlist will be freed and cannot be reused.
 *
 */
void dl_destroy(Dlist l)
{
    Dlist
	tmp = l->next,
	next;
    
    while (tmp != l) {
	next = tmp->next;
	free(tmp);
	tmp = next;
    }
    free(l);
}


/*
 * dl_destroy_all
 *
 * Description: This function is like the dl_destroy function except that
 *              it also calls free on all of the items in the list too.
 *
 */
void dl_destroy_all(Dlist l)
{
    Dlist
	tmp = l->next,
	next;
    
    while (tmp != l) {
	next = tmp->next;
	free(tmp->item);
	free(tmp);
	tmp = next;
    }
    free(l);
}


/*
 * dl_length
 *
 * Description: This function returns the length of the given Dlist.
 *
 */
int dl_length(Dlist l)
{
    Dlist
	tmp;

    int
	c = 0;

    for (tmp=l->next; tmp != l; tmp=tmp->next)
	c++;

    return c;
}
