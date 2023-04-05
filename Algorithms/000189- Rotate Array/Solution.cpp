#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
        vector<int> answer;
        k%=nums.size();
        for(int i=nums.size()-k; i<nums.size(); i++)
        {
            answer.push_back(nums[i]);
        }
        for(int i=0; i<nums.size()-k; i++)
        {
            answer.push_back(nums[i]);
        }
        for(int i=0; i<nums.size(); i++)
        {
            nums[i] = answer[i];
        }
    }

    void test() {
		vector<int> v1;

		v1 = *(new vector<int>( {1,2,3,4,5,6,7} ));
		rotate(v1, 3);
        assert(v1 == *(new vector<int>( {5,6,7,1,2,3,4} )) );

		v1 = *(new vector<int>( {1,2,3,4,5,6,7} ));
		rotate(v1, 0);
        assert(v1 == *(new vector<int>( {1,2,3,4,5,6,7} )) );
		
		v1 = *(new vector<int>( {1} ));
		rotate(v1, 100);
        assert(v1 == *(new vector<int>( {1} )) );

        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}