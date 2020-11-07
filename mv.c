#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    struct stat path;
    char str[10000];
    stat(argv[2], &path);
    int isAFolder = S_ISDIR(path.st_mode);

    if(isAFolder == 0){
        rename(argv[1],argv[2]);
    }else{
        strcpy(str,argv[2]);
        strcat(str,"/");
        strcat(str,argv[1]);
        rename(argv[1],str);
    }

    return 0;
}
