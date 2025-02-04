#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { kDate = 6, kTime = 6, kDay = 4, MaxMatches = 90, kName = 4 };

typedef struct {
  char date[kDate];
  char time[kTime];
  char day[kDay];
  char home_team[kName];
  char away_team[kName];
  int scoreHome;
  int scoreAway;
  int spectators;
} Match;

typedef struct {
  char name[kName];
  int points;
  int goalsScored;
  int goalsAgainst;
} Team;

// Funktion der bliver brugt i qsort til at sortere Teams efter points og efter goalsScored
int compareTeams(const void *a, const void *b) {
  const Team *teamA = (const Team *)a;
  const Team *teamB = (const Team *)b;

  if (teamA->points != teamB->points) {
    return teamB->points - teamA->points;
  }

  return teamB->goalsScored - teamA->goalsScored;
}

void TeamStats(Match matches[], int matchCount, Team Teams[], int teamCount) {
  for (int i = 0; i < teamCount; i++) {
    Teams[i].points = 0;
    Teams[i].goalsScored = 0;
    Teams[i].goalsAgainst = 0;
  }

  for (int i = 0; i < matchCount; i++) {
    int homeTeamIndex = -1;
    int awayTeamIndex = -1;

    for (int j = 0; j < teamCount; j++) {
      if (strcmp(matches[i].home_team, Teams[j].name) == 0) {
        homeTeamIndex = j;
      }
      if (strcmp(matches[i].away_team, Teams[j].name) == 0) {
        awayTeamIndex = j;
      }
    }

    if (homeTeamIndex != -1 && awayTeamIndex != -1) {
      Teams[homeTeamIndex].goalsScored += matches[i].scoreHome;
      Teams[homeTeamIndex].goalsAgainst += matches[i].scoreAway;

      Teams[awayTeamIndex].goalsScored += matches[i].scoreAway;
      Teams[awayTeamIndex].goalsAgainst += matches[i].scoreHome;

      // Tjekker hvem der har vundet og udeler point
      if (matches[i].scoreHome > matches[i].scoreAway) {
        Teams[homeTeamIndex].points += 3;
      } else if (matches[i].scoreHome < matches[i].scoreAway) {
        Teams[awayTeamIndex].points += 3;
      } else {
        Teams[homeTeamIndex].points += 1;
        Teams[awayTeamIndex].points += 1;
      }
    }
  }
}

void readFile(char *filename, Match matches[], int *matchCount) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error\n");
    return;
  }

  while (fscanf(file, "%s %s %s %s - %s %d - %d %d", matches[*matchCount].day,
                matches[*matchCount].date, matches[*matchCount].time,
                matches[*matchCount].home_team, matches[*matchCount].away_team,
                &matches[*matchCount].scoreHome,
                &matches[*matchCount].scoreAway,
                &matches[*matchCount].spectators) == 8) {
    (*matchCount)++;
  }
  fclose(file);
}

int main() {
  Match matches[MaxMatches];

  Team Teams[12];
  int teamCount = 12;

  strcpy(Teams[0].name, "FCM");
  strcpy(Teams[1].name, "FCN");
  strcpy(Teams[2].name, "FCK");
  strcpy(Teams[3].name, "SIF");
  strcpy(Teams[4].name, "BIF");
  strcpy(Teams[5].name, "AGF");
  strcpy(Teams[6].name, "LBK");
  strcpy(Teams[7].name, "VFF");
  strcpy(Teams[8].name, "RFC");
  strcpy(Teams[9].name, "OB");
  strcpy(Teams[10].name, "VB");
  strcpy(Teams[11].name, "HIF");

  int matchCount = 0;
  readFile("Fodboldturnering/Kampe-2023-2024.txt", matches, &matchCount);

  TeamStats(matches, matchCount, Teams, teamCount);

  // Sorter Teams efter points og goalsScored
  qsort(Teams, teamCount, sizeof(Team), compareTeams);

  for (int i = 0; i < teamCount; i++) {
    printf("%s Points: %d Goals: %d - %d\n", Teams[i].name, Teams[i].points,
           Teams[i].goalsScored, Teams[i].goalsAgainst);
  }
  return 0;
}
