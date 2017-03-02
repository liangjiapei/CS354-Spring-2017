/* stacksmashV.c - stacksmashV */

#include <xinu.h>

void stacksmashV()
{
	char v = 'V';
	putc(CONSOLE, v);

	sleepms(200);

	putc(CONSOLE, v);
}
