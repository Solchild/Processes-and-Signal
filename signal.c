/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int hold = 0;
int time = 0;

void handler1(int signum)
{ //signal handler
  hold = 1;
}

void handler2(int signum){
  printf("Program ran for %d seconds.\n", time);
  exit(1);
}

int main(int argc, char * argv[])
{
  signal(SIGINT, handler2);
  while(1){
    signal(SIGALRM,handler); //register handler to handle SIGALRM
    alarm(1); //Schedule a SIGALRM for 1 second
    while(!hold);
    time++
    hold = 0;
  }
  return 0; //never reached
}
