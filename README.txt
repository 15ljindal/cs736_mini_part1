README.txt
Author: Lokesh Jindal
Date:   Jan, 2016
E-mail: lokeshjindal15@cs.wisc.edu


After the Linux kernel 3.12.36 has been downloaded, build it.
# bzip2 -dkv Gentoo-x86-root_fs.bz2 

Building from source
====================
# clean up if you mess up at any step
# make mrproper
# make mrproper ARCH=um

make defconfig ARCH=um
make menuconfig ARCH=um (In the menu that pops up, select a 32-bit kernel (not 64-bit), and make sure to include a bunch of file systems, specifically ext2 (as it will be used later). Select ext2,ext3,ext4 file systems
# make ARCH=um -j4
ls -l linux

./linux ubda=../Gentoo-x86-root_fs mem=256m

And the linux should boot!

Login with "root" as username and no password.

"halt" to shut down.

# add printk in fs/ext2/file.ci and recompile linux

Then make a copy of Gento disk image.
cp ../../Gentoo-x86-root_fs ../../Gentoo-x86-root_fs_COPY

IMPLEMENTING A SYSTEM CALL
==========================
Files changed:
arch/x86/include/generated/uapi/asm/unistd_32.h
arch/x86/syscalls/syscall_32.tbl
fs/ext2/file.c

2 NEWLY ADDED FILES
arch/um/include/asm/get_ext2_fsync_count.h
arch/um/kernel/get_ext2_fsync_count.c

arch/um/kernel/Makefile

Now compile linux
make ARCH=um -j4

./linux ubda=../../Gentoo-x86-root_fs ubdb=../../Gentoo-x86-root_fs_COPY mem=256m
mkfs -t ext2 /dev/ubdb
# mkdir ext2_mount_point
mount /dev/ubdb ext2_mount_point/


Testing system call
===================
vim test_syscall.c
gcc test_syscall.c -o test_syscall
./test_syscall
dmesg

Alternate way to test system call:
----------------------------------

Now in host file system, we will create the test code. create test_syscall.c and compile using "gcc -m32 test_syscall.c -o test_syscall"

now run UML
./linux ubda=../../Gentoo-x86-root_fs ubdb=../../Gentoo-x86-root_fs_COPY mem=256m
mkfs -t ext2 /dev/ubdb
# mkdir ext2_mount_point
mount /dev/ubdb ext2_mount_point/
df -h

# mkdir test_syscall_mount_point
mount none test_syscall_mount_point -t hostfs -o /afs/cs.wisc.edu/u/l/o/lokeshjindal15/private/UWM_COURSES/cs736/mini_project/part1/linux-3.12.36_gitbase/linux-3.12.36
cd test_syscall_mount_point/
./test_syscall

References
==========
http://user-mode-linux.sourceforge.net/old/lksct/index.html
http://www.imada.sdu.dk/~daniel/DM510-2013/assignment2/system-call.html
https://kerneltweaks.wordpress.com/2014/11/26/add-system-call-to-linux-kernel/
https://arvindsraj.wordpress.com/2012/10/05/adding-hello-world-system-call-to-linux/


