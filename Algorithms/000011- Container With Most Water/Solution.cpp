#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(   )
// Space complexity: O(   )
class Solution {
public:
    int maxArea(vector<int>& height) {
        int width = height.size() - 1;
        auto left = height.begin();
        auto right = height.rbegin();
        int area = min(*left, *right) * width;
        while(width > 0)
        {
            if(*left < *right)
            {
                left++;
            }
            else 
            {
                right++;
            }
            area = max(area, min(*left, *right) * --width);
        }

        return area;
    }

    void test() {
        assert(maxArea( *(new vector<int>( {1,8,6,2,5,4,8,3,7} )) ) == 49 );
        assert(maxArea( *(new vector<int>( {1,1} )) ) == 1 );
        assert(maxArea( *(new vector<int>( {7,1,1,1,1,1,1,6,8} )) ) == 56 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}