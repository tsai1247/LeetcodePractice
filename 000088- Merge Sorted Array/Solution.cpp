#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, cur = m+n-1;
        while(i>=0 || j>=0)
        {
            if(i < 0) // put nums2[j] into answer
            {
                nums1[cur--] = nums2[j--];
            }
            else if(j < 0) // put nums1[i] into answer
            {
                nums1[cur--] = nums1[i--];
            }
            else
            {
                if(nums1[i] > nums2[j])
                {
                    nums1[cur--] = nums1[i--];
                }
                else
                {
                    nums1[cur--] = nums2[j--];
                }
            }
        }
    }


    void test() {
		vector<int> v1;

		v1 = *(new vector<int>( {1,2,3,0,0,0} ));
		merge( v1, 3, *(new vector<int>( {2, 5, 6} )), 3 );
        assert( v1 ==  *(new vector<int>( {1,2,2,3,5,6} )));
        
		v1 = *(new vector<int>( {1} ));
		merge( v1, 1, *(new vector<int>( {} )), 0 );
        assert( v1 ==  *(new vector<int>( {1} )));
		
		v1 = *(new vector<int>( {0} ));
		merge( v1, 0, *(new vector<int>( {1} )), 1 );
        assert( v1 ==  *(new vector<int>( {1} )));
		
		cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}