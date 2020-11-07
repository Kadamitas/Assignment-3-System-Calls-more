#include <stdio.h>
#include <unistd.h> 
#include <fcntl.h>
int main(int argc, char ** argv){
    int file = open(argv[1],O_RDONLY);
    
    printf("Size of the file: %d\n",(int)lseek(file,0,SEEK_END));
    printf("Blocks in the file: %d\n",(((int)lseek(file,0,SEEK_END)/4096) +1)*8);
    return 0;
}
