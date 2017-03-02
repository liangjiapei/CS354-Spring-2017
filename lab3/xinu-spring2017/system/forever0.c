/*  forever0.c  - forever0 */

#include <xinu.h>
#include <stdio.h>

process	forever0(void)
{
	while (TRUE) {
		putc(CONSOLE, 's');
		sleep(1);
	}

	return OK;
}
