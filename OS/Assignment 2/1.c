#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
// #include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

int main() {
    pid_t pid;
    struct stat fileStat;
    DIR *dir;
    struct dirent *entry;

    printf("Parent PID: %d\n", getpid());

    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        printf("Child PID: %d\n", getpid());
        execl("/bin/ls", "ls", "-l", NULL);
        perror("execl failed");
        exit(EXIT_FAILURE);
    } else {
        printf("Waiting for child process to finish...\n");
        wait(NULL);

        if (stat("example.txt", &fileStat) == 0) {
            printf("File: example.txt\n");
            printf("Size: %ld bytes\n", fileStat.st_size);
            printf("Permissions: %o\n", fileStat.st_mode & 0777);
        } else {
            perror("stat failed");
        }

        dir = opendir(".");
        if (dir) {
            printf("Directory contents:\n");
            while ((entry = readdir(dir)) != NULL) {
                printf("  %s\n", entry->d_name);
            }
            closedir(dir);
        } else {
            perror("opendir failed");
        }

        printf("Parent process exiting.\n");
    }

    return 0;
}