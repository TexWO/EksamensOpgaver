#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void roll_multiple_dice(int arr[], int num_of_dice) {
  /* Make a function that rolls multiple dice and store them in an int array */

  for (int i = 0; i < num_of_dice; i++) {
    arr[i] = rand() % 6 + 1;
  }
}


void print_dice(int arr[], int num_of_dice, int num_of_sides) {
  /* Make a function that prints dice */
  printf("%d-ere", num_of_sides);
  for (int i = 0; i < num_of_dice; i++) {
    printf(" %d", arr[i]);
  }
  printf("\n");
}

int scoreboard() {
  /* Make a function that keeps track of the score */
}



int main() {
  time_t seed;
  seed = time(NULL);
  srand(seed);

  int num_of_dice = 0;

  printf("Yatzy with how many dice? (a number under 5 terminates)");
  scanf("%d", &num_of_dice);

  if(num_of_dice < 5) {
    printf("Terminating program\n");
    return 1;
  }

  int dice[num_of_dice];
  int num_of_sides = 1;

  printf("Printing dies:\n");
  while(1) {
    roll_multiple_dice(dice, num_of_dice);
    print_dice(dice, num_of_dice, num_of_sides);
    printf("\n");

    num_of_sides++;

    if(num_of_sides > 6) {
      break;
    }
  }

  return 0;
}
