#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned long long int ull;

long digits(long n) {
    long d = 1;
    while (n /= 10) 
        d++;
    
    return d;
}

// get right half of a number
ull get_right(ull n, long digits) {
    ull boom = pow(10, digits >> 1);
    
    return n % boom;
}

int main() {
    vector<ull> stones;
    ull x;

    while (cin >> x) 
        stones.push_back(x);

    for (int j = 0; j < 25; j++) {

        int skip = 0;

        for (int i = 0; i < stones.size(); i++) {
            
            // skip one iter after splitting to
            // leave the right half alone
            if (skip) {
                skip = 0;
                continue;
            }
            
            long digs = 0;
            ull right = 0, left = 0;
            ull bang = 0;

            if (stones[i] == 0)
                stones[i] = 1;
            else if ((digs = digits(stones[i])) % 2 == 0) {
                // split num
                bang = pow(10, digs / 2);
                
                right = stones[i] % bang;
                left = stones[i] / bang;

                // insert into the vector
                stones[i] = left; 
                stones.insert(stones.begin() + i + 1, right);
                
                skip = 1;
            }
            else 
                stones[i] *= 2024;
        }
    }

    cout << stones.size() << endl;
    return 0;
}
