#include<bits/stdc++.h>
using namespace std;

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