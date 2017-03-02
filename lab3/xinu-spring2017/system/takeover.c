/* takeover.c - takeover */

#include <xinu.h>

/*------------------------------------------------------------------------
 * takeover  -  Malocious code
 *------------------------------------------------------------------------
 */

void takeover()
{
  int i;
  for (i = 0; i < 6; i++) {
    kprintf("takeover succeeded\n");
  }
}
