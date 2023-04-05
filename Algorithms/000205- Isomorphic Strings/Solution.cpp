#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(s.length + t.length)
// Space complexity: O(1)
class Solution {
public:
    bool isMapping(string s, string t)
    {
        map<char, char> isreplaced;
        for(int i=0; i<s.size(); i++)
        {
            if(isreplaced.find(s[i]) == isreplaced.end()) // key is not found
            {
                isreplaced[s[i]] = t[i];
            }
            else
            {
                if(isreplaced[s[i]] != t[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isIsomorphic(string s, string t) {
        return isMapping(s, t) && isMapping(t, s);
    }

    void test() {
        assert(isIsomorphic( "egg", "add" ) == true );
        assert(isIsomorphic( "foo", "bar" ) == false );
        assert(isIsomorphic( "paper", "title" ) == true );
        assert(isIsomorphic( "aaa", "abc" ) == false );
        assert(isIsomorphic( "abc", "aaa" ) == false );
        assert(isIsomorphic( "a", "a" ) == true );
        assert(isIsomorphic( "a", "b" ) == true );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}