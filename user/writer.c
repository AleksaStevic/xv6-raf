#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fcntl.h"
#include "kernel/fs.h"

char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

void createbuf(char *buf, char chr, int n) {
    for (int i = 0; i < n; ++i) {
        buf[i] = chr;
    }
}

int
main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("usage: writer <path> <size>.\n");
        exit();
    }

    int fd;
    int size = atoi(argv[2]);
    if((fd = open(argv[1], O_CREATE | O_WRONLY)) < 0) {
        printf("writer: cannot open %s\n", argv[1]);
        exit();
    }

    char buf[BSIZE];
    int ichr = 0;
    while(size > 0) {
        if (ichr > 26) break;
        createbuf(buf, alphabet[ichr], BSIZE);
        int n;
        if ((n = write(fd, buf, BSIZE < size ? BSIZE : size)) < 0) {
            printf("writer: cannot write %s\n", argv[1]);
            exit();
        }
        size -= n;
        ichr++;
    }

    close(fd);
	exit();
}
