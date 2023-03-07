#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int minimum = 0, maximum = nums[0], sum = 0;
        for(auto& num : nums)
        {
            sum += num;
            if(maximum < sum - minimum)
                maximum = sum - minimum;
            if(minimum > sum)
                minimum = sum;
        }
        return maximum;
    }

    void test() {
        assert( maxSubArray(*(new vector<int>({-2,1,-3,4,-1,2,1,-5,4}))) == 6);
        assert( maxSubArray(*(new vector<int>({1}))) == 1);
        assert( maxSubArray(*(new vector<int>({5,4,-1,7,8}))) == 23);
        assert( maxSubArray(*(new vector<int>({-1}))) == -1);
        assert( maxSubArray(*(new vector<int>({-2, -1}))) == -1);
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}