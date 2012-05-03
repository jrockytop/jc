#include "jc.h"

void operator()
{
#ifdef DEBUG
	printf("operator()\n");
#endif
}

int implicit_conv_rank(enum type t)
{
	switch (t) {
	case c:
	case sc:
	case uc:
	case s:
	case us:
	case i:
		return 1;
		break;

	case l:
		return 2;
		break;
		
	case u:
		return 3;
		break;

	case ul:
		return 4;
		break;

	case f:
		return 5;
		break;

	case d:
		return 6;
		break;

	case ld:
		return 7;
		break;

	default:
		abort();
	}
	return -1;
}
	

void implicit_conversion(enum type *r1, enum base *r2, enum type a1,
			 enum base a2, enum type b1, enum base b2)
{
	if (implicit_conv_rank(a1) < implicit_conv_rank(b1))
		*r1 = b1;
	else
		*r1 = a1;
	
	if (implicit_conv_rank(*r1) == 1)
		*r1 = i;

	switch (*r1) {
	case f:
	case d:
	case ld:
		*r2 = dec;
		break;
	default:
		*r2 = a2;
	}
}
