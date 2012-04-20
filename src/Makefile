###############################################################################
#       Makefile
###############################################################################
#  Hand-written makefile for compiling the NebulaOS kernel. Don't consider
#  this file to be permanent; I may switch to another system in the future.
###############################################################################
#  DEPENDS:
#  make (This makefile was tested using GNU Make 3.82)
#  nasm
#  gcc capable of cross-compiling (LLVM may be supported in the future)
#  binutils
#  updatekernel.sh (part of the NebulaOS source tree)
###############################################################################
#  Author:  Joshua William Taylor <taylor.joshua88@gmail.com>
#  Project: NebulaOS
#  Created: 19APR2012
#  License: zlib License
###############################################################################
#  Copyright (c) 2012 Joshua William Taylor <taylor.joshua88@gmail.com>
#
#    This software is provided 'as-is', without any express or implied
#    warranty. In no event will the authors be held liable for any damages
#    arising from the use of this software.
#
#    Permission is granted to anyone to use this software for any purpose,
#    including commercial applications, and to alter it and redistribute it
#    freely, subject to the following restrictions:
#
#    1. The origin of this software must not be misrepresented; you must not
#    claim that you wrote the original software. If you use this software
#    in a product, an acknowledgment in the product documentation would be
#    appreciated but is not required.
#
#    2. Altered source versions must be plainly marked as such, and must not be
#    misrepresented as being the original software.
#
#    3. This notice may not be removed or altered from any source
#    distribution.
###############################################################################

C32_OBJECTS=k_main.e32.o kmemory.e32.o kstdio.e32.o video_primitive.e32.o
C32_SRC=$(C32_OBJECTS,.e32.o=.c)
C32_FLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
	-nostartfiles -nodefaultlibs -std=gnu99
C32_COMMAND=gcc

ASM32_OBJECTS=entry.e32.no ports.e32.no
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

update: all
	./updatekernel.sh
