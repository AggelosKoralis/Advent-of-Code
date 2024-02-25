#include <stdio.h>
#include <stdlib.h>

//cmd line file input

#define MAX_LINE 256

int find_nums(char *line) {
    int first, last;
    int first_found = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] - '0' >= 0 && line[i] - '0' <= 9) {
            if (!first_found) {
                first_found = 1;
                first = line[i] - '0';
                last = line[i] - '0';
            }
            else {
                last = line[i] - '0';
            }
        }
    }

    return 10 * first + last;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "wrong input format\n");
        return 1;
    }

    FILE *text = fopen(argv[1], "r");
    if (!text) {
        fprintf(stderr, "failed to open file\n");
        return 1;
    }

    char *line = malloc(MAX_LINE * sizeof(char));
    if (!line) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    int sum = 0;
    while (fscanf(text, "%[^\n]\n", line) != EOF) { //read up to a newline
        sum += find_nums(line);
    }
    printf("%d\n", sum);
    free(line);
    fclose(text);
    return 0;
}