#include<bits/stdc++.h>
using namespace std;

// Time complexity: O( n )
// Space complexity: O( 1 )
class Solution {
public:
    const string vowels = "aeiou";
    bool isVowel(char c)
    {
        // for c++23, use contains() instread;
        return vowels.find(c) != -1;
    }

    int maxVowels(string s, int k) {
        int left = 0, right = k;
        int cnt = 0;
        for(int i = 0; i<right; i++)
        {
            cnt += isVowel(s[i]) ? 1 : 0;
        }

        int maxCount = cnt;
        while(right < s.length())
        {
            cnt -= isVowel(s[left++]) ? 1 : 0;
            cnt += isVowel(s[right++]) ? 1 : 0;
            maxCount = max(maxCount, cnt);
        }

        return maxCount;
    }

    void test() {
        assert(maxVowels( "abciiidef", 3 ) == 3 );
        assert(maxVowels( "aeiou", 2 ) == 2 );
        assert(maxVowels( "leetcode", 3 ) == 2 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}