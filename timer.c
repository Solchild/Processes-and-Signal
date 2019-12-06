#include "timer.h"
#include <stdio.h>
#include <stdlib.h>

int alarms = 0;
void increment_alarm(){
  alarms++;
}
void sigint_handler(int signum){
  printf("Alarms occured: %d\n", alarms);
  printf("The program executed for %d seconds\n", alarms);
  exit(0);
}
