#!/usr/bin/env sh

###############################################################################
#       updatekernel.sh
###############################################################################
#  Simple script for users of a QEMU supported image file to update
#    their image with the NebulaOS kernel image found in the working directory.
#
#  Note that one must either create the directory /media/NebulaOS Image/
#    or modify this script.
###############################################################################
#  DEPENDS:
#  qemu-nbd (In ArchLinux this is packaged in the qemu / qemu-kvm package)
#  nbd kernel module (compiled-in or available as a module)
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

read -p "Press enter when ready to start transfer... (Make sure loopback is unmounted)"
sudo modprobe nbd max_part=4

if [ ! -b /dev/nbd0p1 ]
then
  echo -n "Establishing network block device for NebulaOS image..."
  sudo qemu-nbd -c /dev/nbd0 ~/VirtualBox\ VMs/NebulaOS/NebulaOS.vdi
  echo "done"
fi

sudo mount /dev/nbd0p1 /media/NebulaOS\ Image
echo -n "Copying kernel to NBD mapped image mounted to /media/NebulaOS Image/..."
sudo cp ./nebula.krn /media/NebulaOS\ Image/boot/nebula.krn
sudo umount /media/NebulaOS\ Image
echo "done"
echo "Script finished."
