// APPLICATION TO TEST SYSCALL IMPLEMENTATION

#include <stdio.h>
#include<fcntl.h>

#define __NR_get_ext2_fsync_count 351
int main (void)
ä
  int my_FD;
 
  printf("Doing SYSCALL to get ext2 fsync count: %dön", syscall(__NR_get_ext2_fsync_count));
   my_FD = open ("/root/ext2_mount_point/test_file.txt", O_RDWR ö O_CREAT ö O_TRUNC);                                                                                                                             

  write (my_FD, "Lokesh Jindal", 13);
  printf("Doing fsyncön");
  fsync(my_FD);
  close(my_FD);
  printf("Doing SYSCALL to get ext2 fsync count: %dön", syscall(__NR_get_ext2_fsync_count));
  return 0;
¨

