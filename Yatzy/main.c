#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void roll_multiple_dice() {
  /* Make a function that rolls multiple dice and store them in an int array */

  time_t seed;
  seed = time(NULL);
  srand(seed);
  int num_of_dice;

  printf("How many dice do you want to roll?\n");
  scanf("%d", &num_of_dice);

  int arr[num_of_dice];

  for (int i = 0; i < num_of_dice; i++) {
    arr[i] = rand() % 6 + 1;
  }

  printf("You rolled: ");
  for (int i = 0; i < num_of_dice; i++) {
    printf("%d ", arr[i]);
  }
}


int scoreboard() {
  /* Make a function that keeps track of the score */
}



int main() {
  roll_multiple_dice();
  return 0;
}
