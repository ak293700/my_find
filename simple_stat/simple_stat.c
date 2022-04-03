#include <err.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        struct stat st;
        if (stat(argv[i], &st) == -1)
            return 1;

        printf("st_dev=%ld\n", st.st_dev);
        printf("st_ino=%ld\n", st.st_ino);
        printf("st_mode=%.7o\n", st.st_mode);
        printf("st_nlink=%ld\n", st.st_nlink);
        printf("st_uid=%d\n", st.st_uid);
        printf("st_gid=%d\n", st.st_gid);
        printf("st_rdev=%ld\n", st.st_rdev);
        printf("st_size=%ld\n", st.st_size);
        printf("st_atime=%ld\n", st.st_atime);
        printf("st_mtime=%ld\n", st.st_mtime);
        printf("st_ctime=%ld\n", st.st_ctime);
        printf("st_blksize=%ld\n", st.st_blksize);
        printf("st_blocks=%ld\n", st.st_blocks);
    }
    return 0;
}
