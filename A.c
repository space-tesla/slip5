
Q.1) Read the current directory and display the name of the files, number of files in the current directory

#include <stdio.h>
#include <dirent.h>

int main() {
    struct dirent *entry;
    DIR *dp = opendir(".");

    if (dp == NULL) {
        perror("opendir");
        return 1;
    }

    int file_count = 0;
    printf("Files in the current directory:\n");
    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) {
            printf("%s\n", entry->d_name);
            file_count++;
        }
    }

    closedir(dp);
    printf("Total number of files: %d\n", file_count);
    return 0;
}






How To Run
--->  cc slip.c
---> ./a.out
--->  gcc slip.c -o slip
---> ./slip slip.c

Output:

Files in the current directory:
file1.txt
file2.c
myprogram.c
Total number of files: 3