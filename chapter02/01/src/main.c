#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *fp = NULL;
  char buffer[100];

  fp = fopen("results.txt", "r");

  if(fp == NULL)
  {
    perror("Error");
    exit(EXIT_FAILURE);
  }

  while(fscanf(fp,"%*s") == 1)
  {
    printf("%s\n", buffer);
  }

  fclose(fp);

  return 0;
}
