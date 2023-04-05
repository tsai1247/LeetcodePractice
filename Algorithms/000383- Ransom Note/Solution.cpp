#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> cnt;
        for(auto& c : magazine)
        {
            cnt[c]++;
        }
        for(auto& c : ransomNote)
        {
            if(cnt[c] == 0)
            {
                return false;
            }
            else
            {
                cnt[c]--;
            }
        }
        return true;
    }

    void test() {
        assert(canConstruct( "aa", "bb" ) == false );
        assert(canConstruct( "a", "abc" ) == true );
        assert(canConstruct( "abc", "a" ) == false );
        assert(canConstruct( "abcde", "fedbacg" ) == true );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}