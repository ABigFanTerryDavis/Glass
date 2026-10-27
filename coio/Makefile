all:
	nasm boot.asm -f bin -o boot.bin
	gcc shell.c -o coio-shell
clean:
	rm -f boot.bin coio-shell
