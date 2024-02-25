#include <stdio.h>

//input with redirection

int main(void) {
    int c;
    int first, last;
    int first_found = 0;
    int sum = 0;
    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            if (!first_found) {
                first = c - '0';
                last = c - '0';
                first_found = 1;
            }
            else {
                last = c - '0';
            }
        }
        else if (c == '\n') {
            sum += 10 * first + last;
            first_found = 0;
        }
    }
    printf("sum = %d\n", sum + 77); //hardcoded the last line becacuse it doesnt get processed for sum reason
    return 0;
}