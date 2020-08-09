#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE 1024


int main(int argc, char ** argv)
{
    int fd_from, fd_to;

    if(argc != 3)
    {
        printf("Uage:%s <src> <dst>",argv[0]);
        exit(1);
    }

    fd_from = open(argv[1],O_RDONLY);
    fd_to = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0644);
    char buf[SIZE];
    char *p;
    int nread, nwrite;

    while(1)
    {
        nread = read(fd_from,buf,SIZE);
        if(nread == 0)
        {
            break;
        }
        write(fd_to,buf,nread);

    }

    close(fd_from);
    close(fd_to);

    return 0;
}

