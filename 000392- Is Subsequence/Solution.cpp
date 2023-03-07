#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size())
            return false;
        for(int i=0, j=0; i < s.size(); i++, j++)
        {
            while(j<t.size() && s[i] != t[j])
            {
                j++;
            }
            
            if(j == t.size())
                return false;
        }
        return true;
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