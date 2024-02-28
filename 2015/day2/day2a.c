#include <stdio.h>

struct box {
    int l;
    int w;
    int h;
};

int solve(struct box current) {
    int side1 = current.l * current.w;
    int side2 = current.w * current.h;
    int side3 = current.h * current.l;

    printf("s1: %d   s2: %d   s3: %d\n", current.l, current.w, current.h);
    
    int min = side1;
    if (min > side2) {
        min = side2;
    }
    if (min > side3) {
        min = side3;
    }
    
    return 2 * side1 + 2 * side2 + 2 * side3 + min;
}

int main(void) {

    int c, tracker = 0; //tracks how many of the 3 dimension of a box we have read
    int num = 0;
    struct box current;
    int total_sq_feet = 0;

    while ((c = getchar()) != EOF) {
        if (c != 'x') {
            num = num * 10 + (c - '0');
        }
        else {
            if (tracker == 0) 
                current.l = num;
            else if (tracker == 1) 
                current.w = num;
            else if (tracker == 2)
                current.h = num;
            tracker++;
            num = 0; //reset number
        }

        if (tracker == 2) { //a box is complete
            tracker = 0;
            total_sq_feet += solve(current);
        }
    }

    printf("%d\n", total_sq_feet);
    return 0;
}