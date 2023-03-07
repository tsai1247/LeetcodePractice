#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numberexists;
        for(int i=0; i<nums.size(); i++)
        {
            if(numberexists[target - nums[i]] > 0)
            {
                return *(
                    new vector<int>({
                        numberexists[target - nums[i]] - 1, 
                        i
                    })
                );
            }
            else
            {
                numberexists[nums[i]] = i+1;
            }
        }
        return *(new vector<int>());
    }

    void test() {
        assert(twoSum(*(new vector<int>({2,7,11,15})), 9) == *(new vector<int>({0, 1})) );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}