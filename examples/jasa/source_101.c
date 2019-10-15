#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "klee/klee.h"

int Roll_Dice(void);
void Change_Ledcolor(void);
int led_state;
int swflg;
  
void main(void)
{
  klee_make_symbolic(&led_state, sizeof(led_state), "led_state");
  klee_make_symbolic(&swflg, sizeof(swflg), "swflg");
  Change_Ledcolor();
}

void Change_Ledcolor(void)
{
  int dice_value1, dice_value2;
  dice_value2 = Roll_Dice();

  
  if(swflg == 1){
    printf("Switch_ON\n");
    switch(led_state)  {
      case(0):
        if(dice_value2 == 1){
          led_state = 1;
        }
        else if (dice_value2 == 2){
          led_state = 2;
        }
        else{
          printf("NO_COLOR_CHANGE\n");
        }
        break;
  	
      case(1):
        if(dice_value2 == 1){
          led_state = 2;
        }
        else if (dice_value2 == 2){
          led_state = 0;
        }
        else{
          printf("NO_COLOR_CHANGE\n");
        }
        break;

      case(2):
        if(dice_value2 == 1){
          led_state = 0;
        }
        else if (dice_value2 == 2){
          led_state = 1;
        }
        else{
          printf("NO_COLOR_CHANGE\n");
        }
        break;

        default:
          printf("NO_COLOR\n");
    }
  }

}

int Roll_Dice(void)
{
  int value;
  //srand(time(NULL));
  //value = rand()%6+1;
  klee_make_symbolic(&value, sizeof(value), "value");
  return value;
}

