#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//12 red | 13 green | 14 blue

#define MAX_LINE 1024

int is_num(char c) {
    return c - '0' >= 0 && c - '0' <= 9;
}

//1 if possible 0 if not
int possible(char *line) {
    int num;
    int i = 8;
    while (line[i] != '\n') { //first number occurs at i = 8 always
        if (is_num(line[i]) && is_num(line[i + 1])) {
            //3-digit number is impossible
            if (is_num(line[i + 2])) {
                return 0; 
            }

            num = 10 * line[i] + line[i + 1];
            if (line[i + 3] == 'b' && num > 14) { //i + 3 is the 1st letter when we have 2 digits
                //blue
                return 0;
            }
            else if (line[i + 3] == 'g' && num > 13) {
                //greem
                return 0;
            }
            else if (line[i + 3] == 'r' && num > 12) {
                //red
                return 0;
            }
            
            i += 2; //increment by 2 to skip he second digit
        }
        printf("%c\n", line[i]);
        i++; //if not a number, go to the next character
    }
    return 1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./day2a input.txt\n");
        return 1;
    }
    
    FILE *text = fopen(argv[1], "r");
    if (!text) {
        fprintf(stderr, "fialed to open file\n");
        return 1;
    }

    char *line = malloc(MAX_LINE * sizeof(char));
    if (!line) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    int id = 1; //i dont have to find the id in the text, i can just increment it every iteration
    int sum = 0; //sum of the ids

    while (fscanf(text, "%[^\n]", line) != EOF) { //read up to a newline
        if (possible(line)) {
            sum += id;
        }
        id++;
    }

    printf("%d\n", sum);
    free(line);
    fclose(text);
    return 0;
} 