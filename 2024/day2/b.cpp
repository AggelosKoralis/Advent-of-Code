#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


int main(void) {
    
    vector<int> data; // stores current line

    string line; 
    int number, x, y;
    int dec = 0;
    int safe = 0;
    int flag = 1;
    int unsafe_lvls = 0;

    while (getline(cin, line)) {
        stringstream stream(line); // make line a stream for ez handling

        while (stream >> number)
            data.push_back(number);
        
        // 1: is dec   0: is inc (do i care if they are equal?)
        dec = data[0] > data[1];
        
        flag = 1;
        for (int i = 0; i < data.size() - 1; i++) {
            x = data[i];
            y = data[i + 1];

            if (!(x > y == dec && abs(x - y) >= 1 && abs(x - y) <= 3))  
                unsafe_lvls++;
        }
        cout << unsafe_lvls << '\n';        
        if (unsafe_lvls <= 1) safe++;
        unsafe_lvls = 0; // reset for the next line
        data.clear();
    }
    
    cout << "safe: " << safe << endl;
        
    return 0;
}
