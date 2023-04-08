#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(n) (can be optimized to O(3))
// Note: 2 cases: NOT robbing the nums[0], and NOT robbing the nums[n-1].
// For the former, make a[0] = 0 and calculate DP as common.
// For the latter, make common initialize, but just calculate DP until a[n-2] and get its value.
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        
        int* a = new int[nums.size()];
        a[0] = 0;
        a[1] = nums[1];
        for(int i=2; i<nums.size(); i++)
        {
            a[i] = max(a[i-1], a[i-2] + nums[i]);
        }
        
        int result_without_a_0 = a[nums.size()-1];
        delete[] a;
        
        a = new int[nums.size()];
        a[0] = nums[0];
        a[1] = max(nums[0], nums[1]);
        for(int i=2; i<nums.size()-1; i++)
        {
            a[i] = max(a[i-1], a[i-2] + nums[i]);
        }
        
        int result_without_a_n = a[nums.size()-2];
        delete[] a;
        
        return max(result_without_a_0, result_without_a_n);
    }

    void test() {
        assert(rob( *(new vector<int>( {2, 3, 2} )) ) == 3 );
        assert(rob( *(new vector<int>( {1, 2, 3, 1} )) ) == 4 );
        assert(rob( *(new vector<int>( {0} )) ) == 0 );
        assert(rob( *(new vector<int>( {1} )) ) == 1 );
        assert(rob( *(new vector<int>( {1, 2} )) ) == 2 );
        assert(rob( *(new vector<int>( {0, 0} )) ) == 0 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}