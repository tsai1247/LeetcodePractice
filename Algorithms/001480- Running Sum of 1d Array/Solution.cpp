#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(1) (answer will saved in the old vector)
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // vector<int> result(1, nums[0]);
        for(int i=1; i<nums.size(); i++)
        {
            nums[i] += nums[i-1];
            // result.push_back(result[i-1] + nums[i]);
        }
        return nums;
    }

    void test() {
        assert(
            runningSum( *(new vector<int>( {1, 2, 3, 4} )) ) 
            == *(new vector<int>( {1, 3, 6, 10} ))  
        );
        assert(
            runningSum( *(new vector<int>( {1} )) )
            == *(new vector<int>( {1} ) )  
        ) ;
        assert(
            runningSum( *(new vector<int>( {4, 3, 2} )) )
            == *(new vector<int>( {4, 7, 9} ) )  
        );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}