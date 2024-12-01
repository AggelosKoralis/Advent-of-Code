#include <bits/stdc++.h>
#include <cmath>

using namespace std;


int main(void) {
    vector<int> a, b;

    int i = 0;
    int x, y;
    while (scanf("%d %d", &x, &y) != EOF) {
            a.push_back(x);
            b.push_back(y);
            i++;
    }

    //sort(a.begin(), a.end());
    //sort(b.begin(), b.end());
    
    // number : occurences
    map<int, int> mapA, mapB;
    
    for (i = 0; i < b.size(); i++)
        mapB[b[i]] = 0;
   

    for (i = 0; i < b.size(); i++)
        mapB[b[i]]++;

    int similarity = 0;    

    for (i = 0; i < a.size(); i++) {
        similarity += mapB[a[i]] * a[i];
    }

    cout << "similarity: " << similarity << endl;

    return 0;
}
