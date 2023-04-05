#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(   )
// Space complexity: O(   )
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int maximum = 0;
        long long sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            
            int cur = (sum + i) / (i+1);
            if(maximum < cur)
                maximum = cur;
        }
        return maximum;
    }

    void test() {
        assert(minimizeArrayValue( *(new vector<int>( {3,7,1,6} )) ) == 5 );
        assert(minimizeArrayValue( *(new vector<int>( {10, 1} )) ) == 10 );
        assert(minimizeArrayValue( *(new vector<int>( {1, 1, 1, 1, 1, 1, 1, 1, 1, 1} )) ) == 1 );
        assert(minimizeArrayValue( *(new vector<int>( {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} )) ) == 0 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}