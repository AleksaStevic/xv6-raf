#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"

int
main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Nije naveden parametar na komandnoj liniji.\n");
        exit();
        return 0;
    }

    switch(rec(argv[1])) {
        case 0:  printf("Uspesan oporavak.\n"); break;
        case -1: printf("Roditeljski direktorijum za navedenu datoteku nije validan.\n"); break;
        case -2: printf("Ne postoji obrisana datoteka sa navedenim nazivom.\n"); break;
        case -3: printf("Inode datoteke je iskorišćen za nešto drugo.\n"); break;
        case -4: printf("Neki blok datoteke je iskorišćen za nešto drugo.\n"); break;
        default: printf("Nepoznata greska.\n");
    }
	exit();
}
