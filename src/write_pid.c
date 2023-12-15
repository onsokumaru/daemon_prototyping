#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define PIDFILE "/tmp/demo.pidfile"

int main (int argc, char *argv[])
{
  
  FILE *fp;
  fp = fopen(PIDFILE, "w+");
  if (fp == NULL) {
    perror("Error opening file for writing.\n");
    exit(EXIT_FAILURE);
  }

  fprintf(fp, "%d\n", getpid());
  return 0;
}


