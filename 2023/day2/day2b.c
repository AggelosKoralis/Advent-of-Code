#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//12 red | 13 green | 14 blue

#define MAX_LINE 256

int is_num(char c) {
    return c - '0' >= 0 && c - '0' <= 9;
}

//return the poer of a game
int power(char *line) {
    int num;
    int max_blue = 0, max_green = 0, max_red = 0;
    //init i with 8 to start after the id of the game
    int i = 8; 

    while (i < strlen(line) - 1) {

        if (is_num(line[i])) {//definitely a number

            if (is_num(line[i + 1])) { //2 digit number
                //3-digit number is impossible
                if (is_num(line[i + 2])) {
                    exit(1);
                }

                num = 10 * (line[i] - '0') + (line[i + 1] - '0');

                if (line[i + 3] == 'b') { //i + 3 is the 1st letter when we have 2 digits
                    //blue
                    if (max_blue < num) max_blue = num;
                }
                else if (line[i + 3] == 'g') {
                    //green
                    if (max_green < num) max_green = num;
                }
                else if (line[i + 3] == 'r') {
                    //red
                    if (max_red < num) max_red = num;
                }
                
                i += 2; //increment by 2 to skip he second digit
            }
            else { //1 digit number
                num = line[i] - '0';

                if (line[i + 2] == 'b') { //i + 2 is the 1st letter when we have 1 digit
                    //blue
                    if (max_blue < num) max_blue = num;
                }
                else if (line[i + 2] == 'g') {
                    //green
                    if (max_green < num) max_green = num;
                }
                else if (line[i + 2] == 'r') {
                    //red
                    if (max_red < num) max_red = num;
                }
            }
        }
        i++; //if not a number go to the next character
    }
    int power = max_blue * max_green * max_red;
    return power;
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


    int sum = 0; //sum of the powers

    while (fscanf(text, "%[^\n]\n", line) != EOF) { //read up to a newline
        sum += power(line);
    }

    printf("%d\n", sum);
    free(line);
    fclose(text);
    return 0;
} 