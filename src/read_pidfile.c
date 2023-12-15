#include <stdio.h>
#include <syslog.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PIDFILE "/tmp/test.pidfile"
#define R_BUF_MAX 128

int main (int argc, char *argv[])
{
  int pidfile_fd;
  pidfile_fd = open(PIDFILE, O_RDONLY);
  if (pidfile_fd == -1) {
    perror("Error opening file or file not present.\n");
    exit(EXIT_FAILURE);
  }

  ssize_t bytes_read;
  char read_buffer[R_BUF_MAX];
  bytes_read = read(pidfile_fd, read_buffer, (R_BUF_MAX - 1));
  if (bytes_read == -1) {
    perror("Error reading from file.\n");
    exit(EXIT_FAILURE);
  }

  printf("PID of running daemon process is: %s", read_buffer);
  
  return 0;
}






