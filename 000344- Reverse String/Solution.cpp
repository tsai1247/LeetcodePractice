#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(   )
// Space complexity: O(   )
class Solution {
public:
    void reverseString(vector<char>& s) {
        char tmp;
        for(int i=0; i<s.size()/2; i++)
        {
            tmp = s[i];
            s[i] = s[s.size()-i-1];
            s[s.size()-i-1] = tmp;
        }
    }

    void test() {
        vector<char> str;
        str = *(new vector<char>( {'a','b','c'} )); reverseString(str);
        assert(str == *(new vector<char>( {'c','b','a'} )) );

        str = *(new vector<char>( {'a','b'} )); reverseString(str);
        assert(str == *(new vector<char>( {'b','a'} )) );
        
        str = *(new vector<char>( {';'} )); reverseString(str);
        assert(str == *(new vector<char>( {';'} )) );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}