/* looper.c - looper */

#include <xinu.h>

/*------------------------------------------------------------------------
 * looper  -  Print a number infinitly
 *------------------------------------------------------------------------
 */

void looper(int val) {
	int count = 1;
	while (1) {
		kprintf("%d: %d\n", count, val);
		count++;
	}
}
