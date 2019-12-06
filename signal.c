/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "timer.h"

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  increment_alarm();
}

int main(int argc, char * argv[])
{
  signal(SIGINT,sigint_handler); //register handler to handle SIGALRM
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  while(1){
    alarm(1); //Schedule a SIGALRM for 1 second
    sleep(1);
    printf("Turing was right!\n");
    
  }
  return 0; //never reached
}
