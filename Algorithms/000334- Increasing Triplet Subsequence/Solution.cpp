#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(   )
// Space complexity: O(   )
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for(auto num : nums)
        {
            if (num <= min1)
            {
                min1 = num;
            }
            
            else if (num <= min2)
            {
                min2 = num;
            }
            else
            {
                return true;
            }
        }
        return false;
    }

    void test() {
        assert(increasingTriplet( *(new vector<int>( {1,2,3,4,5} )) ) == true );
        assert(increasingTriplet( *(new vector<int>( {5,4,3,2,1} )) ) == false );
        assert(increasingTriplet( *(new vector<int>( {2,1,5,0,4,6} )) ) == true );
        assert(increasingTriplet( *(new vector<int>( {20,100,10,12,5,13} )) ) == true );
        assert(increasingTriplet( *(new vector<int>( {1,5,0,4,1,3} )) ) == true );
        assert(increasingTriplet( *(new vector<int>( {1,1,1,1,1,1} )) ) == false );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}