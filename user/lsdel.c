#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"

int
main(int argc, char *argv[])
{
    // Matrica u kojoj treba da se smestaju nazivi obrisanih fajlova.
    char df[DIRFNUM][DIRSIZ+1] = {
        "file1",
        "file2",
        "file3",
    };

    //int fnum = lsdel(argc < 2 ? "." : argv[1], (char *)df);
    int fnum = 3;
    if (fnum < 0) {
        printf("Navedena putanja nije validna.\n");
    } else if (fnum == 0) {
        printf("Nema obrisanih datoteka u navedenom direktorijumu.\n");
    } else {
        for (int i = 0; i < fnum; ++i) {
            printf("%s\n", df[i]);
        }
    }
	exit();
}
