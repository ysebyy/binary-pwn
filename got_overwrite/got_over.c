#include <stdio.h>
#include <fcntl.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <unistd.h>


int main(int argc, char **argv) {
    char buffer[280];
    char quit = 'n';
    
   do {
        memset(buffer, 0, sizeof(buffer));
        //fgets(buffer, sizeof(buffer), stdin);
        scanf("%s", buffer);

        printf(buffer);
        puts("");
        
        printf("Would you like to create another greeting? (y/N): ");
        scanf(" %c", &quit);

  } while (quit == 'y' || quit == 'Y');
      return 0;
}
