/* stacksmashV.c - stacksmashV */

#include <xinu.h>

void stacksmashV()
{
	char v = 'V';
	putc(CONSOLE, v);

	long victimESPAddress;

	asm(
		"movl %%esp, %0;"
		: "=r" (victimESPAddress)
	);

	kprintf("Victim: Address of top of victim runtime stack:  0x%08X\n", victimESPAddress);

	sleepms(800);

	putc(CONSOLE, v);
}
