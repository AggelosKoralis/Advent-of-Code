#include <iostream>

using namespace std;



int main(void) {

    int x, y;

    int check = 0;
    int mul = 0;
    while ((check = scanf("%*cmul(%d,%d)%*c", &x, &y)) != EOF)  
        if (check == 2)
            mul += x * y;

    cout << "total: " << mul << endl;
    return 0;
}
