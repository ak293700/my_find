#include <dirent.h>
#include <err.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    char *path = ".";
    if (argc == 2) // Fill path and check argv
        path = argv[1];
    else if (argc != 1)
        errx(1, "Too few arguments");

    DIR *dir = opendir(path);
    if (dir == NULL)
        errx(1, "%s: Not such file or directory", path);

    for (struct dirent *dst = readdir(dir); dst != NULL; dst = readdir(dir))
    {
        if (dst->d_name[0] == '.')
            continue;
        printf("%s\n", dst->d_name);
    }

    closedir(dir);

    return 0;
}
