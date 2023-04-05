#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    void reverse(string& s, int begin, int end)
    {
        char tmp;
        for(int i=begin; i<(begin+end)/2; i++)
        {
            tmp = s[i];
            s[i] = s[begin + end-i-1];
            s[begin + end-i-1] = tmp;
        }
    }
    
    string reverseWords(string s) {
        int begin=0, end=0;
        for(; end<s.size(); end++)
        {
            if(s[end]==' ')
            {
                reverse(s, begin, end);
                begin = end + 1;
            }
        }
        reverse(s, begin, end);
        return s;
    }

    void test() {
        assert(reverseWords("Let's take LeetCode contest") == "s'teL ekat edoCteeL tsetnoc" );
        assert(reverseWords("God Ding") == "doG gniD" );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}