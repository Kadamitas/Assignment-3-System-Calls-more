#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h> 
#include <string.h>
#include <time.h>
#include <unistd.h> 

int main() {
    pid_t  pid;
    char str[32767]; //max size of an argument
    char quit[100];
    printf("Aron Mlodkowski, siu854477934\n");
    time_t t;
    time(&t);
    printf("%s", ctime(&t));
    forking:
    printf("\nGive me a command or type quit \n");
    scanf("%s", str);
	pid = fork();
	if (pid < 0) { 
		fprintf(stderr, "Fork Failed\n");
		exit(-1);
	}
	else if (pid == 0) { 
    //I would allow more than just the command, but that needs execvp and im required to use
    //execlp
		execlp(str,str, NULL);
	}
	else { 
		wait(NULL);
		//printf ("Child Complete \n");
        if(strcmp(str,"quit") != 0){
            printf("\nHere we go again! \n");
            goto forking;
        }
		exit(0); 	       
        }
    
   }
