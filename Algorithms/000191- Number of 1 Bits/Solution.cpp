#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(log n)
// Space complexity: O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while(n!=0)
        {
            result += n%2;
            n/=2;
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