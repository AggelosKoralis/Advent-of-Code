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
    
    int sum = 0;
    for (i = 0; i < a.size(); i++)
        sum += abs(a[i] - b[i]);

    cout << "distance: " << sum << endl;
    return 0;
}
