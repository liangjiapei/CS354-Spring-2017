

.global net2hostl

net2hostl:
	pushl %ebp
	movl %esp, %ebp
	movl 8(%ebp), %eax
	bswap %eax
	leave
	ret

