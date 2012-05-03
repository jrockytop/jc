#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

#define MAX_STACKS	52
#define ALIGN		"%-24"
#define ALIGN1		"%-23"
#define ALIGN2		"%-22"

Dlist stack;
Dlist mem_stacks[MAX_STACKS];

enum base {dec, hex, oct, chr, uchr, bin};
enum type {c, sc, uc, s, i, l, us, u, ul, f, d, ld};

struct datum {
	enum base base;
	enum type type;
	union {
		/* the compiler determines if (char) is signed or unsigned */
		char			c; 
		signed char		sc;
		unsigned char		uc;

		short			s;
		int			i;
		long			l;

		unsigned short		us;
		unsigned 		u;
		unsigned long		ul;

		float			f;
		double			d;
		long double		ld;

#ifdef LONGLONG
		long long		ll;
#endif
	} t;
};

extern char *yytext;

extern void init();
extern void push(enum type, enum base, char *scan); 
extern void operator(); 
extern void machine_sizes(); 
extern void store_register(); 
extern void store_stack(); 
extern void copy_register_stack(); 
extern void pop_stack_to_mainstack(); 
extern void dup_stack(); 
extern void swap_top_vals(); 
extern void rotate_stack(); 
extern void rev_rotate_stack(); 
extern void print_top_value(); 
extern void print_stack(); 
extern void print_long_stack(); 
extern void clear_stack(); 
extern void pop_stack(); 
extern void pop_stack(); 
extern void set_base(); 
extern void set_type(); 
extern void help(); 
extern void do_ctime();
extern void quit(); 

int implicit_conv_rank(enum type t);
void implicit_conversion(enum type *r1, enum base *r2, enum type a1,
			 enum base a2, enum type b1, enum base b2);

extern void add(); 
extern void sub(); 
extern void mult(); 
extern void divide(); 
extern void lshift(); 
extern void rshift(); 
extern void or(); 
extern void and(); 
extern void mod(); 
extern void bit_comp();
extern void xor();

extern int level(char *);
