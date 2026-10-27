[BITS 16]
[ORG 0x7C00]
start:
    mov si, msg
print:
    lodsb
    or al, al
    jz load_kernel
    mov ah, 0x0E
    int 0x10
    jmp print
load_kernel:
    jmp 0x0000:0x7E00
msg db 'COIO 0.0.1 - Glass(OS) Bootloader', 13, 10, 0
