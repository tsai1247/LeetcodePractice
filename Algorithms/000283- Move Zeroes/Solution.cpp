#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)
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