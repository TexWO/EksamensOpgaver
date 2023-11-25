#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int ones;
  int twos;
  int threes;
  int fours;
  int fives;
  int sixes;
  int one_pair;
  int two_pairs;
  int three_of_a_kind;
  int four_of_a_kind;
  int small_straight;
  int large_straight;
  int full_house;
  int chance;
  int yatzy;
} Scoreboard;

void roll_multiple_dice(int arr[], int num_of_dice) {
  /* Make a function that rolls multiple dice and store them in an int array */

  for (int i = 0; i < num_of_dice; i++) {
    arr[i] = rand() % 6 + 1;
  }
}

int yatzy(int arr[], int num_of_dice) {
  int count[7] = {0};
  int sum = 0;

  for (int i = 0; i < num_of_dice; i++) {
    count[arr[i]]++;
  }

  for (int i = 6; i > 1; i--) {
    if (count[i] >= 5) {
      sum = 50;
      break;
    }
  }
  return sum;
}

int chance(int arr[], int num_of_dice) {
  int count[7] = {0};
  int sum = 0;
  int dice_count = 5;

  for (int i = 0; i < num_of_dice; i++) {
    count[arr[i]]++;
  }

  for (int i = 6; i > 1; i--) {
    while (count[i] > 0) {
      if (dice_count <= 0) {
        break;
      }
      sum += i;
      count[i]--;
      dice_count--;
    }
  }
  return sum;
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

void print_dice(int arr[], int num_of_dice, int num_of_sides, int score,
                Scoreboard *scores) {
  /* Make a function that prints dice */
  int count = 0;
  if (num_of_sides <= 6) {
    for (int i = 0; i < num_of_dice; i++) {
      if (arr[i] == num_of_sides) {
        if (num_of_sides == 1) {
          scores->ones += num_of_sides;
        } else if (num_of_sides == 2) {
          scores->twos += num_of_sides;
        } else if (num_of_sides == 3) {
          scores->threes += num_of_sides;
        } else if (num_of_sides == 4) {
          scores->fours += num_of_sides;
        } else if (num_of_sides == 5) {
          scores->fives += num_of_sides;
        } else if (num_of_sides == 6) {
          scores->sixes += num_of_sides;
        }
        score += num_of_sides;
        count++;
        if (count >= 5) {
          break;
        }
      }
    }
    printf("%d-ere", num_of_sides);
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", score);
  }
  if (num_of_sides == 7) {
    score = calculate_onepair(arr, num_of_dice);
    printf("Et par:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", score);
    scores->one_pair = score;
  }
  if (num_of_sides == 8) {
    score = calculate_twopairs(arr, num_of_dice);
    printf("To par:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", score);
    scores->two_pairs = score;
  }
  if (num_of_sides == 9) {
    score = three_kinds(arr, num_of_dice);
    printf("Tre ens:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", score);
    scores->three_of_a_kind = score;
  }
  if (num_of_sides == 10) {
    score = four_kinds(arr, num_of_dice);
    printf("Fire ens:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", score);
    scores->four_of_a_kind = score;
  }
  if (num_of_sides == 11) {
    score = small_straight(arr, num_of_dice);
    printf("Lille:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", score);
    scores->small_straight = score;
  }
  if (num_of_sides == 12) {
    score = large_straight(arr, num_of_dice);
    printf("Stor:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", score);
    scores->large_straight = score;
  }
  if (num_of_sides == 13) {
    score = full_house(arr, num_of_dice);
    printf("Fuldt hus:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", score);
    scores->full_house = score;
  }
  if (num_of_sides == 14) {
    score = chance(arr, num_of_dice);
    printf("Chance:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", score);
    scores->chance = score;
  }

  if (num_of_sides == 15) {
    score = yatzy(arr, num_of_dice);
    printf("Yatzy:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", score);
    scores->yatzy = score;
  }
}
void scoreboard(Scoreboard *scores) {
  /* Make a function that keeps track of the score */
  printf("Scoreboard:\n");
  printf("1-ere: %d\n", scores->ones);
  printf("2-ere: %d\n", scores->twos);
  printf("3-ere: %d\n", scores->threes);
  printf("4-ere: %d\n", scores->fours);
  printf("5-ere: %d\n", scores->fives);
  printf("6-ere: %d\n", scores->sixes);
  printf("\n");
  printf("Et par: %d\n", scores->one_pair);
  printf("To par: %d\n", scores->two_pairs);
  printf("Tre ens: %d\n", scores->three_of_a_kind);
  printf("Fire ens: %d\n", scores->four_of_a_kind);
  printf("Lille: %d\n", scores->small_straight);
  printf("Stor: %d\n", scores->large_straight);
  printf("Fuldt hus: %d\n", scores->full_house);
  printf("Chance: %d\n", scores->chance);
  printf("Yatzy: %d\n", scores->yatzy);
  printf("\n");
}
int totalScore(Scoreboard *scores, int total_score) {
  total_score += scores->ones;
  total_score += scores->twos;
  total_score += scores->threes;
  total_score += scores->fours;
  total_score += scores->fives;
  total_score += scores->sixes;
  total_score += scores->one_pair;
  total_score += scores->two_pairs;
  total_score += scores->three_of_a_kind;
  total_score += scores->four_of_a_kind;
  total_score += scores->small_straight;
  total_score += scores->large_straight;
  total_score += scores->full_house;
  total_score += scores->chance;
  total_score += scores->yatzy;
  return total_score;
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
  Scoreboard scores = {0};
  int BONUS = 50;

  printf("Printing dies:\n");
  while (1) {
    int score = 0;

    if (num_of_sides <= 6) {
      roll_multiple_dice(dice, num_of_dice);
      print_dice(dice, num_of_dice, num_of_sides, score, &scores);

      if (totalScore(&scores, 0) >= 63 &&num_of_sides == 6) {
        printf("Bonus: %d\n", BONUS);
        scores.sixes += BONUS;
        printf("\n");
      } else if (num_of_sides == 6) {
        printf("Bonus: 0\n");
        printf("\n");
      }
    }

    num_of_sides++;

    if (num_of_sides > 6 && num_of_sides <= 15) {
      roll_multiple_dice(dice, num_of_dice);
      print_dice(dice, num_of_dice, num_of_sides, score, &scores);
    }

    if (num_of_sides > 15) {
      printf("\n");
      scoreboard(&scores);
      printf("Total score: %d\n", totalScore(&scores, 0));
      break;
    }
  }
  return 0;
}