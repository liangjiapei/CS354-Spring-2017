/* cpubnd.c - cpubnd */

#include <xinu.h>

/*------------------------------------------------------------------------
 * cpubnd  -  Test dynamic priority scheduling
 *------------------------------------------------------------------------
 */

void cpubnd()
{

  struct procent *prptr = &proctab[currpid];

  int count = 0;
  int i, j;
  for (i = 0; i < 100; i++) {
    for (j = 0; j < 100; j++) {
      // Insert code that performs memory copy (slow) and/or
      // ALU operations (fast).
      // Note: this loop consumes significant CPU cycles.
      count++;
    }
    // Using kprintf, print the pid followed by the outer loop count i,
    // the process's priority, and the remaining time slice (preempt).
    kprintf("pid: %d, outer loop count: %d, priority: %u, remaining time slice: %u\n", currpid, i, prptr->prcpuused, preempt);
  }
  // Print the CPU time consumed by the process that is recorded in the
  // prcpuused field of the current process's process table entry.
  kprintf("pid: %d, CPU usage: %u\n", currpid, prptr->prcpuused);

}
