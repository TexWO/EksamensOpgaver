#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void roll_multiple_dice(int arr[], int num_of_dice) {
  /* Make a function that rolls multiple dice and store them in an int array */

  for (int i = 0; i < num_of_dice; i++) {
    arr[i] = rand() % 6 + 1;
  }
}

int calculate_onepair(int arr[], int num_of_dice) {
  int max_pair_sum = 0;

  for (int i = 1; i <= 6; i++) {
    int pair_sum = 0;
    int count_pairs = 0;

    // For loop for at finde alle par i en liste og tjekke summen af de par of finde det største par
    for (int j = 0; j < num_of_dice; j++) {
      if (arr[j] == i) {
        count_pairs++;
        pair_sum += arr[j];
        if (count_pairs >= 2) {
          break;
        }
      }
    }

    if (count_pairs >= 2 && pair_sum > max_pair_sum) {
      max_pair_sum = pair_sum;
    }
  }

  return max_pair_sum;
}

void print_dice(int arr[], int num_of_dice, int num_of_sides, int score) {
  /* Make a function that prints dice */
  if (num_of_sides <= 6) {
    printf("%d-ere", num_of_sides);
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", score);
  }

  if (num_of_sides == 7) {
    int max_pair_sum = calculate_onepair(arr, num_of_dice);
    printf("Et par:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", max_pair_sum);
  }
}

void scoreboard(int *score, int num_of_dice, int num_of_sides, int arr[]) {
  /* Make a function that keeps track of the score */
  int count = 0;

  for (int i = 0; i < num_of_dice; i++) {
    if (arr[i] == num_of_sides) {
      (*score) += num_of_sides;
      count++;
      if (count >= 5) {
        break;
      }
    }
  }
}

int main() {
  time_t seed;
  seed = time(NULL);
  srand(seed);

  int num_of_dice = 0;

  printf("Yatzy with how many dice? (a number under 5 terminates)");
  scanf("%d", &num_of_dice);

  if (num_of_dice < 5) {
    printf("Terminating program\n");
    return 1;
  }

  int dice[num_of_dice];
  int num_of_sides = 1;

  printf("Printing dies:\n");
  while (1) {
    int score = 0;
    roll_multiple_dice(dice, num_of_dice);
    scoreboard(&score, num_of_dice, num_of_sides, dice);
    print_dice(dice, num_of_dice, num_of_sides, score);
    printf("\n");

    num_of_sides++;

    if (num_of_sides > 6) {
      roll_multiple_dice(dice, num_of_dice);
      print_dice(dice, num_of_dice, num_of_sides, score);
      break;
    }
  }

  return 0;
}
