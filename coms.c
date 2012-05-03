#include "jc.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

void
print_datum(datum)
struct datum *datum;
{
	int len, x, j, first = 0;

	switch(datum->base) {
	case dec:
		switch(datum->type) {
		case c:
			printf("%-23d", (int)datum->t.c);
			break;
		case sc:
			abort();
			printf("%-23d", (int)datum->t.c);
			break;
		case uc:
			printf("%-23u", (unsigned int)datum->t.uc);
			break;
		case s:
			printf("%-23hd", datum->t.s);
			break;
		case i:
			printf("%-23d", datum->t.i);
			break;
		case l:
			printf("%-23ld", datum->t.l);
			break;
		case us:
			printf("%-23hu", datum->t.us);
			break;
		case u:
			printf("%-23u", datum->t.u);
			break;
		case ul:
			printf("%-23lu", datum->t.ul);
			break;
		case f:
			printf("%-23g", datum->t.f);
			break;
		case d:
			printf("%-23g", datum->t.d);
			break;
		case ld:
			printf("%-23Lg", datum->t.ld);
			break;
		default:
			abort();
		}
		break;
	case hex:
		switch(datum->type) {
		case c:
			printf("%-#23x", (unsigned int)datum->t.c);
			break;
		case sc:
			abort();
			break;
		case uc:
			printf("%-#23x", (unsigned int)datum->t.uc);
			break;
		case s:
			printf("%-#23hx", (unsigned short)datum->t.s);
			break;
		case i:
			printf("%-#23x", (unsigned int)datum->t.i);
			break;
		case l:
			printf("%-#23lx", (unsigned long)datum->t.l);
			break;
		case us:
			printf("%-#23hx", datum->t.us);
			break;
		case u:
			printf("%-#23x", datum->t.u);
			break;
		case ul:
			printf("%-#23lx", datum->t.ul);
			break;
		case f:
			printf("%-#23x", (unsigned int)datum->t.f);
			break;
		case d:
			printf("%-#23lx", (unsigned long)datum->t.d);
			break;
		case ld:
			printf("%-#23lx", (unsigned long)datum->t.ld);
			break;
		default:
			abort();
		}
		break;
	case oct:
		switch(datum->type) {
		case c:
			printf("%-#23o", (unsigned int)datum->t.c);
			break;
		case sc:
			abort();
			break;
		case uc:
			printf("%-#23o", (unsigned int)datum->t.uc);
			break;
		case s:
			printf("%-#23ho", (unsigned short)datum->t.s);
			break;
		case i:
			printf("%-#23o", (unsigned int)datum->t.i);
			break;
		case l:
			printf("%-#23lo", (unsigned long)datum->t.l);
			break;
		case us:
			printf("%-#23ho", datum->t.us);
			break;
		case u:
			printf("%-#23o", datum->t.u);
			break;
		case ul:
			printf("%-#23lo", datum->t.ul);
			break;
		case f:
			printf("%-#23o", (unsigned int)datum->t.f);
			break;
		case d:
			printf("%-#23lo", (unsigned long)datum->t.d);
			break;
		case ld:
			printf("%-#23lo", (unsigned long)datum->t.ld);
			break;
		default:
			abort();
		}
		break;
	case chr:
		switch(datum->type) {
		case c:
			printf("%-23c", datum->t.c);
			break;
		case sc:
			abort();
			break;
		case uc:
			printf("%-23c", datum->t.uc);
			break;
		case s:
			printf("%-23c", (char)datum->t.s);
			break;
		case i:
			printf("%-23c", (char)datum->t.i);
			break;
		case l:
			printf("%-23c", (char)datum->t.l);
			break;
		case us:
			printf("%-23c", (char)datum->t.us);
			break;
		case u:
			printf("%-23c", (char)datum->t.u);
			break;
		case ul:
			printf("%-23c", (char)datum->t.ul);
			break;
		case f:
			printf("%-23c", (char)datum->t.f);
			break;
		case d:
			printf("%-23c", (char)datum->t.d);
			break;
		case ld
			:
			printf("%-23c", (char)datum->t.ld);
			break;
		default:
			abort();
		}
		break;
	case uchr:
		switch(datum->type) {
		case c:
			printf("\\%-#23o", (unsigned int)datum->t.c);
			break;
		case sc:
			abort();
			break;
		case uc:
			printf("\\%-#23o", (unsigned int)datum->t.uc);
			break;
		case s:
			printf("\\%-#23o", (unsigned int)datum->t.s);
			break;
		case i:
			printf("\\%-#23o", (unsigned int)datum->t.i);
			break;
		case l:
			printf("\\%-#23o", (unsigned int)datum->t.l);
			break;
		case us:
			printf("\\%-#23o", (unsigned int)datum->t.us);
			break;
		case u:
			printf("\\%-#23o", datum->t.u);
			break;
		case ul:
			printf("\\%-#23o", (unsigned int)datum->t.ul);
			break;
		case f:
			printf("\\%-#23o", (unsigned int)datum->t.f);
			break;
		case d:
			printf("\\%-#23o", (unsigned int)datum->t.d);
			break;
		case ld:
			printf("\\%-#23o", (unsigned int)datum->t.ld);
			break;
		default:
			abort();
		}
		break;
	case bin:
		switch(datum->type) {
		case c:
		case sc:
		case uc:
			len = sizeof(char);
			break;
		case i:
		case u:
			len = sizeof(int);
			break;
		case l:
		case ul:
			len = sizeof(long);
			break;
		case s:
		case us:
			len = sizeof(short);
			break;
		case f:
			len = sizeof(float);
			break;
		case d:
			len = sizeof(double);
			break;
		case ld:
			len = sizeof(long double);
			break;
		}
		len *= 8; /* XXX  will this always be 8 bits? */
		for (j=0; j < len; j++) {
			switch(datum->type) {
			case c:
			case sc:
			case uc:
				x = ((1 << (len - 1 - j)) & datum->t.uc) ? 1:0;
				break;
			case i:
			case u:
				x = ((1 << (len - 1 - j)) & datum->t.u) ? 1:0;
				break;
			case l:
			case ul:
				x = ((1L << (len - 1 - j)) & datum->t.ul) ? 1:0;
				break;
			case s:
			case us:
				x = ((1 << (len - 1 - j)) & datum->t.us) ? 1:0;
				break;
			case f:
			case d:
			case ld:
				if (sizeof(unsigned)*8 == len)
					x = ((1 << (len - 1 - j)) & 
					     datum->t.u) ? 1:0;
				else if (sizeof(unsigned long)*8 == len)
					x = ((1 << (len - 1 - j)) & 
					     datum->t.ul) ? 1:0;
#ifdef LONGLONG
				else if (sizeof(long long)*8 == len)
					x = ((1LL << (len - 1 - j)) & 
					     datum->t.ll) ? 1:0;
#endif
				else {
					printf("cannot convert");
					return;
				}
				break;
			}
			if (j && !(j%8))
				printf(" ");
			/*if (first || x) {*/
				printf("%d", x);
				first++;
				/*}*/
		}
		for(;first < 23; first++)
			printf(" ");
		break;
	default:
		abort();
	}
}


void store_stack() 
{
#ifdef DEBUG
	printf("store_stack()\n");
#endif
}


void copy_register_stack() 
{
#ifdef DEBUG
	printf("copy_register_stack()\n");
#endif
}


void pop_stack_to_mainstack() 
{
#ifdef DEBUG
	printf("pop_stack_to_mainstack()\n");
#endif
}


void dup_stack() 
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
        *res = *a;
        dl_insert_a(stack, res);
}


void swap_top_vals()
{
	struct datum *a, *b;

        if (stack == stack->next) {
                printf("stack empty\n");
                return;
        }

	if (stack != stack->next->next) {
	        a = (struct datum *)stack->next->item;
		b = (struct datum *)stack->next->next->item;
		stack->next->item = b;
		stack->next->next->item = a;
	}
}


void rotate_stack(int level)
{
	struct datum *a;
	int i = 0;
	Dlist tmp;

        if (stack == stack->next) {
                printf("stack empty\n");
                return;
        }

	if (level == 0) {
		a = (struct datum *)stack->next->item;
		dl_delete(stack->next);
		dl_insert_b(stack, a);
		return;
	}

	dl_traverse(tmp, stack) {
		if (i++ == level) {
			break;
		}
	}

        a = (struct datum *)tmp->item;
	dl_delete(tmp);
        dl_insert_a(stack, a);
}

void rev_rotate_stack(int level)
{ 
	struct datum *a;
	int i = 0;
	Dlist tmp;

        if (stack == stack->next) {
                printf("stack empty\n");
                return;
        }

	if (level == 0) {
		a = (struct datum *)stack->prev->item;
		dl_delete(stack->prev);
		dl_insert_a(stack, a);
		return;
	}

	dl_traverse(tmp, stack) {
		if (i++ == level) {
			break;
		}
	}

        a = (struct datum *)tmp->item;
	dl_delete(tmp);
        dl_insert_a(stack, a);
}


void print_top_value() 
{
	struct datum *d;

        if (stack == stack->next) {
                printf("stack empty\n");
                return;
        }
	d = (struct datum *)stack->next->item;
	print_datum(d);
	printf("\n");
}


void print_stack() 
{
	Dlist tmp, s = stack;
	struct datum *d;
	char *c;
	int i = 0, len;

	c = yytext+1;
	len = i = dl_length(s);
	dl_rtraverse(tmp, s) {
		printf("%d:\t", --i);
		d = (struct datum *)tmp->item;
		print_datum(d);
		printf("\n");
	}
	if (!len)
		printf("stack empty\n");
}


void print_long_stack() 
{
	Dlist tmp, stk = stack;
	struct datum *x;
	char *ch, *str;
	int z = 0, len;

	ch = yytext+2;

	len = z = dl_length(stk);

	dl_rtraverse(tmp, stk) {
		if (z == len) {
			printf("\n%s Stack:\n", (*ch) ? ch : "Main");
			printf("%-23s%-23s%-23s%s\n", "value", "type",
				"base", "level");
			printf("------------------------------------------------------------------------------\n");
			z--;
		}
		x = (struct datum *)tmp->item;
		print_datum(x);
		switch(x->type) {
			case c:
				str = "char";
				break;
			case sc:
				str = "signed char";
				break;
			case uc:
				str = "unsigned char";
				break;
			case s:
				str = "short";
				break;
			case i:
				str = "int";
				break;
			case l:
				str = "long";
				break;
			case us:
				str = "unsigned short";
				break;
			case u:
				str = "unsigned";
				break;
			case ul:
				str = "unsigned long";
				break;
			case f:
				str = "float";
				break;
			case d:
				str = "double";
				break;
			case ld:
				str = "long double";
				break;
			default:
				str = "UNKNOWN";
		}
		printf("%-23s", str);
		switch(x->base) {
			case dec:
				str = "dec";
				break;
			case hex:
				str = "hex";
				break;
			case oct:
				str = "oct";
				break;
			case chr:
				str = "chr";
				break;
			case uchr:
				str = "unsigned chr";
				break;
			case bin:
				str = "binary";
				break;
			default:
				str = "UNKNOWN";
		}
		printf("%-23s", str);
		printf("%d\n", z--);
	}

	if (!len)
		printf("stack empty\n");
}
void clear_stack() 
{
	Dlist s = stack;

#ifdef DEBUG
	printf("clear_stack()\n");
#endif

	dl_clear_all(s);
}
void pop_stack() 
{
	if (stack == stack->next) {
                printf("stack empty\n");
                return;
        }

        dl_delete_item(dl_first(stack));
}

void pop_stack_level(int level) 
{
	int i = 0;
	Dlist tmp;
	struct datum *d;

	if (level == -1) {
		clear_stack();
		return;
	}

	dl_traverse(tmp, stack) {
		if (i++ == level) {
			break;
		}
	}
	dl_delete_item(tmp);
}

void quit() 
{
#ifdef DEBUG
	printf("quit()\n");
#endif

	exit(0);
}
void machine_sizes()
{
	printf("\nMachine architecture: \t");
	fflush(stdout);
	system("uname -m");
	printf("\nType  \t\tBytes\n");
	printf("----------------------------\n");
	printf("void *\t\t%lu\n", sizeof(void *));
	printf("char  \t\t%lu\n", sizeof(char));
	printf("short \t\t%lu\n", sizeof(short));
	printf("int   \t\t%lu\n", sizeof(int));
	printf("long  \t\t%lu\n", sizeof(long));
	printf("float \t\t%lu\n", sizeof(float));
	printf("double\t\t%lu\n\n", sizeof(double));
}


void 
set_base(enum base base, int level) 
{
	int i = 0;
	Dlist tmp;
	struct datum *d;

#ifdef DEBUG
	printf("set_base()\n");
#endif

	dl_traverse(tmp, stack) {
		if (i++ == level || level == -1) {
			d = (struct datum *)tmp->item;
			d->base = base;
			if (level != -1)
				break;
		}
	}
}


void 
set_type(enum type type, int level) 
{
	int x = 0;
	Dlist tmp;
	struct datum *dat;

#ifdef DEBUG
	printf("set_type()\n");
#endif

	dl_traverse(tmp, stack) {
		if (x++ == level || level == -1) {
			dat = (struct datum *)tmp->item;
			switch (type) {
			case c:
				if (dat->type == c)
					dat->t.c = (char) dat->t.c;
				else if (dat->type == sc)
					dat->t.c = (char) dat->t.sc;
				else if (dat->type == uc)
					dat->t.c = (char) dat->t.uc;
				else if (dat->type == s)
					dat->t.c = (char) dat->t.s;
				else if (dat->type == i)
					dat->t.c = (char) dat->t.i;
				else if (dat->type == l)
					dat->t.c = (char) dat->t.l;
				else if (dat->type == us)
					dat->t.c = (char) dat->t.us;
				else if (dat->type == u)
					dat->t.c = (char) dat->t.u;
				else if (dat->type == ul)
					dat->t.c = (char) dat->t.ul;
				else if (dat->type == f)
					dat->t.c = (char) dat->t.f;
				else if (dat->type == d)
					dat->t.c = (char) dat->t.d;
				else if (dat->type == ld)
					dat->t.c = (char) dat->t.ld;
				break;
			case sc:
				if (dat->type == c)
					dat->t.sc = (signed char) dat->t.c;
				else if (dat->type == sc)
					dat->t.sc = (signed char) dat->t.sc;
				else if (dat->type == uc)
					dat->t.sc = (signed char) dat->t.uc;
				else if (dat->type == s)
					dat->t.sc = (signed char) dat->t.s;
				else if (dat->type == i)
					dat->t.sc = (signed char) dat->t.i;
				else if (dat->type == l)
					dat->t.sc = (signed char) dat->t.l;
				else if (dat->type == us)
					dat->t.sc = (signed char) dat->t.us;
				else if (dat->type == u)
					dat->t.sc = (signed char) dat->t.u;
				else if (dat->type == ul)
					dat->t.sc = (signed char) dat->t.ul;
				else if (dat->type == f)
					dat->t.sc = (signed char) dat->t.f;
				else if (dat->type == d)
					dat->t.sc = (signed char) dat->t.d;
				else if (dat->type == ld)
					dat->t.sc = (signed char) dat->t.ld;
				break;
			case uc:
				if (dat->type == c)
					dat->t.uc = (unsigned char) dat->t.c;
				else if (dat->type == sc)
					dat->t.uc = (unsigned char) dat->t.sc;
				else if (dat->type == uc)
					dat->t.uc = (unsigned char) dat->t.uc;
				else if (dat->type == s)
					dat->t.uc = (unsigned char) dat->t.s;
				else if (dat->type == i)
					dat->t.uc = (unsigned char) dat->t.i;
				else if (dat->type == l)
					dat->t.uc = (unsigned char) dat->t.l;
				else if (dat->type == us)
					dat->t.uc = (unsigned char) dat->t.us;
				else if (dat->type == u)
					dat->t.uc = (unsigned char) dat->t.u;
				else if (dat->type == ul)
					dat->t.uc = (unsigned char) dat->t.ul;
				else if (dat->type == f)
					dat->t.uc = (unsigned char) dat->t.f;
				else if (dat->type == d)
					dat->t.uc = (unsigned char) dat->t.d;
				else if (dat->type == ld)
					dat->t.uc = (unsigned char) dat->t.ld;
				break;
			case s:
				if (dat->type == c)
					dat->t.s = (short) dat->t.c;
				else if (dat->type == sc)
					dat->t.s = (short) dat->t.sc;
				else if (dat->type == uc)
					dat->t.s = (short) dat->t.uc;
				else if (dat->type == s)
					dat->t.s = (short) dat->t.s;
				else if (dat->type == i)
					dat->t.s = (short) dat->t.i;
				else if (dat->type == l)
					dat->t.s = (short) dat->t.l;
				else if (dat->type == us)
					dat->t.s = (short) dat->t.us;
				else if (dat->type == u)
					dat->t.s = (short) dat->t.u;
				else if (dat->type == ul)
					dat->t.s = (short) dat->t.ul;
				else if (dat->type == f)
					dat->t.s = (short) dat->t.f;
				else if (dat->type == d)
					dat->t.s = (short) dat->t.d;
				else if (dat->type == ld)
					dat->t.s = (short) dat->t.ld;
				break;
			case i:
				if (dat->type == c)
					dat->t.i = (int) dat->t.c;
				else if (dat->type == sc)
					dat->t.i = (int) dat->t.sc;
				else if (dat->type == uc)
					dat->t.i = (int) dat->t.uc;
				else if (dat->type == s)
					dat->t.i = (int) dat->t.s;
				else if (dat->type == i)
					dat->t.i = (int) dat->t.i;
				else if (dat->type == l)
					dat->t.i = (int) dat->t.l;
				else if (dat->type == us)
					dat->t.i = (int) dat->t.us;
				else if (dat->type == u)
					dat->t.i = (int) dat->t.u;
				else if (dat->type == ul)
					dat->t.i = (int) dat->t.ul;
				else if (dat->type == f)
					dat->t.i = (int) dat->t.f;
				else if (dat->type == d)
					dat->t.i = (int) dat->t.d;
				else if (dat->type == ld)
					dat->t.i = (int) dat->t.ld;
				break;
			case l:
				if (dat->type == c)
					dat->t.l = (long) dat->t.c;
				else if (dat->type == sc)
					dat->t.l = (long) dat->t.sc;
				else if (dat->type == uc)
					dat->t.l = (long) dat->t.uc;
				else if (dat->type == s)
					dat->t.l = (long) dat->t.s;
				else if (dat->type == i)
					dat->t.l = (long) dat->t.i;
				else if (dat->type == l)
					dat->t.l = (long) dat->t.l;
				else if (dat->type == us)
					dat->t.l = (long) dat->t.us;
				else if (dat->type == u)
					dat->t.l = (long) dat->t.u;
				else if (dat->type == ul)
					dat->t.l = (long) dat->t.ul;
				else if (dat->type == f)
					dat->t.l = (long) dat->t.f;
				else if (dat->type == d)
					dat->t.l = (long) dat->t.d;
				else if (dat->type == ld)
					dat->t.l = (long) dat->t.ld;
				break;
			case us:
				if (dat->type == c)
					dat->t.us = (unsigned short) dat->t.c;
				else if (dat->type == sc)
					dat->t.us = (unsigned short) dat->t.sc;
				else if (dat->type == uc)
					dat->t.us = (unsigned short) dat->t.uc;
				else if (dat->type == s)
					dat->t.us = (unsigned short) dat->t.s;
				else if (dat->type == i)
					dat->t.us = (unsigned short) dat->t.i;
				else if (dat->type == l)
					dat->t.us = (unsigned short) dat->t.l;
				else if (dat->type == us)
					dat->t.us = (unsigned short) dat->t.us;
				else if (dat->type == u)
					dat->t.us = (unsigned short) dat->t.u;
				else if (dat->type == ul)
					dat->t.us = (unsigned short) dat->t.ul;
				else if (dat->type == f)
					dat->t.us = (unsigned short) dat->t.f;
				else if (dat->type == d)
					dat->t.us = (unsigned short) dat->t.d;
				else if (dat->type == ld)
					dat->t.us = (unsigned short) dat->t.ld;
				break;
			case u:
				if (dat->type == c)
					dat->t.u = (unsigned) dat->t.c;
				else if (dat->type == sc)
					dat->t.u = (unsigned) dat->t.sc;
				else if (dat->type == uc)
					dat->t.u = (unsigned) dat->t.uc;
				else if (dat->type == s)
					dat->t.u = (unsigned) dat->t.s;
				else if (dat->type == i)
					dat->t.u = (unsigned) dat->t.i;
				else if (dat->type == l)
					dat->t.u = (unsigned) dat->t.l;
				else if (dat->type == us)
					dat->t.u = (unsigned) dat->t.us;
				else if (dat->type == u)
					dat->t.u = (unsigned) dat->t.u;
				else if (dat->type == ul)
					dat->t.u = (unsigned) dat->t.ul;
				else if (dat->type == f)
					dat->t.u = (unsigned) dat->t.f;
				else if (dat->type == d)
					dat->t.u = (unsigned) dat->t.d;
				else if (dat->type == ld)
					dat->t.u = (unsigned) dat->t.ld;
				break;
			case ul:
				if (dat->type == c)
					dat->t.ul = (unsigned long) dat->t.c;
				else if (dat->type == sc)
					dat->t.ul = (unsigned long) dat->t.sc;
				else if (dat->type == uc)
					dat->t.ul = (unsigned long) dat->t.uc;
				else if (dat->type == s)
					dat->t.ul = (unsigned long) dat->t.s;
				else if (dat->type == i)
					dat->t.ul = (unsigned long) dat->t.i;
				else if (dat->type == l)
					dat->t.ul = (unsigned long) dat->t.l;
				else if (dat->type == us)
					dat->t.ul = (unsigned long) dat->t.us;
				else if (dat->type == u)
					dat->t.ul = (unsigned long) dat->t.u;
				else if (dat->type == ul)
					dat->t.ul = (unsigned long) dat->t.ul;
				else if (dat->type == f)
					dat->t.ul = (unsigned long) dat->t.f;
				else if (dat->type == d)
					dat->t.ul = (unsigned long) dat->t.d;
				else if (dat->type == ld)
					dat->t.ul = (unsigned long) dat->t.ld;
				break;
			case f:
				if (dat->type == c)
					dat->t.f = (float) dat->t.c;
				else if (dat->type == sc)
					dat->t.f = (float) dat->t.sc;
				else if (dat->type == uc)
					dat->t.f = (float) dat->t.uc;
				else if (dat->type == s)
					dat->t.f = (float) dat->t.s;
				else if (dat->type == i)
					dat->t.f = (float) dat->t.i;
				else if (dat->type == l)
					dat->t.f = (float) dat->t.l;
				else if (dat->type == us)
					dat->t.f = (float) dat->t.us;
				else if (dat->type == u)
					dat->t.f = (float) dat->t.u;
				else if (dat->type == ul)
					dat->t.f = (float) dat->t.ul;
				else if (dat->type == f)
					dat->t.f = (float) dat->t.f;
				else if (dat->type == d)
					dat->t.f = (float) dat->t.d;
				else if (dat->type == ld)
					dat->t.f = (float) dat->t.ld;
				break;
			case d:
				if (dat->type == c)
					dat->t.d = (double) dat->t.c;
				else if (dat->type == sc)
					dat->t.d = (double) dat->t.sc;
				else if (dat->type == uc)
					dat->t.d = (double) dat->t.uc;
				else if (dat->type == s)
					dat->t.d = (double) dat->t.s;
				else if (dat->type == i)
					dat->t.d = (double) dat->t.i;
				else if (dat->type == l)
					dat->t.d = (double) dat->t.l;
				else if (dat->type == us)
					dat->t.d = (double) dat->t.us;
				else if (dat->type == u)
					dat->t.d = (double) dat->t.u;
				else if (dat->type == ul)
					dat->t.d = (double) dat->t.ul;
				else if (dat->type == f)
					dat->t.d = (double) dat->t.f;
				else if (dat->type == d)
					dat->t.d = (double) dat->t.d;
				else if (dat->type == ld)
					dat->t.d = (double) dat->t.ld;
				break;
			case ld:
				if (dat->type == c)
					dat->t.ld = (long double) dat->t.c;
				else if (dat->type == sc)
					dat->t.ld = (long double) dat->t.sc;
				else if (dat->type == uc)
					dat->t.ld = (long double) dat->t.uc;
				else if (dat->type == s)
					dat->t.ld = (long double) dat->t.s;
				else if (dat->type == i)
					dat->t.ld = (long double) dat->t.i;
				else if (dat->type == l)
					dat->t.ld = (long double) dat->t.l;
				else if (dat->type == us)
					dat->t.ld = (long double) dat->t.us;
				else if (dat->type == u)
					dat->t.ld = (long double) dat->t.u;
				else if (dat->type == ul)
					dat->t.ld = (long double) dat->t.ul;
				else if (dat->type == f)
					dat->t.ld = (long double) dat->t.f;
				else if (dat->type == d)
					dat->t.ld = (long double) dat->t.d;
				else if (dat->type == ld)
					dat->t.ld = (long double) dat->t.ld;
				break;
			}

			dat->type = type;
			if (level != -1)
				break;
		}
	}
}

void 
do_ctime(int level) 
{
	int i = 0;
	Dlist tmp;
	struct datum *d;

	dl_traverse(tmp, stack) {
		if (i++ == level || level == -1) {
			d = (struct datum *)tmp->item;
			printf("ctime(%ld) = %s", d->t.l, 
					ctime((time_t *)&d->t.l));
			if (level != -1)
				break;
		}
	}
}

int
level(char *str)
{
	char *c;

	if (c = strchr(str, ':'))
		return atoi(++c);
	return 0;
}
