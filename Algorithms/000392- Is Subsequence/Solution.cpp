#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(t.length)
// Space complexity: O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto iter = s.begin();
        for(auto c : t)
        {
            if(c == *iter)
            {
                iter++;
            }
            if (iter == s.end())
            {
                return true;
            }   
        }
        return iter == s.end();
    }

    void test() {
        assert(isSubsequence( "", "" ) == true );
        assert(isSubsequence( "abc", "" ) == false );
        assert(isSubsequence( "", "abc" ) == true );
        assert(isSubsequence( "abc", "abc" ) == true );
        assert(isSubsequence( "abc", "ahbgdc" ) == true );
        assert(isSubsequence( "axc", "ahbgdc" ) == false );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}