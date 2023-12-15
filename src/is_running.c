#include <stdio.h>
#include <sys/syslog.h>
#include <syslog.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <syslog.h>


#define PIDFILE "/tmp/test.pidfile"
#define R_BUF_MAX 128

bool is_running(const char *pidfile)
{
  openlog(NULL, LOG_PID, LOG_USER);
  int pidfile_fd;
  pidfile_fd = open(pidfile, O_RDONLY);
  if (pidfile_fd == -1) {
    syslog(LOG_INFO, "%s cannot be opened or is not present.\n", pidfile);
    return false;
  }
  
  ssize_t bytes_read;
  char read_buffer[R_BUF_MAX];
  bytes_read = read(pidfile_fd, read_buffer, (R_BUF_MAX - 1));
  if (bytes_read == -1) {
    syslog(LOG_INFO, "Error reading from file\n");
    exit(EXIT_FAILURE);
  }
  
  syslog(LOG_INFO, "Daemon is already running with PID: %s.\n", read_buffer);

  close(pidfile_fd);
  closelog();

  return true;
  
}

int main (int argc, char *argv[])
{
  
  if (is_running(PIDFILE)) {
    printf("Daemon is already running.\n");
    printf("Exiting.\n");
    exit(EXIT_FAILURE);
  }

  printf("Creating %s.\n", PIDFILE);
  printf("Starting daemon\n");
  return 0;
}






