#include<bits/stdc++.h>
using namespace std;

/*
# Problem 704. tag: Easy
## Question:
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.You must write an algorithm with O(log n) runtime complexity.

Example 1:
	Input: nums = [-1,0,3,5,9,12], target = 9
	Output: 4
	Explanation: 9 exists in nums and its index is 4

Example 2:
	Input: nums = [-1,0,3,5,9,12], target = 2
	Output: -1
	Explanation: 2 does not exist in nums so return -1

Constraints:
	1 <= nums.length <= 104
	-104 < nums[i], target < 104
	All the integers in nums are unique.
	nums is sorted in ascending order.

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    void test() {
        assert(search(*(new vector<int>({1, 2, 3, 4, 5})), 1) ==  0 );
        assert(search(*(new vector<int>({1, 2, 3, 4, 5})), 3) ==  2 );
        assert(search(*(new vector<int>({1, 2, 3, 4, 5})), 5) ==  4 );
        assert(search(*(new vector<int>({1, 2, 3, 4, 5})), 0) == -1 );
        assert(search(*(new vector<int>({1, 2, 3, 4, 5})), 6) == -1 );
        assert(search(*(new vector<int>({1, 2})), 1) ==  0 );
        assert(search(*(new vector<int>({1, 2})), 2) ==  1 );
        assert(search(*(new vector<int>({1, 2})), 0) == -1 );
        assert(search(*(new vector<int>({1, 2})), 3) == -1 );
        assert(search(*(new vector<int>({1})), 1) ==  0 );
        assert(search(*(new vector<int>({1})), 0) == -1 );
        assert(search(*(new vector<int>({1})), 2) == -1 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}