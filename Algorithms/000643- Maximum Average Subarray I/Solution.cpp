#include<bits/stdc++.h>
#include "../../Assert.h"
using namespace std;

// Time complexity: O( n )
// Space complexity: O( 1 )
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        auto left = 0;
        auto right = left + k;
        auto sum = 0;
        for(int i=left; i<right; i++)
        {
            sum += nums[i];
        }

        auto result = sum;
        while(right < nums.size())
        {
            sum = sum - nums[left++] + nums[right++];
            result = max(sum, result);
        }

        return result * 1.0 / k;
    }

    void test() {
        assertEqual(findMaxAverage( *(new vector<int>( {1,12,-5,-6,50,3} )), 4 ), 12.75000 );
        assertEqual(findMaxAverage( *(new vector<int>( {5} )), 1 ), 5.00000 );
        assertEqual(findMaxAverage( *(new vector<int>( {0,4,0,3,2} )), 1 ), 4.00000 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}