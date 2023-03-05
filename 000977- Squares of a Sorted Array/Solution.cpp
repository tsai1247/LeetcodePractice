#include<bits/stdc++.h>
using namespace std;

/*
# Problem 977. tag: Easy
## Question:
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:
	Input: nums = [-4,-1,0,3,10]
	Output: [0,1,9,16,100]
	Explanation: After squaring, the array becomes [16,1,0,9,100].
	After sorting, it becomes [0,1,9,16,100].

Example 2:
	Input: nums = [-7,-3,2,3,11]
	Output: [4,9,9,49,121]

Constraints:
	1 <= nums.length <= 104
	-104 <= nums[i] <= 104
	nums is sorted in non-decreasing order.

Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?

*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++)
        {
            nums[i] = nums[i] * nums[i];
        }
        
        int left = 0, right = nums.size()-1;
        stack<int> answer;
        while(left <= right)
        {
            if(nums[left] > nums[right]) // put left into answer
            {
                answer.push(nums[left++] );
            }
            else
            {
                answer.push(nums[right--]);
            }
        }
        nums.clear();
        while(!answer.empty())
        {
            nums.push_back(answer.top());
            answer.pop();
        }
        return nums;
    }

    void test() {
        assert(sortedSquares( *(new vector<int>( {-4,-1,0,3,10} )) ) == *(new vector<int>( {0,1,9,16,100} )) );
        assert(sortedSquares( *(new vector<int>( {-1} )) ) == *(new vector<int>( {1} )) );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}