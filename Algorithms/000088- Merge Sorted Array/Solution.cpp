#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(m+n)
// Space complexity: O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = nums1.size() - 1;
        while(n > 0)
        {
            if(m == 0 || nums1[m-1] < nums2[n-1])
            {
                nums1[index] = nums2[n-1];
                n--;
            }
            else
            {
                nums1[index] = nums1[m-1];
                m--;
            }
            index--;
        }
    }


    void test() {
		vector<int> v1;

		v1 = {1,2,3,0,0,0};
		merge( v1, 3, *(new vector<int>( {2, 5, 6} )), 3 );
        assert( v1 ==  *(new vector<int>( {1,2,2,3,5,6} )));
        
		v1 = {1};
		merge( v1, 1, *(new vector<int>( {} )), 0 );
        assert( v1 ==  *(new vector<int>( {1} )));
		
		v1 = {0};
		merge( v1, 0, *(new vector<int>( {1} )), 1 );
        assert( v1 ==  *(new vector<int>( {1} )));
		
		cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}