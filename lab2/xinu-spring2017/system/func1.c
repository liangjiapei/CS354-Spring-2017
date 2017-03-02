/* func1.c - func1 */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  func1  -  return a int that is 2 times of input char value
 *------------------------------------------------------------------------
 */

 int func1(char c)
 {

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

	kprintf("(4.2)After func1 is called but before it is returned: \n");
	kprintf("(4.2)Address of top of the runtime stack: 0x%08X\n", address1);
	kprintf("(4.2)Content of top of the runtime stack: 0x%08X\n\n", content1);
 	

 	return (int)(c * 2);
 }

