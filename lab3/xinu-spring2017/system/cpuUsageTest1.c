/* cpuUsageTest1.c - cpuUsageTest1 */

#include <xinu.h>

/*------------------------------------------------------------------------
 * cpuUsageTest1  -  Test CPU usage
 *------------------------------------------------------------------------
 */

void cpuUsageTest1() {
	int count = 0;
  // int i;
  // for (i = 0; i < 100; i++) {
  while(1) {
    while (count < 1000) {
      count++;
    }
    struct procent *prptr = &proctab[currpid];
    kprintf("\n%s CPU Usage: %u\n", prptr->prname, prptr->prcpuused);
    // sleepms(1);
  }
  // }

}
