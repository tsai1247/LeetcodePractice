#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(log n)
// Space complexity: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1, sum;
        while(left < right)
        {
            sum = numbers[left] + numbers[right];
            if(sum > target) // should be smaller
            {
                right--;
            }
            else if(sum < target) // should be larger
            {
                left++;
            }
            else
            {
                return *(new vector<int>({left+1, right+1}));
            }
        }
        return *(new vector<int>({}));  // unreachable

    }

    void test() {
        assert(twoSum( *(new vector<int>( {2,7,11,15} )), 9 ) == *(new vector<int>({1, 2})) );
        assert(twoSum( *(new vector<int>( {-1, 0} )), -1 ) == *(new vector<int>({1, 2})) );
        assert(twoSum( *(new vector<int>( {2,3,4} )), 6 ) == *(new vector<int>({1, 3})) );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}