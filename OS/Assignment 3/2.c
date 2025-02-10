#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void listFiles(const char *path) {
    struct dirent *entry;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        perror("Error opening directory");
        exit(1);
    }

    printf("Files in directory '%s':\n", path);
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    const char *path = (argc == 2) ? argv[1] : ".";
    listFiles(path);
    return 0;
}   