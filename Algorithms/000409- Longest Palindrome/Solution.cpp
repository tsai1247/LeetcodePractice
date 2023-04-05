#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(   )
// Space complexity: O(   )
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> cnt;
        for(auto& c : s)
        {
            cnt[c]++;
        }
        
        int ret = 0, hasodd = 0;
        for(auto&pr : cnt)
        {
            ret += pr.second/2;
            if(pr.second%2 == 1)
            {
                hasodd = 1;
            }
        }
        
        return ret*2 + hasodd;
    }

    void test() {
        assert(longestPalindrome("aabbccdd") == 8 );
        assert(longestPalindrome("aabbccd") == 7 );
        assert(longestPalindrome("AaBbCcDd") == 1 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}