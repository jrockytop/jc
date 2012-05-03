#include "jc.h"

/* bitwise complement */
void bit_comp()
{
	struct datum *res, *a;

	if (stack == stack->next) {
		printf("stack empty\n");
		return;
	}

	res = (struct datum *)malloc(sizeof(struct datum));
	if (!res) {
		printf("no memory\n");
		return;
	}

	a = (struct datum *)stack->next->item;
	res->type = a->type;
	res->base = a->base;

	switch (res->type) {
	case i:
		if (a->type == c)
			res->t.i = ~a->t.c;
		else if (a->type == sc)
			res->t.i = ~a->t.sc;
		else if (a->type == uc)
			res->t.i = ~a->t.uc;
		else if (a->type == s)
			res->t.i = ~a->t.s;
		else if (a->type == i)
			res->t.i = ~a->t.i;
		else if (a->type == l)
			res->t.i = ~a->t.l;
		else if (a->type == us)
			res->t.i = ~a->t.us;
		else if (a->type == u)
			res->t.i = ~a->t.u;
		else if (a->type == ul)
			res->t.i = ~a->t.ul;
		break;
	case l:
		if (a->type == c)
			res->t.l = ~a->t.c;
		else if (a->type == sc)
			res->t.l = ~a->t.sc;
		else if (a->type == uc)
			res->t.l = ~a->t.uc;
		else if (a->type == s)
			res->t.l = ~a->t.s;
		else if (a->type == i)
			res->t.l = ~a->t.i;
		else if (a->type == l)
			res->t.l = ~a->t.l;
		else if (a->type == us)
			res->t.l = ~a->t.us;
		else if (a->type == u)
			res->t.l = ~a->t.u;
		else if (a->type == ul)
			res->t.l = ~a->t.ul;
		break;
	case u:
		if (a->type == c)
			res->t.u = ~a->t.c;
		else if (a->type == sc)
			res->t.u = ~a->t.sc;
		else if (a->type == uc)
			res->t.u = ~a->t.uc;
		else if (a->type == s)
			res->t.u = ~a->t.s;
		else if (a->type == i)
			res->t.u = ~a->t.i;
		else if (a->type == l)
			res->t.u = ~a->t.l;
		else if (a->type == us)
			res->t.u = ~a->t.us;
		else if (a->type == u)
			res->t.u = ~a->t.u;
		else if (a->type == ul)
			res->t.u = ~a->t.ul;
		break;
	case ul:
		if (a->type == c)
			res->t.ul = ~a->t.c;
		else if (a->type == sc)
			res->t.ul = ~a->t.sc;
		else if (a->type == uc)
			res->t.ul = ~a->t.uc;
		else if (a->type == s)
			res->t.ul = ~a->t.s;
		else if (a->type == i)
			res->t.ul = ~a->t.i;
		else if (a->type == l)
			res->t.ul = ~a->t.l;
		else if (a->type == us)
			res->t.ul = ~a->t.us;
		else if (a->type == u)
			res->t.ul = ~a->t.u;
		else if (a->type == ul)
			res->t.ul = ~a->t.ul;
		break;
	default:
		fprintf(stderr, "aborting...\n");
		abort();
	}

	dl_delete_item(dl_first(stack));

	dl_insert_a(stack, res);
}
