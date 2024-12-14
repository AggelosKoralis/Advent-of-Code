#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdint>
#include <cmath>

using namespace std;

typedef unsigned long long int ull;
typedef uint64_t u64;

int digits(ull n) {
    int d = 1;
    while (n /= 10) d++;
    return d;
}

ull cnc(ull n1, ull n2) {
    u64 shift = pow(10, digits(n2));
    n1 = n1 * shift;
    n1 += n2;
    
    return n1;
}

ull run(ull target, vector<u64> nums) {

    if (nums.size() == 1)
        return (nums[0] == target) ? target : 0;

    ull n2 = nums[1];
    nums.erase(nums.begin() + 1); //erase 2nd num 
    
    ull add = nums[0] + n2;
    ull mul = nums[0] * n2;
    ull conc = cnc(nums[0], n2);

    nums[0] = add;
    if (run(target, nums) == target) return target;

    nums[0] = mul;
    if (run(target, nums) == target) return target;
    
    nums[0] = conc;
    if (run(target, nums) == target) return target;

    return 0;
}


int main() {
    u64 res = 0;
    u64 target = 0;

    string rest;

    while (scanf("%llu: ", &target) != EOF) {
        getline(cin, rest);

        istringstream line(rest);
        vector<u64> nums;
        u64 x;

        while (line >> x) 
            nums.push_back(x);
    
        res += run(target, nums);
    }

    cout << "callibration result: " << res << endl;
    return 0;
}
