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

//return the number that it found adnd -1 if it didnt find any
int find_words(char *line, int starting_idx) {

    int length = strlen(line);
    int i = starting_idx;

    if (one(line, length, i)) {
        return 1;
    }
    else if (line[i] == 't') {
        if (two(line, length, i)) {
            return 2;
        }
        else if (three(line, length, i)) {
            return 3;
        }
    }
    else if (line[i] == 'f') {
        if (four(line, length, i)) {
            return 4;
        }
        else if (five(line, length, i)) {
            return 5;
        }
    }
    else if (line[i] == 's') {
        if (six(line, length, i)) {
            return 6;
        }
        else if (seven(line, length, i)) {
            return 7;
        }
    }  
    else if (eight(line, length, i)) {
        return 8;
    }
    else if (nine(line, length, i)) {
        return 9;
    }

    return -1; //no word found
}

int find_nums(char *line) {
    int first_num, last_num;
    int first_num_found = 0;
    int fn_idx = -1, ln_idx = -1; //indices of first/last nums

    int first_word, last_word;
    int first_word_found = 0;
    int fw_idx = -1, lw_idx = -1; //indices of the first/last word
    int temp; //used to absorb error value of find_words()

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] - '0' >= 0 && line[i] - '0' <= 9) {
            if (!first_num_found) {
                first_num_found = 1;
                first_num = line[i] - '0';
                fn_idx = i;
                last_num = line[i] - '0';
                ln_idx = i;
            }
            else {
                last_num = line[i] - '0';
                ln_idx = i;
            }
        }
        else if (isalpha(line[i])) {
            if (!first_word_found) {
                if ((temp = find_words(line, i)) != -1) {
                    first_word_found = 1;
                    first_word = temp;
                    fw_idx = i;
                    last_word = first_word;
                    lw_idx = i;
                }
            }
            else {
                if ((temp = find_words(line, i)) != -1) { //because if it didnt find a word lsat_word would get -1 from find_words()
                    last_word = temp;
                    lw_idx = i;
                }
            }
        }
    }
    int first, last;

    //find which one to keep as first
    if (fn_idx == -1 || fn_idx >= fw_idx)
        first = first_word;
    else if (fw_idx == -1 || fn_idx < fw_idx) 
        first = first_num;
    
    //find which one to keep as last
    if (ln_idx == -1 || ln_idx <= lw_idx)
        last = last_word;
    else if (lw_idx == -1 || ln_idx > lw_idx) 
        last = last_num;


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