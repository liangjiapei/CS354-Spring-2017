/* app1.c - app1 */

#include <xinu.h>


/*------------------------------------------------------------------------
 *  app1  -  example function that calls another function with one argument
 *------------------------------------------------------------------------
 */

char app1(char c) 
{
	
	struct procent *prptr = &proctab[currpid];

	int address1;
	int content1;
	asm(
		"movl %%esp, %0;"
		: "=r" (address1)
	);

	asm(
		"movl (%%esp), %0;"
		: "=r" (content1)
	);

	kprintf("(4.2)Before func1 is called: \n");
	kprintf("(4.2)Address of top of the runtime stack: 0x%08X\n", address1);
	kprintf("(4.2)Content of top of the runtime stack: 0x%08X\n\n", content1);

	kprintf("(4.3)After app1 is run: \n");
	kprintf("(4.3)app1 (PID: %d)'s stored value of esp: 0x%08X\n", currpid, prptr->prstkptr);
	kprintf("(4.3)app1 (PID: %d)'s stored value of base of runtime stack: 0x%08X\n\n", currpid, prptr->prstkbase);


	char result = (char)func1(c);


	int address2;
	int content2;
	asm(
		"movl %%esp, %0;"
		: "=r" (address2)
	);

	asm(
		"movl (%%esp), %0;"
		: "=r" (content2)
	);

	kprintf("(4.2)After func1 is returned:\n");
	kprintf("(4.2)Address of top of the runtime stack: 0x%08X\n", address2);
	kprintf("(4.2)Content of top of the runtime stack: 0x%08X\n\n", content2);


	return result;

}