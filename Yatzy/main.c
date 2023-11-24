#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void roll_multiple_dice(int arr[], int num_of_dice) {
  /* Make a function that rolls multiple dice and store them in an int array */

  for (int i = 0; i < num_of_dice; i++) {
    arr[i] = rand() % 6 + 1;
  }
}

int full_house(int arr[], int num_of_dice) {
  int count[7] = {0};
  int sum = 0;

  for (int i = 0; i < num_of_dice; i++) {
    count[arr[i]]++;
  }

  for (int i = 6; i > 1; i--) {
    if (count[i] >= 3) {
      for (int j = 6; j > 1; j--) {
        if (count[j] >= 2 && j != i) {
          sum = 3 * i + 2 * j;
          break;
        }
      }
      break;
    }
  }
  return sum;
}

int large_straight(int arr[], int num_of_dice) {
  int count[7] = {0};
  int sum = 0;

  for (int i = 0; i < num_of_dice; i++) {
    count[arr[i]]++;
  }

  for (int i = 6; i >= 2; i--) {
    if (count[i] >= 1) {
      sum += i;
    }

    if (count[i] == 0) {
      sum = 0;
      break;
    }
  }

  return sum;
}

int small_straight(int arr[], int num_of_dice) {
  int count[7] = {0};
  int sum = 0;

  for (int i = 0; i < num_of_dice; i++) {
    count[arr[i]]++;
  }

  for (int i = 5; i >= 1; i--) {
    if (count[i] >= 1) {
      sum += i;
    }

    if (count[i] == 0) {
      sum = 0;
      break;
    }
  }

  return sum;
}

int four_kinds(int arr[], int num_of_dice) {
  int count[7] = {0};
  int sum = 0;

  for (int i = 0; i < num_of_dice; i++) {
    count[arr[i]]++;
  }

  for (int i = 6; i > 1; i--) {
    if (count[i] >= 4) {
      sum = 4 * i;
      break;
    }
  }
  return sum;
}

int three_kinds(int arr[], int num_of_dice) {
  int count[7] = {0};
  int sum = 0;

  for (int i = 0; i < num_of_dice; i++) {
    count[arr[i]]++;
  }

  for (int i = 6; i > 1; i--) {
    if (count[i] >= 3) {
      sum = 3 * i;
      break;
    }
  }
  return sum;
}

int calculate_twopairs(int arr[], int num_of_dice) {
  int pair_count[7] = {0};
  int first_pair_value = 0;
  int second_pair_value = 0;
  int sum_of_pairs = 0;

  // Tager et array og tæller hvor mange af hver værdi der er i arrayet
  for (int i = 0; i < num_of_dice; i++) {
    pair_count[arr[i]]++;
  }

  // Tjekker om der er to par i faldende rækkefølge for at tage de to største
  for (int i = 6; i >= 1; i--) {
    if (pair_count[i] >= 2) {
      if (first_pair_value == 0) {
        first_pair_value = i;
      } else if (second_pair_value == 0 && i != first_pair_value) {
        second_pair_value = i;
      }
    }
  }
  // Tjekker om der er to par og regner summen af de to par
  if (first_pair_value != 0 && second_pair_value != 0) {
    sum_of_pairs = 2 * (first_pair_value + second_pair_value);
  }

  return sum_of_pairs;
}

int calculate_onepair(int arr[], int num_of_dice) {
  int max_pair_sum = 0;

  for (int i = 1; i <= 6; i++) {
    int pair_sum = 0;
    int count_pairs = 0;

    // For loop for at finde alle par i en liste og tjekke summen af de par of
    // finde det største par
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

  if (num_of_sides == 8) {
    int max_pair_sum = calculate_twopairs(arr, num_of_dice);
    printf("To par:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", max_pair_sum);
  }

  if (num_of_sides == 9) {
    int max_pair_sum = three_kinds(arr, num_of_dice);
    printf("Tre ens:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", max_pair_sum);
  }

  if (num_of_sides == 10) {
    int max_pair_sum = four_kinds(arr, num_of_dice);
    printf("Fire ens:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", max_pair_sum);
  }

  if (num_of_sides == 11) {
    int max_pair_sum = small_straight(arr, num_of_dice);
    printf("Lille:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", max_pair_sum);
  }

  if (num_of_sides == 12) {
    int max_pair_sum = large_straight(arr, num_of_dice);
    printf("Stor:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", max_pair_sum);
  }

  if (num_of_sides == 13) {
    int max_pair_sum = full_house(arr, num_of_dice);
    printf("Fuldt hus:");
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
    exit(EXIT_FAILURE);
  }

  int dice[num_of_dice];
  int num_of_sides = 1;

  printf("Printing dies:\n");
  while (1) {
    int score = 0;

    if (num_of_sides <= 6) {
      roll_multiple_dice(dice, num_of_dice);
      scoreboard(&score, num_of_dice, num_of_sides, dice);
      print_dice(dice, num_of_dice, num_of_sides, score);
      printf("\n");
    }

    num_of_sides++;

    if (num_of_sides > 6) {
      printf("%d\n", num_of_sides);
      roll_multiple_dice(dice, num_of_dice);
      print_dice(dice, num_of_dice, num_of_sides, score);
      printf("\n");
    }

    if (num_of_sides > 14) {
      break;
    }
  }

  return 0;
}
