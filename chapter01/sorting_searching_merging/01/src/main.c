#include <stdio.h>
#include <stdlib.h>

#define INDEX 20

// utility function
void errorCheck(FILE *f)
{
  if(f == NULL)
  {
    perror("Error");
    exit(EXIT_FAILURE);
  }
}

typedef struct vote
{
  int vote;
} vote_t;

/* log the vote to a structure, and write it to a file */
void logVote(vote_t lv)
{
  printf("My Vote: %d\n", lv.vote);

  FILE *la = fopen("votes.txt","w+");

  errorCheck(la);

  fscanf(stdin, "%d", &lv.vote);

  printf("> %d\n", lv.vote);

  fseek(la, 9, SEEK_SET);

  fwrite(&lv, sizeof(lv), sizeof(1), la);

  fclose(la);
}

void readResults(FILE *r)
{
  r = fopen("results.txt", "r");

  errorCheck(r);

  printf("things are ok...");

  fclose(r);
}

void readArtist(vote_t v)
{
  char buffer[INDEX];

  FILE *fpArtist = NULL;

  fpArtist = fopen("artists.txt", "r");

  if(fpArtist == NULL)
  {
    perror("Error");
    exit(EXIT_FAILURE);
  }

  while(fscanf(fpArtist, "%s", buffer) == 1)
  {
    printf("%s\n", buffer);
  }

  fclose(fpArtist);

  logVote(v);
}

int main(void)
{
  char buffer[INDEX];
  vote_t vote = { 0 };
  FILE *fp = NULL;

  fp = fopen("results.txt", "r");

  if(fp == NULL)
  {
    perror("Error");
    exit(EXIT_FAILURE);
  }

  /* read the first column */
  while(fscanf(fp, "%s", buffer) == 1)
  {
    printf("%s\n", buffer);
  }

  fclose(fp);

  readArtist(vote);

  return 0;
}
