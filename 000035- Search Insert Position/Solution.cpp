#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }

    void test() {
        assert(searchInsert( *(new vector<int>( {1,3,5,6} )), 5 ) == 2 );
        assert(searchInsert( *(new vector<int>( {1,3,5,6} )), 2 ) == 1 );
        assert(searchInsert( *(new vector<int>( {1,3,5,6} )), 7 ) == 4 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}