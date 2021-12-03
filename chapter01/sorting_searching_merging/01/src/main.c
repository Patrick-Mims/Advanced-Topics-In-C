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

void logVote(vote_t lv)
{
  printf("My Vote: %d\n", lv.vote);

  FILE *la = NULL;

  la = fopen("votes.txt","a+");

  fscanf(stdin, "%d", &lv.vote);

  printf(">>%d\n", lv.vote);

  /*
  int buffer[9], i = 0, v = 5;

  while((v != 0) && (v <= 10))
  {
    printf("Vote for your favorite Artist %d: ", i);
    scanf("%d", &v);
    printf("Thank you for your vote\n");

    fwrite(&vote, sizeof(vote_t), 1, la);

    i += 1;
  }
  */

  errorCheck(la);

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

void voteForArtist(FILE *a)
{

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

  //readResults(fp);
  //voteForArtist(fp);
  readArtist(vote);

  return 0;
}
