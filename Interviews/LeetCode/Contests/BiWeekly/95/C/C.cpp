#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int ans = 0;
        for (int i : nums) ans ^= i;
        return ans;
    }
};