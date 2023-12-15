#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int main (int argc, char *argv[])
{
  pid_t parent_pid = getpid();
  pid_t parent_ppid = getppid();
  pid_t parent_psid = getsid(parent_pid);
  pid_t child_pid;
  pid_t running_child_pid;
  pid_t running_child_ppid;
  pid_t running_child_psid;

  printf("Parent Program starting...\n");
  printf("=======================================\n");
  printf("Process ID: %d\n", parent_pid);
  printf("Parent Process ID: %d\n", parent_ppid);
  printf("Parent Session ID: %d\n", parent_psid);
  printf("=======================================\n");
  printf("Forking Current Process...\n");

  child_pid = fork();
  if (child_pid == 0) {
    // inside child process
    running_child_pid = getpid();
    running_child_ppid = getppid();
    running_child_psid = getsid(running_child_pid);
    sleep(3);
    printf("\n");
    printf("Child Process Starting...\n");
    printf("=======================================\n");
    printf("Child PID as seen from Child: %d\n", running_child_pid);
    printf("Child PPID as seen from Child: %d\n", running_child_ppid);
    printf("Child SID as seen from Child: %d\n", running_child_psid);
    printf("=======================================\n");
    sleep(30); 
    printf("Child Process Exiting...\n");

  } else if (child_pid > 0) {
    // inside parent process
    printf("Parent Process Terminating...\n");
    
  } else {
    perror("An error occurred when trying to fork the process\n");
    exit(EXIT_FAILURE);
  }

  return 0;
}



