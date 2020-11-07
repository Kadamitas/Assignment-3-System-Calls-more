#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ftw.h>
#include <sys/stat.h>
// since ftw doesnt work on my machine, ill use a system call
int main(int argc, char** argv)
{
    execlp("rm", "rm", "-rf", argv[1],NULL);
    return 0;
}

