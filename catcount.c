#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h> 
#include <string.h>
#include <time.h>
#include <unistd.h> 

int main(int argc, char** argv) {
    pid_t  pid;
    printf("Aron Mlodkowski, siu854477934\n");
    time_t t;
    time(&t);
    printf("%s", ctime(&t));

	pid = fork();
	if (pid < 0) { 
		fprintf(stderr, "Fork Failed\n");
		exit(-1);
	}
	else if (pid == 0) { 
        printf("\ncat:\n");fflush(stdout);
		execlp("cat","cat", argv[1], NULL);
	}
	else { 
		wait(NULL);
                pid = fork();
                if (pid < 0) { 
                    fprintf(stderr, "Fork Failed\n");
                    exit(-1);
                }
                else if (pid == 0) { 
                    printf("\n\nwc:\n");fflush(stdout);
                    execlp("wc","wc", argv[1], NULL);
                }
                else { 
                    wait(NULL);
                }
		exit(0);
    }
}       