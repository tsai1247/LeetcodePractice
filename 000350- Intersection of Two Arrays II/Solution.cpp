#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Time complexity: min( O(nums1.length), O(nums2.length) )

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> content_map_count;
        for(auto& content : nums1)
        {
            content_map_count[content]++;
        }
        vector<int> ret;
        for(auto& content : nums2)
        {
            if(content_map_count[content] > 0)
            {
                ret.push_back(content);
                content_map_count[content]--;
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