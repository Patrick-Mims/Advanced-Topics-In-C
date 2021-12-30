#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INDEX 20

// utility function
void errorCheck(FILE *f)
{
  if (f == NULL)
  {
    perror("Error");
    exit(EXIT_FAILURE);
  }
}
typedef struct
{
  char name[20];
  int count;
  int index;
  int rate;
  int vote;
} vote_t; /* log the vote to a structure, and write it to a file */

void logVote(vote_t lv)
{
  printf("My Vote: %d\n", lv.vote);

  FILE *la = fopen("votes.txt", "w+");

  errorCheck(la);

  fscanf(stdin, "%d%d", &lv.vote, &lv.rate);

  printf("> %d\n%d\n", lv.vote, lv.rate);

  fseek(la, sizeof(vote_t), SEEK_SET);

  fwrite(&lv, (lv.rate - 1) * sizeof(lv), sizeof(1), la);

  fclose(la);
}

void readResults(FILE *r)
{
  r = fopen("results.txt", "r");

  errorCheck(r);

  printf("things are ok...");

  fclose(r);
}

void readArtist(vote_t *v, char *buff)
{
  int i = 0;
  // char buffer[INDEX];

  FILE *fpArtist = NULL;

  fpArtist = fopen("artists.txt", "r");

  if (fpArtist == NULL)
  {
    perror("Error");
    exit(EXIT_FAILURE);
  }

  while (fscanf(fpArtist, "%s", buff) == 1)
  {
    // add the name to the structure array
    strcpy(v[i].name, buff);
    //  printf("%d %s\n", i, v[i].name);
    i = i + 1;
  }

  fclose(fpArtist);
  // logVote(v);
}

/*
 * write a struct (int, int), that will hold the index and count data.
 * */

void display(char *list[], int index, int count)
{
  printf("%s - %d\n", list[index], count);

  FILE *fp = NULL;

  fp = fopen("results.txt", "a+");

  if (fp == NULL)
  {
    perror("Error");
    exit(EXIT_FAILURE);
  }

  fprintf(fp, "%s - %d\n", list[index], count);

  fclose(fp);
}

int main(void)
{
  char buffer[INDEX];

  vote_t v[6];
  /*
  char *artists[] = {
      "Diana",
      "Freida",
      "Madonna",
      "Michael",
      "Prince",
      "Stevie"};
  */

  readArtist(v, buffer);

  /*
    walk the struct here
  */

  int j = 0;
  for (; j < 6; j++)
  {
    printf("::%s\n", v[j].name);
  }

  int cnt = 0;
  int five = 0;
  int four = 0;
  int one = 0;
  int three = 0;
  int two = 0;
  int vote = 0;
  int zero = 0;

  do
  {
    printf("Which artist do you want to vote for [0-5]?\n");

    scanf("%d", &vote);

    if (vote > 5)
    {
      perror("Vote out of range");
      exit(EXIT_FAILURE);
    }

    /*
        switch (vote)
        {
        case 0:
          zero++;
          display(artists, vote, zero);
          break;
        case 1:
          one++;
          display(artists, vote, one);
          break;
        case 2:
          two++;
          display(artists, vote, two);
          break;
        case 3:
          three++;
          display(artists, vote, three);
          break;
        case 4:
          four++;
          display(artists, vote, four);
          break;
        case 5:
          five++;
          display(artists, vote, five);
          break;
        default:
          printf("Nothing Here...");
        }
        */

    cnt = cnt + 1;
  } while (cnt < 8);

  return 0;
}
