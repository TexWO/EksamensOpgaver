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

// Funktion der ruller flere terninger og gemmer dem i et array
void roll_multiple_dice(int arr[], int num_of_dice) {

  for (int i = 0; i < num_of_dice; i++) {
    arr[i] = rand() % 6 + 1;
  }
}

// Funktion der tæller score for yatzy
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

// Funktion der tæller score for chance
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

// Funktion der tæller score for fuldt hus
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

// Funktion der tæller score for stor straight
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

// Funktion der tæller score for lille straight
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

// Funktion der tæller score for fire ens
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

// Funktion der tæller score for tre ens
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

// Funktion der tæller score for to par
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

// Funktion der tæller score for et par
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

// Funktion der printer terningerne og giver structs scores en score for hver terning
void print_dice(int arr[], int num_of_dice, int num_of_sides, int score,
                Scoreboard *scores) {
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
    scores->one_pair = calculate_onepair(arr, num_of_dice);
    printf("Et par:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", scores->one_pair);
  }
  if (num_of_sides == 8) {
    scores->two_pairs = calculate_twopairs(arr, num_of_dice);
    printf("To par:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", scores->two_pairs);
  }
  if (num_of_sides == 9) {
    scores->three_of_a_kind = three_kinds(arr, num_of_dice);
    printf("Tre ens:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", scores->three_of_a_kind);
  }
  if (num_of_sides == 10) {
    scores->four_of_a_kind = four_kinds(arr, num_of_dice);
    printf("Fire ens:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", scores->four_of_a_kind);
  }
  if (num_of_sides == 11) {
    scores->small_straight = small_straight(arr, num_of_dice);
    printf("Lille:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", scores->small_straight);
  }
  if (num_of_sides == 12) {
    scores->large_straight = large_straight(arr, num_of_dice);
    printf("Stor:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", scores->large_straight);
  }
  if (num_of_sides == 13) {
    scores->full_house = full_house(arr, num_of_dice);
    printf("Fuldt hus:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", scores->full_house);
  }
  if (num_of_sides == 14) {
    scores->chance = chance(arr, num_of_dice);
    printf("Chance:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", scores->chance);
  }

  if (num_of_sides == 15) {
    scores->yatzy = yatzy(arr, num_of_dice);
    printf("Yatzy:");
    for (int i = 0; i < num_of_dice; i++) {
      printf(" %d", arr[i]);
    }
    printf(" -- %d\n", scores->yatzy);
  }
}
// Funktion der printer scoreboard
void scoreboard(Scoreboard *scores) {
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
// Funktion der tæller total score
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
  char play_again;

  printf("Yatzy with how many dice? (a number under 5 terminates)");
  scanf("%d", &num_of_dice);

  if (num_of_dice < 5) {
    printf("Terminating program\n");
    return 1;
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
      printf("\n");
      break;
    }
  }
  printf("Wanna play again? (y/n)\n");
  scanf(" %c", &play_again);

  if (play_again == 'y') {
    main();
  } else if (play_again != 'y'){
    printf("Terminating program\n");
    return 0;
  }
}