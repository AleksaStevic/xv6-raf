#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"

#define MAX_ROWS 64

int
main(int argc, char *argv[])
{
    // Matrica u kojoj treba da se smestaju nazivi obrisanih fajlova.
    char df[MAX_ROWS][DIRSIZ+1];

    int result = lsdel(argc < 2 ? "." : argv[1], (char *)df);
    if (result < 0) {
        printf("Navedena putanja nije validna.\n");
    } else if (result == 0) {
        printf("Nema obrisanih datoteka u navedenom direktorijumu.\n");
    } else {
        // @TODO: izlistaj fajlove iz df matrice
        printf("lsdel user software.\n");
    }
	exit();
}
