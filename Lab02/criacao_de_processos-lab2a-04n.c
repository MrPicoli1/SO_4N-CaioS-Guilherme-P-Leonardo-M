#include <stdio.h>
#include <unistd.h>

int main(){
  int x;

  x = 0;
  fork();
  x = 1;
  printf("I'm process %ld and my 'x' is %d\n", (long)getpid(), x);
  return 0;
}

