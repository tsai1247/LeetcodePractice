#include<bits/stdc++.h>
using namespace std;

/*
# Problem 53. tag: Medium
## Question:
Given an integer array nums, find thesubarraywith the largest sum, and return its sum.

Example 1:
	Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
	Output: 6
	Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
	Input: nums = [1]
	Output: 1
	Explanation: The subarray [1] has the largest sum 1.

Example 3:
	Input: nums = [5,4,-1,7,8]
	Output: 23
	Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

Constraints:
	1 <= nums.length <= 105
	-104 <= nums[i] <= 104

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

*/

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