// Compiled with `gcc -g -no-pie greetings_2.c -o greetings_2`
#include <fcntl.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUF_LEN 500

void setup() {
  setbuf(stdout, NULL);
  setbuf(stdin, NULL);
  setbuf(stderr, NULL);
}

int main(int argc, char **argv) {

  // vars
  char name[20];
  char greeting[280];
  char quit = 'n';

  // Disable buffering
  setup();

  do {

    // Zero buffers in case of looping
    memset(name, 0, sizeof(name));
    memset(greeting, 0, sizeof(greeting));

    puts("========================");
    puts("*** Greetings! ***");
    puts("========================");

    puts("");
    puts("Welcome! Enter your name and a greeting.");

    printf("Name: ");
    scanf(" %19s", name);

    printf("Greeting: ");
    scanf(" %s", greeting);

    printf("Generating your custom greeting....\n");
    usleep(500);

    puts("");
    puts("Your custom greeting:");
    puts("========================");

    printf("Why hello there %s,", name);
    printf(greeting);
    puts("");
    printf("========================\n");

    puts("");
    printf("Would you like to create another greeting? (y/N): ");
    scanf(" %c", &quit);

  } while (quit == 'y' || quit == 'Y');

  return 0;
}
