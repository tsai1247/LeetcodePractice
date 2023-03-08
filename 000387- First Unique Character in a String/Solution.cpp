#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(1) (26 kinds of characters)
class Solution {
public:
public:
    int firstUniqChar(string s) {
        map<char, int> mp_count;
        map<char, int> mp_index;

        for(int i=0; i<s.size(); i++)
        {
            mp_count[s[i]]++;
            if(mp_index[s[i]] == 0)
            {
                mp_index[s[i]] = i + 1;
            }
        }
        int ret = INT_MAX;
        for(auto& c_pair : mp_count)
        {
            if(c_pair.second == 1 && ret > mp_index[c_pair.first])
            {
                ret = mp_index[c_pair.first];
            }
        }
        
        if(ret == INT_MAX)
            return -1;
        else
            return ret-1;
    }

    void test() {
        assert(firstUniqChar("leetcode") == 0 );
        assert(firstUniqChar("loveleetcode") == 2 );
        assert(firstUniqChar("aabb") == -1 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}