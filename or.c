#include "jc.h"

void or()
{
	struct datum *res, *a, *b;

	if (stack == stack->next || stack == stack->next->next) {
		printf("stack empty\n");
		return;
	}

	res = (struct datum *)malloc(sizeof(struct datum));
	if (!res) {
		printf("no memory\n");
		return;
	}

	a = (struct datum *)stack->next->next->item;
	b = (struct datum *)stack->next->item;

	implicit_conversion(&res->type, &res->base, a->type, a->base,
			   b->type, b->base);

	switch (res->type) {
	case i:
		if (a->type == c && b->type == c)
			res->t.i = a->t.c | b->t.c;
		else if (a->type == c && b->type == sc)
			res->t.i = a->t.c | b->t.sc;
		else if (a->type == c && b->type == uc)
			res->t.i = a->t.c | b->t.uc;
		else if (a->type == c && b->type == s)
			res->t.i = a->t.c | b->t.s;
		else if (a->type == c && b->type == i)
			res->t.i = a->t.c | b->t.i;
		else if (a->type == c && b->type == l)
			res->t.i = a->t.c | b->t.l;
		else if (a->type == c && b->type == us)
			res->t.i = a->t.c | b->t.us;
		else if (a->type == c && b->type == u)
			res->t.i = a->t.c | b->t.u;
		else if (a->type == c && b->type == ul)
			res->t.i = a->t.c | b->t.ul;
		else if (a->type == sc && b->type == c)
			res->t.i = a->t.sc | b->t.c;
		else if (a->type == sc && b->type == sc)
			res->t.i = a->t.sc | b->t.sc;
		else if (a->type == sc && b->type == uc)
			res->t.i = a->t.sc | b->t.uc;
		else if (a->type == sc && b->type == s)
			res->t.i = a->t.sc | b->t.s;
		else if (a->type == sc && b->type == i)
			res->t.i = a->t.sc | b->t.i;
		else if (a->type == sc && b->type == l)
			res->t.i = a->t.sc | b->t.l;
		else if (a->type == sc && b->type == us)
			res->t.i = a->t.sc | b->t.us;
		else if (a->type == sc && b->type == u)
			res->t.i = a->t.sc | b->t.u;
		else if (a->type == sc && b->type == ul)
			res->t.i = a->t.sc | b->t.ul;
		else if (a->type == uc && b->type == c)
			res->t.i = a->t.uc | b->t.c;
		else if (a->type == uc && b->type == sc)
			res->t.i = a->t.uc | b->t.sc;
		else if (a->type == uc && b->type == uc)
			res->t.i = a->t.uc | b->t.uc;
		else if (a->type == uc && b->type == s)
			res->t.i = a->t.uc | b->t.s;
		else if (a->type == uc && b->type == i)
			res->t.i = a->t.uc | b->t.i;
		else if (a->type == uc && b->type == l)
			res->t.i = a->t.uc | b->t.l;
		else if (a->type == uc && b->type == us)
			res->t.i = a->t.uc | b->t.us;
		else if (a->type == uc && b->type == u)
			res->t.i = a->t.uc | b->t.u;
		else if (a->type == uc && b->type == ul)
			res->t.i = a->t.uc | b->t.ul;
		else if (a->type == s && b->type == c)
			res->t.i = a->t.s | b->t.c;
		else if (a->type == s && b->type == sc)
			res->t.i = a->t.s | b->t.sc;
		else if (a->type == s && b->type == uc)
			res->t.i = a->t.s | b->t.uc;
		else if (a->type == s && b->type == s)
			res->t.i = a->t.s | b->t.s;
		else if (a->type == s && b->type == i)
			res->t.i = a->t.s | b->t.i;
		else if (a->type == s && b->type == l)
			res->t.i = a->t.s | b->t.l;
		else if (a->type == s && b->type == us)
			res->t.i = a->t.s | b->t.us;
		else if (a->type == s && b->type == u)
			res->t.i = a->t.s | b->t.u;
		else if (a->type == s && b->type == ul)
			res->t.i = a->t.s | b->t.ul;
		else if (a->type == i && b->type == c)
			res->t.i = a->t.i | b->t.c;
		else if (a->type == i && b->type == sc)
			res->t.i = a->t.i | b->t.sc;
		else if (a->type == i && b->type == uc)
			res->t.i = a->t.i | b->t.uc;
		else if (a->type == i && b->type == s)
			res->t.i = a->t.i | b->t.s;
		else if (a->type == i && b->type == i)
			res->t.i = a->t.i | b->t.i;
		else if (a->type == i && b->type == l)
			res->t.i = a->t.i | b->t.l;
		else if (a->type == i && b->type == us)
			res->t.i = a->t.i | b->t.us;
		else if (a->type == i && b->type == u)
			res->t.i = a->t.i | b->t.u;
		else if (a->type == i && b->type == ul)
			res->t.i = a->t.i | b->t.ul;
		else if (a->type == l && b->type == c)
			res->t.i = a->t.l | b->t.c;
		else if (a->type == l && b->type == sc)
			res->t.i = a->t.l | b->t.sc;
		else if (a->type == l && b->type == uc)
			res->t.i = a->t.l | b->t.uc;
		else if (a->type == l && b->type == s)
			res->t.i = a->t.l | b->t.s;
		else if (a->type == l && b->type == i)
			res->t.i = a->t.l | b->t.i;
		else if (a->type == l && b->type == l)
			res->t.i = a->t.l | b->t.l;
		else if (a->type == l && b->type == us)
			res->t.i = a->t.l | b->t.us;
		else if (a->type == l && b->type == u)
			res->t.i = a->t.l | b->t.u;
		else if (a->type == l && b->type == ul)
			res->t.i = a->t.l | b->t.ul;
		else if (a->type == us && b->type == c)
			res->t.i = a->t.us | b->t.c;
		else if (a->type == us && b->type == sc)
			res->t.i = a->t.us | b->t.sc;
		else if (a->type == us && b->type == uc)
			res->t.i = a->t.us | b->t.uc;
		else if (a->type == us && b->type == s)
			res->t.i = a->t.us | b->t.s;
		else if (a->type == us && b->type == i)
			res->t.i = a->t.us | b->t.i;
		else if (a->type == us && b->type == l)
			res->t.i = a->t.us | b->t.l;
		else if (a->type == us && b->type == us)
			res->t.i = a->t.us | b->t.us;
		else if (a->type == us && b->type == u)
			res->t.i = a->t.us | b->t.u;
		else if (a->type == us && b->type == ul)
			res->t.i = a->t.us | b->t.ul;
		else if (a->type == u && b->type == c)
			res->t.i = a->t.u | b->t.c;
		else if (a->type == u && b->type == sc)
			res->t.i = a->t.u | b->t.sc;
		else if (a->type == u && b->type == uc)
			res->t.i = a->t.u | b->t.uc;
		else if (a->type == u && b->type == s)
			res->t.i = a->t.u | b->t.s;
		else if (a->type == u && b->type == i)
			res->t.i = a->t.u | b->t.i;
		else if (a->type == u && b->type == l)
			res->t.i = a->t.u | b->t.l;
		else if (a->type == u && b->type == us)
			res->t.i = a->t.u | b->t.us;
		else if (a->type == u && b->type == u)
			res->t.i = a->t.u | b->t.u;
		else if (a->type == u && b->type == ul)
			res->t.i = a->t.u | b->t.ul;
		else if (a->type == ul && b->type == c)
			res->t.i = a->t.ul | b->t.c;
		else if (a->type == ul && b->type == sc)
			res->t.i = a->t.ul | b->t.sc;
		else if (a->type == ul && b->type == uc)
			res->t.i = a->t.ul | b->t.uc;
		else if (a->type == ul && b->type == s)
			res->t.i = a->t.ul | b->t.s;
		else if (a->type == ul && b->type == i)
			res->t.i = a->t.ul | b->t.i;
		else if (a->type == ul && b->type == l)
			res->t.i = a->t.ul | b->t.l;
		else if (a->type == ul && b->type == us)
			res->t.i = a->t.ul | b->t.us;
		else if (a->type == ul && b->type == u)
			res->t.i = a->t.ul | b->t.u;
		else if (a->type == ul && b->type == ul)
			res->t.i = a->t.ul | b->t.ul;
		break;
	case l:
		if (a->type == c && b->type == c)
			res->t.l = a->t.c | b->t.c;
		else if (a->type == c && b->type == sc)
			res->t.l = a->t.c | b->t.sc;
		else if (a->type == c && b->type == uc)
			res->t.l = a->t.c | b->t.uc;
		else if (a->type == c && b->type == s)
			res->t.l = a->t.c | b->t.s;
		else if (a->type == c && b->type == i)
			res->t.l = a->t.c | b->t.i;
		else if (a->type == c && b->type == l)
			res->t.l = a->t.c | b->t.l;
		else if (a->type == c && b->type == us)
			res->t.l = a->t.c | b->t.us;
		else if (a->type == c && b->type == u)
			res->t.l = a->t.c | b->t.u;
		else if (a->type == c && b->type == ul)
			res->t.l = a->t.c | b->t.ul;
		else if (a->type == sc && b->type == c)
			res->t.l = a->t.sc | b->t.c;
		else if (a->type == sc && b->type == sc)
			res->t.l = a->t.sc | b->t.sc;
		else if (a->type == sc && b->type == uc)
			res->t.l = a->t.sc | b->t.uc;
		else if (a->type == sc && b->type == s)
			res->t.l = a->t.sc | b->t.s;
		else if (a->type == sc && b->type == i)
			res->t.l = a->t.sc | b->t.i;
		else if (a->type == sc && b->type == l)
			res->t.l = a->t.sc | b->t.l;
		else if (a->type == sc && b->type == us)
			res->t.l = a->t.sc | b->t.us;
		else if (a->type == sc && b->type == u)
			res->t.l = a->t.sc | b->t.u;
		else if (a->type == sc && b->type == ul)
			res->t.l = a->t.sc | b->t.ul;
		else if (a->type == uc && b->type == c)
			res->t.l = a->t.uc | b->t.c;
		else if (a->type == uc && b->type == sc)
			res->t.l = a->t.uc | b->t.sc;
		else if (a->type == uc && b->type == uc)
			res->t.l = a->t.uc | b->t.uc;
		else if (a->type == uc && b->type == s)
			res->t.l = a->t.uc | b->t.s;
		else if (a->type == uc && b->type == i)
			res->t.l = a->t.uc | b->t.i;
		else if (a->type == uc && b->type == l)
			res->t.l = a->t.uc | b->t.l;
		else if (a->type == uc && b->type == us)
			res->t.l = a->t.uc | b->t.us;
		else if (a->type == uc && b->type == u)
			res->t.l = a->t.uc | b->t.u;
		else if (a->type == uc && b->type == ul)
			res->t.l = a->t.uc | b->t.ul;
		else if (a->type == s && b->type == c)
			res->t.l = a->t.s | b->t.c;
		else if (a->type == s && b->type == sc)
			res->t.l = a->t.s | b->t.sc;
		else if (a->type == s && b->type == uc)
			res->t.l = a->t.s | b->t.uc;
		else if (a->type == s && b->type == s)
			res->t.l = a->t.s | b->t.s;
		else if (a->type == s && b->type == i)
			res->t.l = a->t.s | b->t.i;
		else if (a->type == s && b->type == l)
			res->t.l = a->t.s | b->t.l;
		else if (a->type == s && b->type == us)
			res->t.l = a->t.s | b->t.us;
		else if (a->type == s && b->type == u)
			res->t.l = a->t.s | b->t.u;
		else if (a->type == s && b->type == ul)
			res->t.l = a->t.s | b->t.ul;
		else if (a->type == i && b->type == c)
			res->t.l = a->t.i | b->t.c;
		else if (a->type == i && b->type == sc)
			res->t.l = a->t.i | b->t.sc;
		else if (a->type == i && b->type == uc)
			res->t.l = a->t.i | b->t.uc;
		else if (a->type == i && b->type == s)
			res->t.l = a->t.i | b->t.s;
		else if (a->type == i && b->type == i)
			res->t.l = a->t.i | b->t.i;
		else if (a->type == i && b->type == l)
			res->t.l = a->t.i | b->t.l;
		else if (a->type == i && b->type == us)
			res->t.l = a->t.i | b->t.us;
		else if (a->type == i && b->type == u)
			res->t.l = a->t.i | b->t.u;
		else if (a->type == i && b->type == ul)
			res->t.l = a->t.i | b->t.ul;
		else if (a->type == l && b->type == c)
			res->t.l = a->t.l | b->t.c;
		else if (a->type == l && b->type == sc)
			res->t.l = a->t.l | b->t.sc;
		else if (a->type == l && b->type == uc)
			res->t.l = a->t.l | b->t.uc;
		else if (a->type == l && b->type == s)
			res->t.l = a->t.l | b->t.s;
		else if (a->type == l && b->type == i)
			res->t.l = a->t.l | b->t.i;
		else if (a->type == l && b->type == l)
			res->t.l = a->t.l | b->t.l;
		else if (a->type == l && b->type == us)
			res->t.l = a->t.l | b->t.us;
		else if (a->type == l && b->type == u)
			res->t.l = a->t.l | b->t.u;
		else if (a->type == l && b->type == ul)
			res->t.l = a->t.l | b->t.ul;
		else if (a->type == us && b->type == c)
			res->t.l = a->t.us | b->t.c;
		else if (a->type == us && b->type == sc)
			res->t.l = a->t.us | b->t.sc;
		else if (a->type == us && b->type == uc)
			res->t.l = a->t.us | b->t.uc;
		else if (a->type == us && b->type == s)
			res->t.l = a->t.us | b->t.s;
		else if (a->type == us && b->type == i)
			res->t.l = a->t.us | b->t.i;
		else if (a->type == us && b->type == l)
			res->t.l = a->t.us | b->t.l;
		else if (a->type == us && b->type == us)
			res->t.l = a->t.us | b->t.us;
		else if (a->type == us && b->type == u)
			res->t.l = a->t.us | b->t.u;
		else if (a->type == us && b->type == ul)
			res->t.l = a->t.us | b->t.ul;
		else if (a->type == u && b->type == c)
			res->t.l = a->t.u | b->t.c;
		else if (a->type == u && b->type == sc)
			res->t.l = a->t.u | b->t.sc;
		else if (a->type == u && b->type == uc)
			res->t.l = a->t.u | b->t.uc;
		else if (a->type == u && b->type == s)
			res->t.l = a->t.u | b->t.s;
		else if (a->type == u && b->type == i)
			res->t.l = a->t.u | b->t.i;
		else if (a->type == u && b->type == l)
			res->t.l = a->t.u | b->t.l;
		else if (a->type == u && b->type == us)
			res->t.l = a->t.u | b->t.us;
		else if (a->type == u && b->type == u)
			res->t.l = a->t.u | b->t.u;
		else if (a->type == u && b->type == ul)
			res->t.l = a->t.u | b->t.ul;
		else if (a->type == ul && b->type == c)
			res->t.l = a->t.ul | b->t.c;
		else if (a->type == ul && b->type == sc)
			res->t.l = a->t.ul | b->t.sc;
		else if (a->type == ul && b->type == uc)
			res->t.l = a->t.ul | b->t.uc;
		else if (a->type == ul && b->type == s)
			res->t.l = a->t.ul | b->t.s;
		else if (a->type == ul && b->type == i)
			res->t.l = a->t.ul | b->t.i;
		else if (a->type == ul && b->type == l)
			res->t.l = a->t.ul | b->t.l;
		else if (a->type == ul && b->type == us)
			res->t.l = a->t.ul | b->t.us;
		else if (a->type == ul && b->type == u)
			res->t.l = a->t.ul | b->t.u;
		else if (a->type == ul && b->type == ul)
			res->t.l = a->t.ul | b->t.ul;
		break;
	case u:
		if (a->type == c && b->type == c)
			res->t.u = a->t.c | b->t.c;
		else if (a->type == c && b->type == sc)
			res->t.u = a->t.c | b->t.sc;
		else if (a->type == c && b->type == uc)
			res->t.u = a->t.c | b->t.uc;
		else if (a->type == c && b->type == s)
			res->t.u = a->t.c | b->t.s;
		else if (a->type == c && b->type == i)
			res->t.u = a->t.c | b->t.i;
		else if (a->type == c && b->type == l)
			res->t.u = a->t.c | b->t.l;
		else if (a->type == c && b->type == us)
			res->t.u = a->t.c | b->t.us;
		else if (a->type == c && b->type == u)
			res->t.u = a->t.c | b->t.u;
		else if (a->type == c && b->type == ul)
			res->t.u = a->t.c | b->t.ul;
		else if (a->type == sc && b->type == c)
			res->t.u = a->t.sc | b->t.c;
		else if (a->type == sc && b->type == sc)
			res->t.u = a->t.sc | b->t.sc;
		else if (a->type == sc && b->type == uc)
			res->t.u = a->t.sc | b->t.uc;
		else if (a->type == sc && b->type == s)
			res->t.u = a->t.sc | b->t.s;
		else if (a->type == sc && b->type == i)
			res->t.u = a->t.sc | b->t.i;
		else if (a->type == sc && b->type == l)
			res->t.u = a->t.sc | b->t.l;
		else if (a->type == sc && b->type == us)
			res->t.u = a->t.sc | b->t.us;
		else if (a->type == sc && b->type == u)
			res->t.u = a->t.sc | b->t.u;
		else if (a->type == sc && b->type == ul)
			res->t.u = a->t.sc | b->t.ul;
		else if (a->type == uc && b->type == c)
			res->t.u = a->t.uc | b->t.c;
		else if (a->type == uc && b->type == sc)
			res->t.u = a->t.uc | b->t.sc;
		else if (a->type == uc && b->type == uc)
			res->t.u = a->t.uc | b->t.uc;
		else if (a->type == uc && b->type == s)
			res->t.u = a->t.uc | b->t.s;
		else if (a->type == uc && b->type == i)
			res->t.u = a->t.uc | b->t.i;
		else if (a->type == uc && b->type == l)
			res->t.u = a->t.uc | b->t.l;
		else if (a->type == uc && b->type == us)
			res->t.u = a->t.uc | b->t.us;
		else if (a->type == uc && b->type == u)
			res->t.u = a->t.uc | b->t.u;
		else if (a->type == uc && b->type == ul)
			res->t.u = a->t.uc | b->t.ul;
		else if (a->type == s && b->type == c)
			res->t.u = a->t.s | b->t.c;
		else if (a->type == s && b->type == sc)
			res->t.u = a->t.s | b->t.sc;
		else if (a->type == s && b->type == uc)
			res->t.u = a->t.s | b->t.uc;
		else if (a->type == s && b->type == s)
			res->t.u = a->t.s | b->t.s;
		else if (a->type == s && b->type == i)
			res->t.u = a->t.s | b->t.i;
		else if (a->type == s && b->type == l)
			res->t.u = a->t.s | b->t.l;
		else if (a->type == s && b->type == us)
			res->t.u = a->t.s | b->t.us;
		else if (a->type == s && b->type == u)
			res->t.u = a->t.s | b->t.u;
		else if (a->type == s && b->type == ul)
			res->t.u = a->t.s | b->t.ul;
		else if (a->type == i && b->type == c)
			res->t.u = a->t.i | b->t.c;
		else if (a->type == i && b->type == sc)
			res->t.u = a->t.i | b->t.sc;
		else if (a->type == i && b->type == uc)
			res->t.u = a->t.i | b->t.uc;
		else if (a->type == i && b->type == s)
			res->t.u = a->t.i | b->t.s;
		else if (a->type == i && b->type == i)
			res->t.u = a->t.i | b->t.i;
		else if (a->type == i && b->type == l)
			res->t.u = a->t.i | b->t.l;
		else if (a->type == i && b->type == us)
			res->t.u = a->t.i | b->t.us;
		else if (a->type == i && b->type == u)
			res->t.u = a->t.i | b->t.u;
		else if (a->type == i && b->type == ul)
			res->t.u = a->t.i | b->t.ul;
		else if (a->type == l && b->type == c)
			res->t.u = a->t.l | b->t.c;
		else if (a->type == l && b->type == sc)
			res->t.u = a->t.l | b->t.sc;
		else if (a->type == l && b->type == uc)
			res->t.u = a->t.l | b->t.uc;
		else if (a->type == l && b->type == s)
			res->t.u = a->t.l | b->t.s;
		else if (a->type == l && b->type == i)
			res->t.u = a->t.l | b->t.i;
		else if (a->type == l && b->type == l)
			res->t.u = a->t.l | b->t.l;
		else if (a->type == l && b->type == us)
			res->t.u = a->t.l | b->t.us;
		else if (a->type == l && b->type == u)
			res->t.u = a->t.l | b->t.u;
		else if (a->type == l && b->type == ul)
			res->t.u = a->t.l | b->t.ul;
		else if (a->type == us && b->type == c)
			res->t.u = a->t.us | b->t.c;
		else if (a->type == us && b->type == sc)
			res->t.u = a->t.us | b->t.sc;
		else if (a->type == us && b->type == uc)
			res->t.u = a->t.us | b->t.uc;
		else if (a->type == us && b->type == s)
			res->t.u = a->t.us | b->t.s;
		else if (a->type == us && b->type == i)
			res->t.u = a->t.us | b->t.i;
		else if (a->type == us && b->type == l)
			res->t.u = a->t.us | b->t.l;
		else if (a->type == us && b->type == us)
			res->t.u = a->t.us | b->t.us;
		else if (a->type == us && b->type == u)
			res->t.u = a->t.us | b->t.u;
		else if (a->type == us && b->type == ul)
			res->t.u = a->t.us | b->t.ul;
		else if (a->type == u && b->type == c)
			res->t.u = a->t.u | b->t.c;
		else if (a->type == u && b->type == sc)
			res->t.u = a->t.u | b->t.sc;
		else if (a->type == u && b->type == uc)
			res->t.u = a->t.u | b->t.uc;
		else if (a->type == u && b->type == s)
			res->t.u = a->t.u | b->t.s;
		else if (a->type == u && b->type == i)
			res->t.u = a->t.u | b->t.i;
		else if (a->type == u && b->type == l)
			res->t.u = a->t.u | b->t.l;
		else if (a->type == u && b->type == us)
			res->t.u = a->t.u | b->t.us;
		else if (a->type == u && b->type == u)
			res->t.u = a->t.u | b->t.u;
		else if (a->type == u && b->type == ul)
			res->t.u = a->t.u | b->t.ul;
		else if (a->type == ul && b->type == c)
			res->t.u = a->t.ul | b->t.c;
		else if (a->type == ul && b->type == sc)
			res->t.u = a->t.ul | b->t.sc;
		else if (a->type == ul && b->type == uc)
			res->t.u = a->t.ul | b->t.uc;
		else if (a->type == ul && b->type == s)
			res->t.u = a->t.ul | b->t.s;
		else if (a->type == ul && b->type == i)
			res->t.u = a->t.ul | b->t.i;
		else if (a->type == ul && b->type == l)
			res->t.u = a->t.ul | b->t.l;
		else if (a->type == ul && b->type == us)
			res->t.u = a->t.ul | b->t.us;
		else if (a->type == ul && b->type == u)
			res->t.u = a->t.ul | b->t.u;
		else if (a->type == ul && b->type == ul)
			res->t.u = a->t.ul | b->t.ul;
		break;
	case ul:
		if (a->type == c && b->type == c)
			res->t.ul = a->t.c | b->t.c;
		else if (a->type == c && b->type == sc)
			res->t.ul = a->t.c | b->t.sc;
		else if (a->type == c && b->type == uc)
			res->t.ul = a->t.c | b->t.uc;
		else if (a->type == c && b->type == s)
			res->t.ul = a->t.c | b->t.s;
		else if (a->type == c && b->type == i)
			res->t.ul = a->t.c | b->t.i;
		else if (a->type == c && b->type == l)
			res->t.ul = a->t.c | b->t.l;
		else if (a->type == c && b->type == us)
			res->t.ul = a->t.c | b->t.us;
		else if (a->type == c && b->type == u)
			res->t.ul = a->t.c | b->t.u;
		else if (a->type == c && b->type == ul)
			res->t.ul = a->t.c | b->t.ul;
		else if (a->type == sc && b->type == c)
			res->t.ul = a->t.sc | b->t.c;
		else if (a->type == sc && b->type == sc)
			res->t.ul = a->t.sc | b->t.sc;
		else if (a->type == sc && b->type == uc)
			res->t.ul = a->t.sc | b->t.uc;
		else if (a->type == sc && b->type == s)
			res->t.ul = a->t.sc | b->t.s;
		else if (a->type == sc && b->type == i)
			res->t.ul = a->t.sc | b->t.i;
		else if (a->type == sc && b->type == l)
			res->t.ul = a->t.sc | b->t.l;
		else if (a->type == sc && b->type == us)
			res->t.ul = a->t.sc | b->t.us;
		else if (a->type == sc && b->type == u)
			res->t.ul = a->t.sc | b->t.u;
		else if (a->type == sc && b->type == ul)
			res->t.ul = a->t.sc | b->t.ul;
		else if (a->type == uc && b->type == c)
			res->t.ul = a->t.uc | b->t.c;
		else if (a->type == uc && b->type == sc)
			res->t.ul = a->t.uc | b->t.sc;
		else if (a->type == uc && b->type == uc)
			res->t.ul = a->t.uc | b->t.uc;
		else if (a->type == uc && b->type == s)
			res->t.ul = a->t.uc | b->t.s;
		else if (a->type == uc && b->type == i)
			res->t.ul = a->t.uc | b->t.i;
		else if (a->type == uc && b->type == l)
			res->t.ul = a->t.uc | b->t.l;
		else if (a->type == uc && b->type == us)
			res->t.ul = a->t.uc | b->t.us;
		else if (a->type == uc && b->type == u)
			res->t.ul = a->t.uc | b->t.u;
		else if (a->type == uc && b->type == ul)
			res->t.ul = a->t.uc | b->t.ul;
		else if (a->type == s && b->type == c)
			res->t.ul = a->t.s | b->t.c;
		else if (a->type == s && b->type == sc)
			res->t.ul = a->t.s | b->t.sc;
		else if (a->type == s && b->type == uc)
			res->t.ul = a->t.s | b->t.uc;
		else if (a->type == s && b->type == s)
			res->t.ul = a->t.s | b->t.s;
		else if (a->type == s && b->type == i)
			res->t.ul = a->t.s | b->t.i;
		else if (a->type == s && b->type == l)
			res->t.ul = a->t.s | b->t.l;
		else if (a->type == s && b->type == us)
			res->t.ul = a->t.s | b->t.us;
		else if (a->type == s && b->type == u)
			res->t.ul = a->t.s | b->t.u;
		else if (a->type == s && b->type == ul)
			res->t.ul = a->t.s | b->t.ul;
		else if (a->type == i && b->type == c)
			res->t.ul = a->t.i | b->t.c;
		else if (a->type == i && b->type == sc)
			res->t.ul = a->t.i | b->t.sc;
		else if (a->type == i && b->type == uc)
			res->t.ul = a->t.i | b->t.uc;
		else if (a->type == i && b->type == s)
			res->t.ul = a->t.i | b->t.s;
		else if (a->type == i && b->type == i)
			res->t.ul = a->t.i | b->t.i;
		else if (a->type == i && b->type == l)
			res->t.ul = a->t.i | b->t.l;
		else if (a->type == i && b->type == us)
			res->t.ul = a->t.i | b->t.us;
		else if (a->type == i && b->type == u)
			res->t.ul = a->t.i | b->t.u;
		else if (a->type == i && b->type == ul)
			res->t.ul = a->t.i | b->t.ul;
		else if (a->type == l && b->type == c)
			res->t.ul = a->t.l | b->t.c;
		else if (a->type == l && b->type == sc)
			res->t.ul = a->t.l | b->t.sc;
		else if (a->type == l && b->type == uc)
			res->t.ul = a->t.l | b->t.uc;
		else if (a->type == l && b->type == s)
			res->t.ul = a->t.l | b->t.s;
		else if (a->type == l && b->type == i)
			res->t.ul = a->t.l | b->t.i;
		else if (a->type == l && b->type == l)
			res->t.ul = a->t.l | b->t.l;
		else if (a->type == l && b->type == us)
			res->t.ul = a->t.l | b->t.us;
		else if (a->type == l && b->type == u)
			res->t.ul = a->t.l | b->t.u;
		else if (a->type == l && b->type == ul)
			res->t.ul = a->t.l | b->t.ul;
		else if (a->type == us && b->type == c)
			res->t.ul = a->t.us | b->t.c;
		else if (a->type == us && b->type == sc)
			res->t.ul = a->t.us | b->t.sc;
		else if (a->type == us && b->type == uc)
			res->t.ul = a->t.us | b->t.uc;
		else if (a->type == us && b->type == s)
			res->t.ul = a->t.us | b->t.s;
		else if (a->type == us && b->type == i)
			res->t.ul = a->t.us | b->t.i;
		else if (a->type == us && b->type == l)
			res->t.ul = a->t.us | b->t.l;
		else if (a->type == us && b->type == us)
			res->t.ul = a->t.us | b->t.us;
		else if (a->type == us && b->type == u)
			res->t.ul = a->t.us | b->t.u;
		else if (a->type == us && b->type == ul)
			res->t.ul = a->t.us | b->t.ul;
		else if (a->type == u && b->type == c)
			res->t.ul = a->t.u | b->t.c;
		else if (a->type == u && b->type == sc)
			res->t.ul = a->t.u | b->t.sc;
		else if (a->type == u && b->type == uc)
			res->t.ul = a->t.u | b->t.uc;
		else if (a->type == u && b->type == s)
			res->t.ul = a->t.u | b->t.s;
		else if (a->type == u && b->type == i)
			res->t.ul = a->t.u | b->t.i;
		else if (a->type == u && b->type == l)
			res->t.ul = a->t.u | b->t.l;
		else if (a->type == u && b->type == us)
			res->t.ul = a->t.u | b->t.us;
		else if (a->type == u && b->type == u)
			res->t.ul = a->t.u | b->t.u;
		else if (a->type == u && b->type == ul)
			res->t.ul = a->t.u | b->t.ul;
		else if (a->type == ul && b->type == c)
			res->t.ul = a->t.ul | b->t.c;
		else if (a->type == ul && b->type == sc)
			res->t.ul = a->t.ul | b->t.sc;
		else if (a->type == ul && b->type == uc)
			res->t.ul = a->t.ul | b->t.uc;
		else if (a->type == ul && b->type == s)
			res->t.ul = a->t.ul | b->t.s;
		else if (a->type == ul && b->type == i)
			res->t.ul = a->t.ul | b->t.i;
		else if (a->type == ul && b->type == l)
			res->t.ul = a->t.ul | b->t.l;
		else if (a->type == ul && b->type == us)
			res->t.ul = a->t.ul | b->t.us;
		else if (a->type == ul && b->type == u)
			res->t.ul = a->t.ul | b->t.u;
		else if (a->type == ul && b->type == ul)
			res->t.ul = a->t.ul | b->t.ul;
		break;
	default:
		abort();
	}

	dl_delete_item(dl_first(stack));
	dl_delete_item(dl_first(stack));

	dl_insert_a(stack, res);
}
