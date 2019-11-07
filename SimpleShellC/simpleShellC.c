#include <stdio.h>
#include "list.h"
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX_LENGHT 1000


char **to_array(char *input) {
    char **command = malloc(10 * sizeof(char *));
    char *parsed;
    int i = 0;

    parsed = strtok(input, " ");
    while (parsed != 0) {
        command[i] = parsed;
        parsed = strtok(0, " ");
        i++;
    }

    command[i] = NULL;
    return command;
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
