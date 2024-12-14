#include <iostream>
#include <vector>
#include <cmath>
#include <list>
using namespace std;

typedef unsigned long long int ull;

int digits(long n) {
    int d = 1;
    while (n /= 10) 
        d++;

    return d;
}


void fillvec(vector<ull>& v) {
    v[0] = 1; // 1 stone with 0
    v[1] = 1; // 1 stone with 1
    v[2] = 1;
    v[3] = 2;

    vector<ull> stones;
    stones.push_back(0);
    
    for (int  i = 1; i < 25; i++) {
        int digs = 0, skip = 0;
        
        for (int j = 0; j < stones.size(); j++) {

            if (skip) {
                skip = 0;
                continue;
            }

            ull bang = 0;
            long right = 0, left = 0;

            if (stones[j] == 0) 
                stones [j] = 1;
            else if ((digs = digits(stones[j])) % 2 == 0) {
                // split num
                bang = pow(10, digs / 2);
                
                left = stones[j] / bang;
                right = stones[j] - (left * bang); // avoid mod ops

                // insert into the list
                stones[j] = left;
                stones.insert(stones.begin() + j + 1, right);
                
                skip = 1;
            }
            else 
                stones[j] *= 2024;

        }
        
        v[i] = stones.size();
    }
}


int main() {
    list<ull> stones;
    ull x;

    while (cin >> x) 
        stones.push_back(x);
    
    vector<ull> cache(75, -1);
    fillvec(cache);

    for (int i = 0; i < 25; i++) 
        cout << cache[i] << " ";
    cout << endl;

    ull total = stones.size();

    for (int j = 0; j < 75; j++) {

        int skip = 0;
        
        list<ull>::iterator it;
        for (it = stones.begin(); it != stones.end(); it++) {

            // skip one iter after splitting to
            // leave the right half alone
            if (skip) {
                skip = 0;
                continue;
            }
            
            int digs = 0;
            long right = 0, left = 0;
            ull bang = 0;

            if (*it == 0) {
                if (cache[j] != -1) { 
                    total += cache[75 - j];
                    break;
                }
                *it = 1;
                
            }
            else if ((digs = digits(*it)) % 2 == 0) {
                // split num
                bang = pow(10, digs / 2);
                
                left = *it / bang;
                right = *it - (left * bang); // avoid mod ops

                // insert into the list
                *it = left;
                stones.insert(next(it), right);
                
                skip = 1;
                total += 2;
            }
            else 
                *it *= 2024;
        }
    }

    cout << stones.size() << endl;
    return 0;
}
