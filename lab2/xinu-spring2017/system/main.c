/*  main.c  - main */

#include <xinu.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>


process	main(void)
{
	// Added Author and UserID
	kprintf("\nHello World!\n");
	kprintf("\nAuthor: Jiapei Liang, UserID: liang98\n");

	kprintf("\nThis is Lab1, I am trying to get acquanted with XINU.\n");

	kprintf("\nThis is the first XINU app and running function main() in system/main.c.\n");
	kprintf("\nIt was created by nulluser() in system/initialize.c using create().\n");
	kprintf("\nIts creator will turn itself into the do-nothing null process.\n");
	kprintf("\nMain process will create a second XINU app that runs shell() in shell/shell.c as an example.\n");
	kprintf("\nYou can do something else, or do nothing; it's completely up to you.\n");
	kprintf("\n...creating a shell\n");
	// recvclr();
	/*
	resume(create(shell, 8192, 50, "shell", 1, CONSOLE));

	sleep(1);
	*/

	/* Lab 2 */
	/*
	kprintf("\n===================== Problem 3 =====================\n");
	long test = 0x12345678;
	kprintf("input value: 0x%X\n", test);
	kprintf("test net2hostl:  0x%X\n", net2hostl(test));
	kprintf("test net2hostlgcc: 0x%X\n", net2hostlgcc(test));
	kprintf("test net2hostlasm: 0x%X\n\n", net2hostlasm(test));



	kprintf("\n===================== Problem 4.1 =====================\n");
	printsegaddr();




	kprintf("\n===================== Problem 4.2/4.3 =====================\n");
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

	kprintf("(4.2)Before app1 is created: \n");
	kprintf("(4.2)Address of top of the runtime stack: 0x%08X\n", address1);
	kprintf("(4.2)Content of top of the runtime stack: 0x%08X\n\n", content1);


	struct procent *prptr = &proctab[currpid];
	kprintf("(4.3)Before app1 is created: \n");
	kprintf("(4.3)Main Process(PID: 2)'s stored value of esp: 0x%08X\n", prptr->prstkptr);
	kprintf("(4.3)Main Process(PID: %d)'s stored value of base of runtime stack: 0x%08X\n\n", currpid, prptr->prstkbase);

	pid32 pid = create(app1, 1024, 20, "app1", 1, 'c');

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

	kprintf("(4.2)After app1 is created but before it is resumed:\n");
	kprintf("(4.2)Address of top of the runtime stack: 0x%08X\n", address2);
	kprintf("(4.2)Content of top of the runtime stack: 0x%08X\n\n", content2);

	kprintf("(4.3)After app1 is created: \n");
	kprintf("(4.3)Main Process(PID: 2)'s stored value of esp: 0x%08X\n", prptr->prstkptr);
	kprintf("(4.3)Main Process(PID: %d)'s stored value of base of runtime stack: 0x%08X\n\n", currpid, prptr->prstkbase);

	resume(pid);

	sleep(5);

	int address3;
	int content3;
	asm(
		"movl %%esp, %0;"
		: "=r" (address3)
	);

	asm(
		"movl (%%esp), %0;"
		: "=r" (content3)
	);

	kprintf("(4.2)After app1 finished:\n");
	kprintf("(4.2)Address of top of the runtime stack: 0x%08X\n", address3);
	kprintf("(4.2)Content of top of the runtime stack: 0x%08X\n\n", content3);

	*/

	/*
	kprintf("\n===================== Problem 5 =====================\n");
	int looperPID1 = create(looper, 512, 10, "looper1", 1, 100);
	int looperPID2 = create(looper, 512, 10, "looper2", 1, 200);
	int looperPID3 = create(looper, 512, 30, "looper3", 1, 300);


	kprintf("main\n");
	resume(looperPID1);
	kprintf("main\n");
	resume(looperPID2);
	kprintf("main\n");
	resume(looperPID3);

	int i;
	for (i = 0; i < 10; i++) {
		sleepms(3);
		kprintf("MAIN\n");
	}
	*/

	/*
	kprintf("\n===================== Problem 6 =====================\n");
	resume(create(stacksmashA, 1024, 10, "stacksmashA", 0));

	resume(create(stacksmashV, 1024, 20, "stacksmashV", 0));

	sleep(5);
	*/



	recvclr();

	/* Wait for shell to exit and recreate it */

	while (TRUE) {
		receive();
		sleepms(200);
		kprintf("\n\nMain process recreating shell\n\n");
		resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
	}

	return OK;
}
