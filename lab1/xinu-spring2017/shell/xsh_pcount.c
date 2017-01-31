/* xsh_pcount.c - xsh_pcount */

#include <xinu.h>
#include <stdio.h>
#include <string.h>

/*------------------------------------------------------------------------
 * xsh_pcount - shell command to print the number of processes
 *------------------------------------------------------------------------
 */

shellcmd xsh_pcount(int nargs, char *args[])
{

	struct procent *prptr;		/* pointer to process */

	int32 numProcesses = 0;
	int32 i;


	for (i = 0; i < NPROC; i++) {
	
		prptr = &proctab[i];

		if (prptr->prstate == PR_FREE) { // skip unused slots
			continue;
		}

		numProcesses++;
	}

	printf("The number of processes: %d\n", numProcesses);
	return 0;
}
