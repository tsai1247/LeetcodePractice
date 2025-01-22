#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur = 0;
        for(auto num : nums)
        {
            if(num != 0)
            {
                nums[cur++] = num;
            }
        }

        for(int i=cur; i<nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                nums[i] = 0;
            }
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