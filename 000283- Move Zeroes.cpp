#include<bits/stdc++.h>
using namespace std;

/*
# Problem 283. tag: Easy
## Question:
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.Note that you must do this in-place without making a copy of the array.

Example 1:
	Input: nums = [0,1,0,3,12]
	Output: [1,3,12,0,0]

Example 2:
	Input: nums = [0]
	Output: [0]

Constraints:
	1 <= nums.length <= 104
	-231 <= nums[i] <= 231 - 1

Follow up: Could you minimize the total number of operations done?

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int bias = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                bias++;
            }
            else
            {
                nums[i-bias] = nums[i];
            }
        }
        for(int i=nums.size()-bias; i<nums.size(); i++)
        {
            nums[i] = 0;
        }
    }

    void test() {
        vector<int> v1;

        v1 = *(new vector<int>( {0,1,0,3,12} ));
        moveZeroes(v1);
        assert(v1 == *(new vector<int>( {1,3,12,0,0} )) );

        v1 = *(new vector<int>( {0} ));
        moveZeroes(v1);
        assert(v1 == *(new vector<int>( {0} )) );
        
        v1 = *(new vector<int>( {1} ));
        moveZeroes(v1);
        assert(v1 == *(new vector<int>( {1} )) );

        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}