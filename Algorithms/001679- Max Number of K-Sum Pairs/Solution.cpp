#include<bits/stdc++.h>
using namespace std;

// Time complexity: O( n )
// Space complexity: O( n )
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> mp;
        for(auto num : nums)
        {
            mp[num]++;
        }

        auto left = mp.begin();
        auto right = mp.rbegin();
        auto result = 0;
        while(*left <= *right && left != mp.end() && right != mp.rend())
        {
            auto sum = (*left).first + (*right).first;
            if (sum < k)
            {
                left++;
            }
            else if (sum > k)
            {
                right++;
            }
            else
            {
                result += (*left).first == (*right).first 
                    ? (*left).second / 2 
                    : min((*left).second, (*right).second);
                left++; right++;
            }
        }

        return result;
    }

    void test() {
        assert(maxOperations( *(new vector<int>( {1,2,3,4} )), 5 ) == 2 );
        assert(maxOperations( *(new vector<int>( {3,1,3,4,3} )), 6 ) == 1 );
        assert(maxOperations( *(new vector<int>( {3,1,5,1,1,1,1,1,2,2,3,2,2} )), 1 ) == 0 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}