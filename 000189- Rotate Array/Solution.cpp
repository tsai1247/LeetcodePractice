#include<bits/stdc++.h>
using namespace std;

/*
# Problem 189. tag: Medium
## Question:
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:
	Input: nums = [1,2,3,4,5,6,7], k = 3
	Output: [5,6,7,1,2,3,4]
	Explanation:
	rotate 1 steps to the right: [7,1,2,3,4,5,6]
	rotate 2 steps to the right: [6,7,1,2,3,4,5]
	rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
	Input: nums = [-1,-100,3,99], k = 2
	Output: [3,99,-1,-100]
	Explanation:
	rotate 1 steps to the right: [99,-1,-100,3]
	rotate 2 steps to the right: [3,99,-1,-100]

Constraints:
	1 <= nums.length <= 105
	-231 <= nums[i] <= 231 - 1
	0 <= k <= 105

Follow up:
	Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
	Could you do it in-place with O(1) extra space?

*/

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
        vector<int> answer;
        k%=nums.size();
        for(int i=nums.size()-k; i<nums.size(); i++)
        {
            answer.push_back(nums[i]);
        }
        for(int i=0; i<nums.size()-k; i++)
        {
            answer.push_back(nums[i]);
        }
        for(int i=0; i<nums.size(); i++)
        {
            nums[i] = answer[i];
        }
    }

    void test() {
		vector<int> v1;

		v1 = *(new vector<int>( {1,2,3,4,5,6,7} ));
		rotate(v1, 3);
        assert(v1 == *(new vector<int>( {5,6,7,1,2,3,4} )) );

		v1 = *(new vector<int>( {1,2,3,4,5,6,7} ));
		rotate(v1, 0);
        assert(v1 == *(new vector<int>( {1,2,3,4,5,6,7} )) );
		
		v1 = *(new vector<int>( {1} ));
		rotate(v1, 100);
        assert(v1 == *(new vector<int>( {1} )) );

        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}