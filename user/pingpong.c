#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {

  int p[2];
  char buf[100];
  pipe(p);
  int pid=fork();
  
  if(pid==0){
    write(p[1], "pong", 4);
    printf("%d: received ping\n", getpid());
    }

  else {
    wait(0);
    read(p[0], buf, 100);
    printf("%d: received pong\n", getpid());
      
  }
  
  exit(0);
}
