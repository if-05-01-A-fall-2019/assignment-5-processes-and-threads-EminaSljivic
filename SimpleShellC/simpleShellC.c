#include <stdio.h>
#include "list.h"
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX_LENGHT 1000


char **to_array(char *input) {
  int count = 0;
    char **temp1 = malloc(10 * sizeof(char *));
    char *temp2;

    temp2 = strtok(input, " ");
    while (temp2 != 0) {
        count++;
        temp1[count] = parsed;
        temp2 = strtok(0, " ");
    }
    temp1[count] = NULL;

    return temp1;
}

int main(int argc, char const *argv[]) {
  char str[MAX_LENGHT];
  char **temp1;
  int status;
  char* temp2;
  scanf("%s", str);
  temp2 = strtok(str, "&");
  while(temp2 != 0) {
      temp1 = to_array(temp2);
       if (fork() != 0) {
           execvp(temp1[0], temp1);
      }
      temp2 = strtok(0, "&");
      free(temp1);
  }
  waitpid(-1, &status, 0);
  return 0;
}
