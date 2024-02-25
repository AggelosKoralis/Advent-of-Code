#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//cmd line file input

#define MAX_LINE 256

int find_words(char *line, int starting_idx) {
    //the number itself and how many pieces(letters) we have to collect to complete it
    int one3 = 0, two3 = 0, three5 = 0, four4 = 0, five4 = 0, six3 = 0, seven5 = 0, eight5 = 0, nine4 = 0;
    
    int i = starting_idx;
    //while i dont bump into a number loop
    while (!(line[i] - '0' >= 0 && line[i] - '0' <= 9)) {

        if (line[i] == 'o') {
            one3++;
            if (line[++i] == 'n') {
                one3++;
                if (line[++i] == 'e') {
                    one3++;
                }
            }
        }
        else if (line[i] == 't') {

        }
        else if (line[i] == 'f') {

        }
        else if (line[i] == 's') {

        }
        else if (line[i] == 'e') {

        }
        else if (line[i] == 'n') {

        }

    }
}

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
        else if (isalpha(line[i])) {
            find_words(line, i);
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
    fclose(text);
    return 0;
}