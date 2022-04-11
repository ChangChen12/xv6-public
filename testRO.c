#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"

int
main(int argc, char *argv[])
{
  char *x = sbrk(0);
  sbrk(PGSIZE);
  *x = 200;
  mprotect(x, 1) ;
  int y = fork();
  if(y == 0){
    printf(1, "Protected: %d \n", *x);
    munprotect(x, 1);
    *x = 10;
    printf(1, "Unprotected: %d \n", *x);
    exit();
  }
  else{
    wait();
    printf(1, "trapping it \n");
    *x = 10;
    exit();
  }
 exit();
} 