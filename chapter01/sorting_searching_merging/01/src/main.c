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

void insertionSort(int *list[], int lo, int hi)
{
}

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
    /* populate the structure */
    /* add the name to the structure array */
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

void display(char *list, int index, int count)
{
  printf("%s - %d\n", list, count);

  FILE *fp = NULL;

  fp = fopen("results.txt", "a+");

  if (fp == NULL)
  {
    perror("Error");
    exit(EXIT_FAILURE);
  }

  fprintf(fp, "%s - %d\n", list, count);

  fclose(fp);
}

int main(void)
{
  if (remove("results.txt"))
  {
    printf("\n\tSuccess: results.txt removed!\n");
    return 0;
  }

  char buffer[INDEX];

  // TODO: Try to get rid of these...struct?
  int cnt = 0;
  static int five = 0;
  static int four = 0;
  static int j;
  static int one = 0;
  static int three = 0;
  static int two = 0;
  static int vote = 0;
  static int zero = 0;

  vote_t v[6];

  /* populate vote_t v */
  readArtist(v, buffer);

  for (j = 0; j < 6; j++)
  {
    printf("%d. %s\n", j, v[j].name);
  }

  do
  {
    printf("Which artist do you want to vote for [0-5]?\n");

    scanf("%d", &vote);

    if (vote > 5)
    {
      perror("Vote out of range");
      exit(EXIT_FAILURE);
    }

    // TODO: pass the structure to the display function

    switch (vote)
    {
    case 0:
      zero = zero + 1;
      display(v[0].name, vote, zero);
      break;
    case 1:
      one = one + 1;
      display(v[1].name, vote, one);
      break;
    case 2:
      two = two + 1;
      display(v[2].name, vote, two);
      break;
    case 3:
      three = three + 1;
      display(v[3].name, vote, three);
      break;
    case 4:
      four = four + 1;
      display(v[4].name, vote, four);
      break;
    case 5:
      five = five + 1;
      display(v[5].name, vote, five);
      break;
    default:
      printf("Nothing Here...");
    }

    cnt = cnt + 1;

  } while (cnt < 8);

  return 0;
}
