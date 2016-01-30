#include <stdio.h>
#include<fcntl.h>
#include "arch/x86/include/generated/uapi/asm/unistd_32.h"

int main (void)
{
  int my_FD;
 
  printf("Doing SYSCALL to get ext2 fsync count: %d\n", syscall(__NR_get_ext2_fsync_count));
   my_FD = open ("/root/ext2_mount_point/test_file.txt", O_RDWR | O_CREAT | O_TRUNC);

  write (my_FD, "Lokesh Jindal", 13);
  fsync(my_FD);
  close(my_FD);
  printf("Doing SYSCALL to get ext2 fsync count: %d\n", syscall(__NR_get_ext2_fsync_count));
  return 0;
}
