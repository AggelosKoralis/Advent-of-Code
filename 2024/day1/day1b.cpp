#include <bits/stdc++.h>
#include <cmath>

using namespace std;


int main(void) {
    vector<int> a;
    vector<int> b;

    int i = 0;
    int x, y;
    while (scanf("%d %d", &x, &y) != EOF) {
            a.push_back(x);
            b.push_back(y);
            i++;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    map<int, int> mapA, mapB;

    for (i = 0; i < a.size(); i++) {
        mapA[a[i]] = 0;
        
        mapB[b[i]] = 0;
    }
   

    for (i = 0; i < a.size(); i++) {
        mapA[a[i]]++;
        mapB[b[i]]++;
    }
    

    int similarity = 0;
    int sum = 0;
    for (i = 0; i < a.size(); i++) {
        sum += abs(a[i] - b[i]);
        similarity += mapB[a[i]] * a[i];
    }
    
    cout << "distance: " << sum << endl;
    cout << "similarity: " << similarity << endl;

    return 0;
}
