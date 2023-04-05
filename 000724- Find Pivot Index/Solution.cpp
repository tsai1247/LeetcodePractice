#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(auto& num : nums)
            sum += num;
        
        int cur = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(sum - nums[i] == cur*2)
                return i;
            cur += nums[i];
        }
        return -1;
    }
    void test() {
        assert(pivotIndex( *(new vector<int>( {1,7,3,6,5,6} )) ) == 3 );
        assert(pivotIndex( *(new vector<int>( {1,2,3} )) ) == -1 );
        assert(pivotIndex( *(new vector<int>( {2, 1, -1} )) ) == 0 );
        assert(pivotIndex( *(new vector<int>( {1} )) ) == 0 );
        assert(pivotIndex( *(new vector<int>( {0} )) ) == 0 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}