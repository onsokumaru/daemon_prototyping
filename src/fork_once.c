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
    sleep(5); // give parent time to do its thing and go to sleep
    printf("=======================================\n");
    printf("Child PID as seen from Child: %d\n", running_child_pid);
    printf("Child PPID as seen from Child: %d\n", running_child_ppid);
    printf("Child SID as seen from Child: %d\n", running_child_psid);
    printf("=======================================\n");
    printf("Child process exiting...\n");

  } else if (child_pid > 0) {
    // inside parent process
    printf("=======================================\n");
    printf("Child PID as seen from Parent: %d\n", child_pid);
    printf("=======================================\n");
    printf("Parent Process going to sleep...\n");
    sleep(90); // put parent process to sleep
    printf("Parent process exiting...\n");
  } else {
    perror("An error occurred when trying to fork the process\n");
    exit(EXIT_FAILURE);
  }
  return 0;
}



