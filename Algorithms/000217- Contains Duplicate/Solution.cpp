#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		map<int, bool> mp;
        for(auto& num : nums)
        {
            if(mp[num])
                return true;
            else
                mp[num] = true;
        }
        return false;
	}

    void test() {
        assert(containsDuplicate(*(new vector<int>({1, 2, 3, 4}))) == false );
        assert(containsDuplicate(*(new vector<int>({1, 2, 3, 2}))) == true );
        assert(containsDuplicate(*(new vector<int>({1, 1, 1, 2, 3}))) == true );
        assert(containsDuplicate(*(new vector<int>({1}))) == false );
        cout<<"test succeeded.\n";

    }
};

int main()
{
    Solution().test();
}