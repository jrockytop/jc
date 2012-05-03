#include "jc.h"

void init()
{
	int i;

#ifdef DEBUG
	printf("init()\n");
#endif

	stack = dl_create();
	for (i=0; i < MAX_STACKS; i++)
		mem_stacks[i] = dl_create();
}
