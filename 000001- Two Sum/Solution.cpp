#include<bits/stdc++.h>
using namespace std;

/*
# Problem 1. tag: Easy
## Question:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.You may assume that each input would have exactly one solution, and you may not use the same element twice.You can return the answer in any order.

Example 1:
	Input: nums = [2,7,11,15], target = 9
	Output: [0,1]
	Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
	Input: nums = [3,2,4], target = 6
	Output: [1,2]

Example 3:
	Input: nums = [3,3], target = 6
	Output: [0,1]

Constraints:
	2 <= nums.length <= 104
	-109 <= nums[i] <= 109
	-109 <= target <= 109
	Only one valid answer exists.

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numberexists;
        for(int i=0; i<nums.size(); i++)
        {
            if(numberexists[target - nums[i]] > 0)
            {
                return *(
                    new vector<int>({
                        numberexists[target - nums[i]] - 1, 
                        i
                    })
                );
            }
            else
            {
                numberexists[nums[i]] = i+1;
            }
        }
        return *(new vector<int>());
    }

    void test() {
        assert(twoSum(*(new vector<int>({2,7,11,15})), 9) == *(new vector<int>({0, 1})) );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}