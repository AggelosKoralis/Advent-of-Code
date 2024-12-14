#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

typedef unsigned long long int ull;

ull run(ull target, vector<ull> nums) {

    if (nums.size() == 1)
        return (nums[0] == target) ? target : 0;

    ull n2 = nums[1];
    nums.erase(nums.begin() + 1); //erase 2nd num 
    
    ull add = nums[0] + n2;
    ull mul = nums[0] * n2;
    
    nums[0] = add;
    if (run(target, nums) == target) return target;

    nums[0] = mul;
    if (run(target, nums) == target) return target;
    
    return 0;
}


int main() {
    ull res = 0;
    ull target = 0;

    string rest;

    while (scanf("%llu: ", &target) != EOF) {
        getline(cin, rest);

        istringstream line(rest);
        vector<ull> nums;
        ull x;

        while (line >> x) 
            nums.push_back(x);
    
        res += run(target, nums);
    }

    cout << "callibration result: " << res << endl;
    return 0;
}
