#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int hold = 0;
int time = 0;

void handler1(){
  hold = 1;
}
void handler2(int signum){
  printf("Ran for %d seconds", time);
  exit(1);
}

int main(int argc, char * argv[]){
  signal(SIGINT, handler2);
  while(1){
    signal(SIGINTALRM, handler1);
    alarm(1);
    while(!hold);
    time++;
    hold = 0;
  }
  
  return 0;
}
