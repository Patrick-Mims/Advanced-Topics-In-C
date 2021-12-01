#include <stdio.h>
#include <stdlib.h>

#define INDEX 20

// utility function
void errorCheck(FILE *e)
{
    if(e == NULL)
    {
      perror("Error");
      exit(EXIT_FAILURE);
    }
}

void readResults(FILE *r)
{
  r = fopen("results.txt", "r");

  errorCheck(r);

  printf("things are ok...");

  fclose(r);
}

void readArtists()
{
    FILE *fpArtist = NULL;

    fpArtist = fopen("fpArtist", "r");

    if(fpArtist == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    fclose(fpArtist);
}

void voteForArtist(FILE *a)
{

}

int main(void)
{
  char buffer[INDEX];

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

  readResults(fp);
  voteForArtist(fp);

  return 0;
}
