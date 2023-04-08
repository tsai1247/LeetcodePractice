#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(n)  (can be optimized to O(3))
class Solution {
public:
    int rob(vector<int>& nums) {
        // a[i] means the best amount when rob between [0, i]
        if(nums.size() == 1)    return nums[0];
        
        int* a = new int[nums.size()];
        
        // init
        a[0] = nums[0];
        a[1] = max(nums[0], nums[1]);
        
        for(int i=2; i<nums.size(); i++)
        {
            a[i] = max(a[i-1], a[i-2] + nums[i]);
            
        }
        
        // the result is a[n-1]
        int result = a[nums.size()-1];
        delete[] a;
        return result;
        
    }

    void test() {
        assert(rob( *(new vector<int>( {0} )) ) == 0 );
        assert(rob( *(new vector<int>( {1} )) ) == 1 );
        assert(rob( *(new vector<int>( {1, 2, 3, 1} )) ) == 4 );
        assert(rob( *(new vector<int>( {2, 7, 9, 3, 1} )) ) == 12 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}