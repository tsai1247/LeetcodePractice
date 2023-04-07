#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(log n)
// Space complexity: O(1)
// The complexity is same as Solution.cpp, but the worst time complexity is optimized: 
// For Solution.cpp, it takes 'the index of highest 1-bit' times, but here, just takes 'result' times.
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while(n!=0)
        {
            n &= (n-1);
            result++;
        }
        return result;
    }

    void test() {
        assert(hammingWeight( 11 ) == 3 );
        assert(hammingWeight( 128 ) == 1 );
        assert(hammingWeight( 2147483647 ) == 31 );
        assert(hammingWeight( -3 ) == 31 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}