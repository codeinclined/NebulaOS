C32_OBJECTS=k_main.e32.o
C32_SRC=$(C32_OBJECTS,.e32.o=.c)
C32_FLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
	-nostartfiles -nodefaultlibs -Wall -Wextra -Werror
C32_COMMAND=gcc

ASM32_OBJECTS=entry.e32.no
ASM32_SRC=$(ASM32_OBJECTS,.e32.no=.asm)
ASM32_FLAGS=-felf
ASM32_COMMAND=nasm

LINK_FLAGS=-Tlink.ld -melf_i386
LINK_COMMAND=ld

KERNEL_BIN=nebula.krn

all: $(ASM32_OBJECTS) $(C32_OBJECTS) link

clean:
	-rm -f *.{o,no} $(KERNEL_BIN)

%.e32.no : %.asm
	$(ASM32_COMMAND) $(ASM32_FLAGS) -o $@ $?

%.e32.o : %.c
	$(C32_COMMAND) $(C32_FLAGS) -c $? -o $@

link:
	$(LINK_COMMAND) $(LINK_FLAGS) -o $(KERNEL_BIN) $(ASM32_OBJECTS) $(C32_OBJECTS)

rebuild: clean all