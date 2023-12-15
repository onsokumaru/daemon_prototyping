#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
  pid_t pid = getpid();
  pid_t ppid = getppid();

  printf("Program is running...\n");
  printf("Process PID is: %d\n", pid);
  printf("Parent Process PID is: %d\n", ppid);
  sleep(120);
  printf("Program is exiting...\n");

  return 0;
}



