//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] += i;
            if (mp[target - nums[i]] != 0) {
                return {i , mp[nums[i]]};
            }
        }
        return {};
    }
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    Solution{};
    return 0;
}