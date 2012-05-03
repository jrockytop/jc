#include <stdlib.h>
#include "jc.h"

void
push(t, b, scan)
enum type t;
enum base b;
char *scan;
{
	struct datum *dat;
	int j;

	dat = (struct datum *) malloc(sizeof(struct datum));
	if (!dat) {
		fprintf(stderr, "Out of memory\n");
		return;
	}
	dat->type = t;
	dat->base = b;

	if (b == bin) {
		/* Binary scanf */
		dat->t.u = 0;
		for (j=1; yytext[j]; j++) {
			dat->t.u <<= 1;
			if (yytext[j] == '1')
				dat->t.u |= 1;
		}
	} else {

	switch (t) {
	case c:
		sscanf(yytext, scan, &dat->t.c);
		break;
	case sc:
		sscanf(yytext, scan, &dat->t.sc);
		break;
	case uc:
		sscanf(yytext, scan, &dat->t.uc);
		break;
	case s:
		sscanf(yytext, scan, &dat->t.s);
		break;
	case i:
		sscanf(yytext, scan, &dat->t.i);
		break;
	case l:
		sscanf(yytext, scan, &dat->t.l);
		break;
	case us:
		sscanf(yytext, scan, &dat->t.us);
		break;
	case u:
		sscanf(yytext, scan, &dat->t.u);
		break;
	case ul:
		sscanf(yytext, scan, &dat->t.ul);
		break;
	case f:
		sscanf(yytext, scan, &dat->t.f);
		break;
	case d:
		sscanf(yytext, scan, &dat->t.d);
		break;
	case ld:
		sscanf(yytext, scan, &dat->t.ld);
		break;
	default:
		fprintf(stderr, "Unknown type\n");
		abort();
	}
	}

	dl_insert_a(stack, dat);
}
	
#if 0
void strip(s)
char *s;
{
	int i;

	for (i=0; i < strlen(s); i++) {
		if (!isdigit(s[i]))
			s[i] = '\0';
	}
}
void push_unsigned_hex() 
{
	struct datum *d;

#ifdef DEBUG
	printf("push_unsigned_hex()\n");
#endif

	d = datum(ui, uh);
	sscanf(yytext, "%x", &d->t.ui);
}
void push_long_hex() 
{
	struct datum *d;

#ifdef DEBUG
	printf("push_long_hex()\n");
#endif

	d = datum(lh, li);
	sscanf(yytext, "%lx", &d->t.li);
	dl_insert_a(stack, d);
}
void push_unsigned_long_hex() 
{
	struct datum *d;

#ifdef DEBUG
	printf("push_unsigned_long_hex()\n");
#endif

	d = datum(luh, lui);
	sscanf(yytext, "%lx", &d->t.lui);
	dl_insert_a(stack, d);
}
void push_signed_hex() 
{
	struct datum *d;

#ifdef DEBUG
	printf("push_signed_hex()\n");
#endif

	d = datum(sh, si);
	sscanf(yytext, "%x", &d->t.si);
	dl_insert_a(stack, d);
}
void push_bin() 
{
	struct datum *d;

#ifdef DEBUG
	printf("push_bin()\n");
#endif
}
void push_unsigned_octal() 
{
	struct datum *d;

#ifdef DEBUG
	printf("push_unsigned_octal()\n");
#endif

	d = datum(uo, ui);
	sscanf(yytext, "%o", &d->t.ui);
	dl_insert_a(stack, d);
}
void push_long_octal() 
{
	struct datum *d;

#ifdef DEBUG
	printf("push_long_octal()\n");
#endif

	d = datum(lo, li);
	sscanf(yytext, "%lo", &d->t.li);
	dl_insert_a(stack, d);
}
void push_unsigned_long_octal() 
{
	struct datum *d;

#ifdef DEBUG
	printf("push_unsigned_long_hex()\n");
#endif

	d = datum(luo, lui);
	sscanf(yytext, "%lo", &d->t.lui);
	dl_insert_a(stack, d);
}
void push_signed_octal() 
{
	struct datum *d;

#ifdef DEBUG
	printf("push_signed_octal()\n");
#endif

	d = datum(so, si);
	sscanf(yytext, "%o", &d->t.si);
	dl_insert_a(stack, d);
}
void push_unsigned_int() 
{
	struct datum *d;

#ifdef DEBUG
	printf("push_unsigned_int()\n");
#endif

	d = datum(nil, ui);
	sscanf(yytext, "%d", &d->t.ui);
	dl_insert_a(stack, d);
}
void push_long_int() 
{
	struct datum *d;

#ifdef DEBUG
	printf("push_long_int()\n");
#endif

	d = datum(nil, li);
	sscanf(yytext, "%ld", &d->t.li);
	dl_insert_a(stack, d);
}
void push_unsigned_long_int() 
{
	struct datum *d;

#ifdef DEBUG
	printf("push_unsigned_long_int()\n");
#endif

	d = datum(nil, lui);
	if (sscanf(yytext, "%ld", &d->t.lui) != 1) {
		free(d);
		fprintf(stderr, "unacceptable number\n");
		return;
	}
	dl_insert_a(stack, d);
}
void push_signed_int() 
{
	struct datum *d;

#ifdef DEBUG
	printf("push_signed_int()\n");
#endif

	d = datum(nil, si);
	sscanf(yytext, "%d", &d->t.si);
	dl_insert_a(stack, d);
}
void push_double() 
{
	struct datum *x;

	strip(yytext);

#ifdef DEBUG
	printf("push_double()\n");
#endif

	x = datum(nil, d);
#if 0
	sscanf(yytext, "%lf", &x->t.d);
#else
	x->t.d = (double)strtod(yytext, NULL);
#endif
	dl_insert_a(stack, x);
}
void push_float() 
{
	struct datum *d;

#ifdef DEBUG
	printf("push_float()\n");
#endif

	d = datum(nil, f);
	sscanf(yytext, "%f", &d->t.f);
	dl_insert_a(stack, d);
}

#endif
