#include <stdio.h>

enum { kDate = 6, kTime = 6, kDay = 4, kHomeTeam = 4, kAwayTeam = 4, MaxMatches = 90 };

typedef struct {
  char date[kDate];
  char time[kTime];
  char day[kDay];
  char home_team[kHomeTeam];
  char away_team[kAwayTeam];
  int scoreHome;
  int scoreAway;
  int spectators;
} Match;

int main() {
  FILE *file = fopen("Fodboldturnering/kampe-2023-2024.txt", "r");
  if (file == NULL) {
    perror("Error\n");
    return 1;
  }

  Match matches[MaxMatches];
  int matchCount = 0;

  while (fscanf(file, "%s %s %s %s - %s %d - %d %d",
                matches[matchCount].day,
                matches[matchCount].date,
                matches[matchCount].time,
                matches[matchCount].home_team,
                matches[matchCount].away_team,
                &matches[matchCount].scoreHome,
                &matches[matchCount].scoreAway,
                &matches[matchCount].spectators) == 8) {
    matchCount++;
  }


  for (int i = 0; i < matchCount; i++) {
    printf("%s %s %s %s - %s %d - %d %d\n",
           matches[i].day,
           matches[i].date,
           matches[i].time,
           matches[i].home_team,
           matches[i].away_team,
           matches[i].scoreHome,
           matches[i].scoreAway,
           matches[i].spectators);
  }

  fclose(file);
  return 0;
}