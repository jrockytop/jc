#include "jc.h"

void store_register(char *p)
{
#if 1
        printf("store_register()\n");
#endif
}

recall_register(char *p)
{ 
	if (p)
		printf("recall_register: %s\n", p);

	return 0;
}

