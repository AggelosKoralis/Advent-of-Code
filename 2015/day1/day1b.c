#include <stdio.h>

//input using redirection

int main(void) {
    int c, floor = 0, position = 0;
    while ((c = getchar()) != EOF) {
        if (c == '(') {
            floor++;
            position++;
        }
        else if (c == ')') {
            floor--;
            position++;
            if (floor < 0) {
                printf("%d\n", position);
                return 0;
            }
        }
    }

    return 0;
}