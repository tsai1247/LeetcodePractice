#include<bits/stdc++.h>
using namespace std;

/*
# Problem 205. tag: Easy
## Question:
Given two strings s and t, determine if they are isomorphic.Two strings s and t are isomorphic if the characters in s can be replaced to get t.All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example 1:
	Input: s = "egg", t = "add"
	Output: true

Example 2:
	Input: s = "foo", t = "bar"
	Output: false

Example 3:
	Input: s = "paper", t = "title"
	Output: true

Constraints:
	1 <= s.length <= 5 * 104
	t.length == s.length
	s and t consist of any valid ascii character.

*/

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