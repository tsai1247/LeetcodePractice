#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(log n)
// Space complexity: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    void test() {
        assert(search(*(new vector<int>({1, 2, 3, 4, 5})), 1) ==  0 );
        assert(search(*(new vector<int>({1, 2, 3, 4, 5})), 3) ==  2 );
        assert(search(*(new vector<int>({1, 2, 3, 4, 5})), 5) ==  4 );
        assert(search(*(new vector<int>({1, 2, 3, 4, 5})), 0) == -1 );
        assert(search(*(new vector<int>({1, 2, 3, 4, 5})), 6) == -1 );
        assert(search(*(new vector<int>({1, 2})), 1) ==  0 );
        assert(search(*(new vector<int>({1, 2})), 2) ==  1 );
        assert(search(*(new vector<int>({1, 2})), 0) == -1 );
        assert(search(*(new vector<int>({1, 2})), 3) == -1 );
        assert(search(*(new vector<int>({1})), 1) ==  0 );
        assert(search(*(new vector<int>({1})), 0) == -1 );
        assert(search(*(new vector<int>({1})), 2) == -1 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}