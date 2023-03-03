#include<bits/stdc++.h>
using namespace std;

/*
# Problem 217. tag: Easy
## Question:
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
	Input: nums = [1,2,3,1]
	Output: true

Example 2:
	Input: nums = [1,2,3,4]
	Output: false

Example 3:
	Input: nums = [1,1,1,3,3,4,3,2,4,2]
	Output: true

Constraints:
	1 <= nums.length <= 105
	-109 <= nums[i] <= 109

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		map<int, bool> mp;
        for(auto& num : nums)
        {
            if(mp[num])
                return true;
            else
                mp[num] = true;
        }
        return false;
	}

    void test() {
        assert(containsDuplicate(*(new vector<int>({1, 2, 3, 4}))) == false );
        assert(containsDuplicate(*(new vector<int>({1, 2, 3, 2}))) == true );
        assert(containsDuplicate(*(new vector<int>({1, 1, 1, 2, 3}))) == true );
        assert(containsDuplicate(*(new vector<int>({1}))) == false );
        cout<<"test succeeded.\n";

    }
};

int main()
{
    Solution().test();
}