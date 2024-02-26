#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//cmd line file input

#define MAX_LINE 256

int one(char *line, int length, int i) {
    return (length >= i + 2) && (line[i] == 'o' && line[i + 1] == 'n' && line[i + 2] == 'e');
}

int two(char *line, int length, int i) {
    return (length >= i + 2) && (line[i + 1] == 'w' && line[i + 2] == 'o');
}

int three(char *line, int length, int i) {
    return (length >= i + 4) && (line[i + 1] == 'h' && line[i + 2] == 'r' && line[i + 3] == 'e' && line[i + 4] == 'e');
}

int four(char *line, int length, int i) {
    return (length >= i + 3) && (line[i + 1] == 'o' && line[i + 2] == 'u' && line[i + 3] == 'r');
}

int five(char *line, int length, int i) {
    return (length >= i + 3) && (line[i + 1] == 'i' && line[i + 2] == 'v' && line[i + 3] == 'e');
}

int six(char *line, int length, int i) {
    return (length >= i + 2) && (line[i + 1] == 'i' && line[i + 2] == 'x');
}

int seven(char *line, int length, int i) {
    return (length >= i + 4) && (line[i + 1] == 'e' && line[i + 2] == 'v' && line[i + 3] == 'e' && line[i + 4] == 'n');
}

int eight(char *line, int length, int i) {
    return (length >= i + 4) && (line[i] == 'e' && line[i + 1] == 'i' && line[i + 2] == 'g' && line[i + 3] == 'h' && line[i + 4] == 't');
}

int nine(char *line, int length, int i) {
    return (length >= i + 3) && (line[i] == 'n' && line[i + 1] == 'i' && line[i + 2] == 'n' && line[i + 3] == 'e');
}

//the starting index will help figure out which to put first or last
int find_words(char *line, int starting_idx) {

    int length = strlen(line);
    int i = starting_idx;
    //while i dont bump into a number loop
    //while (!(line[i] - '0' >= 0 && line[i] - '0' <= 9)) { //no loop? the loop is in the caller func

        if (one(line, length, i)) {
            //one
        }
        else if (line[i] == 't') {
            if (two(line, length, i)) {
                //two
            }
            else if (three(line, length, i)) {
                //three
            }
        }
        else if (line[i] == 'f') {
            if (four(line, length, i)) {
                //four
            }
            else if (five(line, length, i)) {
                //five
            }
        }
        else if (line[i] == 's') {
            if (six(line, length, i)) {
                //six
            }
            else if (seven(line, length, i)) {
                //seven
            }
        }  
        else if (eight(line, length, i)) {
            //eight
        }
        else if (nine(line, length, i)) {
            //nine
        }

    //}
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