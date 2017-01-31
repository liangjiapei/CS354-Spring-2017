/*  main.c  - main */

#include <xinu.h>
#include <string.h>
#include <stdio.h>


extern void forever0(void);

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
	recvclr();
	resume(create(shell, 8192, 50, "shell", 1, CONSOLE));

	sleep(1);

	
	pid32 pid = create(forever0, 1024, 20, "forever0", 0, CONSOLE);

	resume(pid);

	sleep(10);

	kill(pid);
	recvclr();

	struct procent *prptr = &proctab[pid];
	if (prptr->prstate == PR_FREE) {
		kprintf(" forever0 was killed successfully.");
	} else {
		kprintf(" Failed to kill forever0.");
	}

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

