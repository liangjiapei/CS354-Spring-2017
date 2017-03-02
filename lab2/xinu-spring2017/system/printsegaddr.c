/* printsegaddr.c - printsegaddr */

#include <xinu.h>

/*------------------------------------------------------------------------
 * printsegaddr.c  -  prints the address of the start of the text, data, 
 * bss segments and the end of the bss segment of XINU
 *------------------------------------------------------------------------
 */

void printsegaddr() 
{
	kprintf("Start of TEXT segment:        address: 0x%08X\n", &text);
	kprintf("First byte of TEXT segment:   address: 0x%08X, content: 0x%08X\n", &text, text);
	kprintf("Second byte of TEXT segment:  address: 0x%08X, content: 0x%08X\n", ((uint32)&text + 1), (&text)[1]);	
	kprintf("Third byte of TEXT segment:   address: 0x%08X, content: 0x%08X\n", ((uint32)&text + 2), (&text)[2]);
	kprintf("Fourth byte of TEXT segment:  address: 0x%08X, content: 0x%08X\n\n", ((uint32)&text + 3), (&text)[3]);

	kprintf("Start of DATA segment:        address: 0x%08X\n", (uint32)&data);
	kprintf("First byte of TEXT segment:   address: 0x%08X, content: 0x%08X\n", &data, data);
	kprintf("Second byte of TEXT segment:  address: 0x%08X, content: 0x%08X\n", ((uint32)&data + 1), (&data)[1]);	
	kprintf("Third byte of TEXT segment:   address: 0x%08X, content: 0x%08X\n", ((uint32)&data + 2), (&data)[2]);
	kprintf("Fourth byte of TEXT segment:  address: 0x%08X, content: 0x%08X\n\n", ((uint32)&data + 3), (&data)[3]);

	kprintf("Start of BSS segment:         address: 0x%08X\n", (uint32)&bss);
	kprintf("First byte of TEXT segment:   address: 0x%08X, content: 0x%08X\n", &bss, bss);
	kprintf("Second byte of TEXT segment:  address: 0x%08X, content: 0x%08X\n", ((uint32)&bss + 1), (&bss)[1]);	
	kprintf("Third byte of TEXT segment:   address: 0x%08X, content: 0x%08X\n", ((uint32)&bss + 2), (&bss)[2]);
	kprintf("Fourth byte of TEXT segment:  address: 0x%08X, content: 0x%08X\n\n", ((uint32)&bss + 3), (&bss)[3]);

	kprintf("End of BSS segment:           address: %08X\n", (uint32)&ebss - 1) ;
	kprintf("First byte of TEXT segment:   address: 0x%08X, content: 0x%08X\n", &ebss, ebss);
	kprintf("Second byte of TEXT segment:  address: 0x%08X, content: 0x%08X\n", ((uint32)&ebss + 1), (&ebss)[1]);	
	kprintf("Third byte of TEXT segment:   address: 0x%08X, content: 0x%08X\n", ((uint32)&ebss + 2), (&ebss)[2]);
	kprintf("Fourth byte of TEXT segment:  address: 0x%08X, content: 0x%08X\n\n", ((uint32)&ebss + 3), (&ebss)[3]);


	kprintf("Length of TEXT segment: %d bytes\n", (uint32)&etext - (uint32)&text);
	kprintf("Length of DATA segment: %d bytes\n", (uint32)&edata  - (uint32)&data);
	kprintf("Length of BSS  segment: %d bytes\n\n", (uint32)&ebss - (uint32)&bss);	
}

