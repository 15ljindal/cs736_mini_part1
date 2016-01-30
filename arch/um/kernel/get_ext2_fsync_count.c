#include "linux/kernel.h"
#include "linux/unistd.h"

extern int global_ext2_fsync_counter;

asmlinkage
int sys_get_ext2_fsync_count( void ) {
  printk(KERN_INFO "Inside get_ext2_fsync_count returning %d\n", global_ext2_fsync_counter);
  return global_ext2_fsync_counter;
}


