#include <stdio.h>

//input using redirection

int main(void) {
    int c, floor = 0;
    while ((c = getchar()) != EOF) {
        if (c == '(') {
            floor++;
        }
        else if (c == ')') {
            floor--;
        }
    }

    printf("%d\n", floor);
    return 0;
}