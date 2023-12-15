#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int main (int argc, char *argv[])
{
  pid_t parent_pid = getpid();
  pid_t parent_ppid = getppid();
  pid_t parent_psid = getsid(parent_pid);
  pid_t child_01_pid;
  pid_t child_02_pid;
  pid_t running_child_01_pid;
  pid_t running_child_01_ppid;
  pid_t running_child_01_psid;
  pid_t running_child_02_pid;
  pid_t running_child_02_ppid;
  pid_t running_child_02_psid;

  // printf("Parent Program starting...\n");
  // printf("=======================================\n");
  // printf("Process ID: %d\n", parent_pid);
  // printf("Parent Process ID: %d\n", parent_ppid);
  // printf("Parent Session ID: %d\n", parent_psid);
  // printf("=======================================\n");
  printf("Forking Current Process...\n");

  child_01_pid = fork();
  if (child_01_pid == 0) {
    // inside child process
    running_child_01_pid = getpid();
    running_child_01_ppid = getppid();
    running_child_01_psid = getsid(running_child_01_pid);
    printf("\n");
    printf("First Child Process Starting...\n");
    printf("=======================================\n");
    printf("Child PID as seen from Child 1: %d\n", running_child_01_pid);
    printf("Child PPID as seen from Child 1: %d\n", running_child_01_ppid);
    printf("Child SID as seen from Child 1: %d\n", running_child_01_psid);
    printf("=======================================\n");
    setsid(); // start a new session 
    sleep(25);
    printf("First Child Process Exiting...\n");

  } else if (child_01_pid > 0) {
    // inside parent process
    printf("Parent Program starting...\n");
    printf("=======================================\n");
    printf("Process ID: %d\n", parent_pid);
    printf("Parent Process ID: %d\n", parent_ppid);
    printf("Parent Session ID: %d\n", parent_psid);
    printf("=======================================\n");
    printf("First Parent Process Terminating...\n");
    
  } else {
    perror("An error occurred when trying to fork the process\n");
    exit(EXIT_FAILURE);
  }

  printf("Forking from First Child Process...\n");
  child_02_pid = fork();
  if (child_02_pid == 0) {
    // inside child process
    running_child_02_pid = getpid();
    running_child_02_ppid = getppid();
    running_child_02_psid = getsid(running_child_01_pid);
    sleep(3);
    printf("\n");
    printf("Second Child Process Starting...\n");
    printf("=======================================\n");
    printf("Child PID as seen from Child 2: %d\n", running_child_02_pid);
    printf("Child PPID as seen from Child 2: %d\n", running_child_02_ppid);
    printf("Child SID as seen from Child 2: %d\n", running_child_02_psid);
    printf("=======================================\n");
    sleep(30); 
    printf("Child Process Exiting...\n");

  } else if (child_02_pid > 0) {
    // inside parent process
    printf("Second Parent Process Terminating...\n");
    
  } else {
    perror("An error occurred when trying to fork the process\n");
    exit(EXIT_FAILURE);
  }

  return 0;
}



