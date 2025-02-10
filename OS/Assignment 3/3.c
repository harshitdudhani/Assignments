#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void grepFile(const char *filename, const char *searchTerm) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char line[1024];
    int lineNumber = 0;

    while (fgets(line, sizeof(line), file)) {
        lineNumber++;
        if (strstr(line, searchTerm)) {
            printf("Line %d: %s", lineNumber, line);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <search_term>\n", argv[0]);
        return 1;
    }

    grepFile(argv[1], argv[2]);
    return 0;
}
