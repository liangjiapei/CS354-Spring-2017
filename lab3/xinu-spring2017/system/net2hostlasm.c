/* net2hostlasm.c - net2hostlasm */

/*------------------------------------------------------------------------
 * net2hostlgcc  -  Convert big endian to little endian
 *------------------------------------------------------------------------
 */

long net2hostlasm(long x)
{
	long result;

	asm("movl %1, %0;"
	    "bswap %0;"
	    : "=r" (result) 
	    : "r" (x)
	);

	return result;

}
