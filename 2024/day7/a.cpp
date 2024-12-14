#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int run(int target, vector<int> nums) {

    if (nums.size() == 1)
        return (nums[0] == target) ? target : 0;

    int n2 = nums[1];
    nums.erase(nums.begin() + 1); //erase 2nd num 
    
    int add = nums[0] + n2;
    int mul = nums[0] * n2;
    
    nums[0] = add;
    if (run(target, nums) == target) return target;

    nums[0] = mul;
    if (run(target, nums) == target) return target;
    
    return 0;
}


int main() {
    long res = 0;
    int target = 0;

    string rest;

    while (scanf("%d: ", &target) != EOF) {
        getline(cin, rest);

        istringstream line(rest);
        vector<int> nums;
        int x;

        while (line >> x) 
            nums.push_back(x);
    
        res += run(target, nums);
    }

    cout << "callibration result: " << res << endl;

    return 0;
}
