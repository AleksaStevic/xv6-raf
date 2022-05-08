#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fcntl.h"
#include "kernel/fs.h"

#define MAX_ROWS 64
#define BBSIZE 10

char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

void createbuf(char *nzm, char chr, int n) {
    for (int i = 0; i < n; ++i) {
        nzm[i] = chr;
    }
}

int
main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("usage: writer <filename> <size>.\n");
        exit();
        return 0;
    }
    int fd;
    int size = atoi(argv[2]);
    if((fd = open(argv[1], O_CREATE | O_WRONLY)) < 0) {
        printf("writer: cannot open %s\n", argv[1]);
        exit();
    }

    // @TODO abort if file exists

    char buf[BBSIZE];
    int ichr = 0;
    while(size > 0) {
        if (ichr > 26) break;
        int n;
        createbuf(buf, alphabet[ichr], BBSIZE);
        if ((n = write(fd, buf, BBSIZE < size ? BBSIZE : size)) < 0) {
            printf("writer: cannot write %s\n", argv[1]);
            exit();
        }
        size -= n;
        ichr++;
    }

    close(fd);
	exit();
}
