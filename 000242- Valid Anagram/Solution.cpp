#include<bits/stdc++.h>
using namespace std;

/* Note:
    About the follow up, the constraints said there are only 26 possible characters in string.  Therefore, we may use int[26] array instead of map<char, int> to speed up.
    When the inputs contain Unicode characters, we prefer the approach with map<char, int> to save the space of unused index.
*/
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())    return false;
        map<char, int> count;
        for(auto& c:s)
        {
            count[c]++;
        }
        for(auto& c:t)
        {
            count[c]--;
        }
        
        for(auto& pr:count)
        {
            if(pr.second != 0)
                return false;
        }
        return true;
    }

    void test() {
        assert(isAnagram("anagram", "nagaram") == true );
        assert(isAnagram("rat", "car") == false );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}