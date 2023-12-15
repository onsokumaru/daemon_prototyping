#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int main (int argc, char *argv[])
{
  pid_t parent_pid = getpid();
  pid_t parent_ppid = getppid();
  pid_t parent_psid = getsid(parent_pid);
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

  switch (fork()) {   // become background process and disconnect from terminal
    case -1:
      perror("Error forking process\n");
      exit(EXIT_FAILURE);
    case 0: 
      break;
    default:
      exit(EXIT_SUCCESS);
  }

  // inside child process
  // create a new session
  if (setsid() == -1) {
    perror("Error creating new session\n");
    exit(EXIT_FAILURE);
  }

  switch (fork()) {   // become leader of a new session
    case -1:
      perror("Error forking process\n");
      exit(EXIT_FAILURE);
    case 0: 
      break;
    default:
      exit(EXIT_SUCCESS);
  }
  // inside child process
  running_child_pid = getpid();
  running_child_ppid = getppid();
  running_child_psid = getsid(running_child_pid);
  printf("\n");
  printf("Remaining Child Process...\n");
  printf("=======================================\n");
  printf("PID as seen from Child: %d\n", running_child_pid);
  printf("PPID as seen from Child: %d\n", running_child_ppid);
  printf("SID as seen from Child: %d\n", running_child_psid);
  printf("=======================================\n");
  sleep(25);
  printf("Child Process Exiting...\n");


  return 0;
}

