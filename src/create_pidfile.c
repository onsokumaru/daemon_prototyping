#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>




#define PIDFILE "/tmp/test.pidfile"
#define BUFFER 100

int create_pid_file() 
{
  int pidfile_fd = open(PIDFILE, O_CREAT | O_RDWR | O_EXCL, 0644);
  if (pidfile_fd == -1) {
    perror("Error opening file for writing.\n");
    return -1;
  }

  char pid_str[BUFFER];
  snprintf(pid_str, sizeof(pid_str), "%d\n", getpid());
  write(pidfile_fd, pid_str, strlen(pid_str));
  close(pidfile_fd);

  return 0;

}

int main (int argc, char *argv[])
{
  
  if (create_pid_file() == -1) {
    perror("Error creating pidfile.\n");
    exit(EXIT_FAILURE);
  }
  return 0;
}




