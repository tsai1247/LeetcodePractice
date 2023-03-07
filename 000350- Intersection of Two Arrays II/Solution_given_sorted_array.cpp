#include<bits/stdc++.h>
using namespace std;

// Time complexity: min( O(nums1.length), O(nums2.length) )
// Space complexity: min( O(nums1.length), O(nums2.length) )
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // condition from follow-up
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ret;
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i] < nums2[j])
            {
                i++;
            }
            else if(nums1[i] > nums2[j])
            {
                j++;
            }
            else    // equal, add to ret
            {
                ret.push_back(nums1[i]);
                i++; j++;
            }
        }
        
        return ret;
    }

    void test() {
        vector<int> result;

        result = intersect( *(new vector<int>( {1, 2, 2, 1} )), *(new vector<int>( {2, 2} )) ); sort(result.begin(), result.end());
        assert(result == *(new vector<int>({2, 2})) );

        result = intersect( *(new vector<int>( {4,9,5} )), *(new vector<int>( {9,4,9,8,4} )) ); sort(result.begin(), result.end());
        assert(result == *(new vector<int>({4, 9})) );
        
        result = intersect( *(new vector<int>( {1, 2} )), *(new vector<int>( {4, 3} )) ); sort(result.begin(), result.end());
        assert(result == *(new vector<int>({})) );

        result = intersect( *(new vector<int>( {1, 2} )), *(new vector<int>( {2, 1} )) ); sort(result.begin(), result.end());
        assert(result == *(new vector<int>({1, 2})) );
        
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}